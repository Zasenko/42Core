/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:58:35 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/20 13:33:35 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int add_param(t_prog *prog, char *prog_name)
{
    if (!prog || !prog->folders || !prog_name)
    {
        return 1; // todo
    }
        
    int i = 0;
    while (prog->folders[i])
    {

        //prog->folders[i] + / ??? + prog name

        // strcat?
        if (check_file(prog->folders[i]))
        {
            // сохранить в параметр
            // return 1
        }
        i++;
    }
    //exit error команда/программа не найдена
    exit(1);
}

int add_params()
{
    return 1;
}

int cmnd1(t_prog *prog, int fd_pipe[2])
{
    pid_t pid;

    if (!prog)
        return -1;
    pid = fork();
    if (pid == -1)
        return (perror("Can't create fork"), -1);//todo exit
    if (pid == 0)
    {
        if (dup2(prog->fd_file1, 0) == -1 || dup2(fd_pipe[1], 1) == -1)
        {
            printf("prog->fd_file1: %d, fd_pipe[1]: %d\n", prog->fd_file1, fd_pipe[1]);
            close_fd(prog);
            perror("Can't redirect  1 fd");
            exit(EXIT_FAILURE);
        }
        close_fd(prog);
        char *param[] = {"/bin/cat", NULL};
        if (execve("/bin/cat", param, NULL) == -1)
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
        return (perror("Can't create fork"), -1); //todo exit!
    if (pid == 0)
    {
        if (dup2(fd_pipe[0], 0) == -1 || dup2(prog->fd_file2, 1) == -1)
        {
            close_fd(prog);
            perror("Can't redirect 2 fd");
            exit(EXIT_FAILURE);
        }
        close_fd(prog);
        char *param[] = {"/usr/bin/wc", "-w", NULL};
        if (execve("/usr/bin/wc", param, NULL) == -1)
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

int main(int ac, char **av, char **env)
{
    t_prog prog;

    if (!init_prog(&prog))
        return (printf("Can't init programm") , 1);
    if (!parse(&prog, ac, av, env))
    {
        free_prog(&prog);
        exit(1);
    }
    if (pipe(prog.fd_pipe) == -1)
    {
        free_prog(&prog);
        perror("Can't create pipe");
        exit (1);
    }
    if (!cmnd1(&prog, prog.fd_pipe))
        return (free_prog(&prog), perror("error command 1"), 1);
    if (!cmnd2(&prog, prog.fd_pipe))
        return (free_prog(&prog), perror("error command 2"), 1);
    free_prog(&prog);
    return (0);
}

// printf("COMMANDS\n");
// int i = 0;
// if (prog->commands)
// {
//     while (prog->commands[i] != NULL)
//     {
//         printf("PIPE %d\n", i + 1);
//         int j = 0;
//         while (prog->commands[i]->args[j] != NULL)
//         {
//             printf("%d arg: %s\n", j + 1, prog->commands[i]->args[j]);
//             j++;
//         }
//         i++;
//     }
// }
// printf("COMMANDS END\n");