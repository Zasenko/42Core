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

int cmnd1(t_prog *prog, int fd_pipe[2])
{
    pid_t pid;
    
    pid = fork();
    if (pid == -1)
    {
        free_prog(prog);
        printf("pid 1 ERROR\n");
        return 0;
    }
    if (pid == 0)
    {
        if (dup2(prog->fd_file1, 0) == -1 || dup2(fd_pipe[1], 1) == -1)
        {
            free_prog(prog);
            printf("dup2 1 ERROR\n");
            return 0;
        }
        close_fd(prog);
        printf("COMMANDS\n");
        int i = 0;
        if (prog->commands)
        {
            while (prog->commands[i] != NULL)
            {
                printf("PIPE %d\n", i + 1);
                int j = 0;
                while (prog->commands[i]->args[j] != NULL)
                {
                    printf("%d arg: %s\n", j + 1, prog->commands[i]->args[j]);
                    j++;
                }
                i++;
            }
        }
        printf("COMMANDS END\n");
        char *param[] = {"/usr/bin/cat", NULL};
        if (execve("/usr/bin/cat", param, NULL) == -1)
        {
            free_prog(prog);
            printf("execve 1 ERROR\n");
            return 0;
        }
    }
    return 1;
}

int cmnd2(t_prog *prog, int fd_pipe[2])
{
    pid_t pid;
    
    pid = fork();
    if (pid == -1)
    {
        free_prog(prog);
        printf("pid 2 ERROR\n");
        return 0;
    }
    if (pid == 0)
    {
        if (dup2(fd_pipe[0], 0) == -1 || dup2(prog->fd_file2, 1) == -1)
        {
            free_prog(prog);
            printf("dup2 2 ERROR\n");
            return 0;
        }
        close_fd(prog);
        printf("COMMANDS\n");
        int i = 0;
        if (prog->commands)
        {
            while (prog->commands[i] != NULL)
            {
                printf("PIPE %d\n", i + 1);
                int j = 0;
                while (prog->commands[i]->args[j] != NULL)
                {
                    printf("%d arg: %s\n", j + 1, prog->commands[i]->args[j]);
                    j++;
                }
                i++;
            }
        }
        printf("COMMANDS END\n");
        char *param[] = {"/usr/bin/cat", NULL};
        if (execve("/usr/bin/cat", param, NULL) == -1)
        {
            free_prog(prog);
            printf("execve 2 ERROR\n");
            return 0;
        }
    }
    return 1;
}

int main(int ac, char **av, char **env)
{
    t_prog prog;

    if (!init_prog(&prog))
    {
        printf("main init_prog ERROR\n");
        return (0);
    }
    if (!parse(&prog, ac, av, env))
    {
        printf("main parse ERROR\n");
        free_prog(&prog);
        return (0);
    }

    char *path_file1 = prog.file1_path;
    char *path_file2 = prog.file2_path;
    prog.fd_file1 = open(path_file1, O_RDONLY);
    if (prog.fd_file1 < 0)
    {
        free_prog(&prog);
        printf("ERROR fd_file1\n");
        return 1;
    }
    prog.fd_file2 = open(path_file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (prog.fd_file2 < 0)
    {
        free_prog(&prog);
        printf("ERROR fd_file2\n");
        return 1;
    }
    int fd_pipe[2];
    if (pipe(fd_pipe) == -1)
    {
        free_prog(&prog);
        printf("fd_pipe ERROR\n");
        return 0;
    }
   
    if (!cmnd1(&prog, fd_pipe))
    {
        free_prog(&prog);
        printf("cmnd1 ERROR\n");
        return 0;
    }

    if (!cmnd2(&prog, fd_pipe))
    {
        free_prog(&prog);
        printf("cmnd1 ERROR\n");
        return 0;
    }

    free_prog(&prog);
    return (0);
}