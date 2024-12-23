/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:58:35 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/23 12:33:30 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int cmnd1(t_prog *prog, int fd_pipe[2])
{
    pid_t pid;

    if (!prog)
        return -1;
    pid = fork();
    if (pid == -1)
    {
        perror("Can't create fork");
        free_prog(prog);
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        if (dup2(prog->fd_file1, 0) == -1 || dup2(fd_pipe[1], 1) == -1)
        {
            close_fd(prog);
            perror("Can't redirect  1 fd");
            exit(EXIT_FAILURE);
        }
        close_fd(prog);
        if (execve(prog->commands[0]->args[0], prog->commands[0]->args, NULL) == -1)
        {
            perror("execve 1 failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        close(fd_pipe[1]);
        int status;
        pid_t child_pid = waitpid(pid, &status, 0);
        if (child_pid == -1)
            return (perror("waitpid error"), -1);
        if (WIFEXITED(status))
        {
            if (WEXITSTATUS(status) == EXIT_FAILURE)
            {
                perror("Child process 1 ERROR");
                free_prog(prog);
                exit(EXIT_FAILURE);
            }
            close(prog->fd_file1);
        }
    }
    return (1);//todo exit remove
}

int cmnd2(t_prog *prog, int fd_pipe[2])
{
    pid_t pid;
    
    pid = fork();
    if (pid == -1)
    {
        perror("Can't create fork");
        free_prog(prog);
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        if (dup2(fd_pipe[0], 0) == -1 || dup2(prog->fd_file2, 1) == -1)
        {
            close_fd(prog);
            perror("Can't redirect 2 fd");
            exit(EXIT_FAILURE);
        }
        close_fd(prog);
        if (execve(prog->commands[1]->args[0], prog->commands[1]->args, NULL) == -1)
        {
            perror("execve 2 failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        close(fd_pipe[0]);
        int status;
        pid_t child_pid = waitpid(pid, &status, 0);
        if (child_pid == -1)
            return (perror("waitpid 2 error"), -1);
        if (WIFEXITED(status))
        {
            if (WEXITSTATUS(status) == EXIT_FAILURE)
            {
                perror("Child process 2 ERROR");
                free_prog(prog);
                exit(EXIT_FAILURE);
            }
        }
    }
    return 1;//todo exit remove
}

// valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes --track-origins=yes ./pipex file1 "cat" "wc -l" file2
int main(int ac, char **av, char **env)
{
    t_prog prog;

    if (!init_prog(&prog))
        return (printf("Can't init programm"), 1);
    parse(&prog, ac, av, env);
    if (pipe(prog.fd_pipe) == -1)
    {
        free_prog(&prog);
        perror("Can't create pipe");
        exit(EXIT_FAILURE);
    }
    if (!cmnd1(&prog, prog.fd_pipe))
        return (free_prog(&prog), perror("error command 1"), 1);
    if (!cmnd2(&prog, prog.fd_pipe))
        return (free_prog(&prog), perror("error command 2"), 1);
    free_prog(&prog);
    return (0);
}
