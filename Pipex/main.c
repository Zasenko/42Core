/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:58:35 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/19 17:45:34 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
    t_prog prog;

    if (env && *env)
    {
        int d = 0;
        while (env[d])
        {
            printf("env: %s\n", env[d]);
            d++;
        }
    }
    if (!init_prog(&prog))
    {
        return (0);
    }
    if (!parse(&prog, ac, av, env))
    {
        free_prog(&prog);
        return (0);
    }


    int i = 0;
    if (prog.commands)
    {
        while (prog.commands[i] != NULL)
        {
            printf("PIPE %d\n", i + 1);

            int j = 0;
            while (prog.commands[i]->args[j] != NULL)
            {
                printf("%d arg: %s\n", j + 1, prog.commands[i]->args[j]);
                j++;
            }
            i++;
        }
    }
    i = 0;
    printf("FOLDERS:\n");
    if (prog.folders)
    {
        while (prog.folders[i])
        {
            printf("%s\n", prog.folders[i]);
            i++;
        }
    }

    char *path_file1 = prog.file1_path;
    char *path_file2 = prog.file2_path;

    int fd_file1 = open(path_file1, O_RDONLY);
    if (fd_file1 < 0)
    {
        printf("ERROR fd_file1\n");
        return 1;
    }
    int fd_file2 = open(path_file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd_file2 < 0)
    {
        printf("ERROR fd_file2\n");
        return 1;
    }


    int fd_pipe1[2];
    if (pipe(fd_pipe1) == -1)
    {
        close(fd_file1);
        close(fd_file2);
        printf("fd_pipe ERROR\n");
        return 0;
    }
    pid_t pid1 = fork();
    if (pid1 == -1)
    {
        close(fd_pipe1[0]);
        close(fd_pipe1[1]);
        close(fd_file1);
        close(fd_file2);
        printf("pid 1 ERROR\n");
        return 0;
    }
    if (pid1 == 0)
    {
        printf("CHILD 1\n");
        if (dup2(fd_file1, 0) == -1 || dup2(fd_pipe1[1], 1) == -1)
        {
            close(fd_file1);
            close(fd_file2);
            close(fd_pipe1[0]);
            close(fd_pipe1[1]);
            printf("dup2 1 ERROR\n");
            return 0;
        }
        close(fd_pipe1[0]);
        close(fd_pipe1[1]);
        close(fd_file2);
        close(fd_file1);
        char *param[] = {"/bin/cat", NULL};
        if (execve("/bin/cat", param, NULL) == -1)
        {
            //todo close dup2?
            printf("execve 1 ERROR\n");
            return 0;
        }
    }
    close(fd_file1);
    int fd_pipe2[2];
    if (pipe(fd_pipe2) == -1)
    {
        close(fd_pipe1[0]);
        close(fd_pipe1[1]);
        close(fd_file2);
        close(fd_file1);
        printf("fd_pipe2 ERROR\n");
        return 0;
    }

    pid_t pid2= fork();
    if (pid2 == -1)
    {
        close(fd_pipe1[0]);
        close(fd_pipe1[1]);
        close(fd_pipe2[0]);
        close(fd_pipe2[1]);
        close(fd_file2);
        printf("pid middle ERROR\n");
        return 0;
    }
    // child 2
    if (pid2 == 0)
    {
        printf("CHILD 2\n");
        if (dup2(fd_pipe1[0], 0) == -1 || dup2(fd_pipe2[1], 1) == -1)
        {
            close(fd_pipe1[0]);
            close(fd_pipe1[1]);
            close(fd_pipe2[0]);
            close(fd_pipe2[1]);
            close(fd_file2);
            printf("dup2 2 ERROR\n");
            return 0;
        }
        close(fd_pipe1[0]);
        close(fd_pipe1[1]);
        close(fd_pipe2[0]);
        close(fd_pipe2[1]);
        close(fd_file2);
        char *param[] = {"/bin/wc", "-w", NULL};
        if (execve("/bin/wc", param, NULL) == -1)
        {
            printf("execve 2 ERROR\n");
            return 0;
        }
    }

    close(fd_pipe1[0]);
    close(fd_pipe1[1]);

    int fd_pipe3[2];
    if (pipe(fd_pipe3) == -1)
    {
        close(fd_pipe2[0]);
        close(fd_pipe2[1]);
        close(fd_file2);
        printf("fd_pipe3 ERROR\n");
        return 0;
    }

    pid_t pid3 = fork();
    if (pid3 == -1)
    {
        close(fd_pipe2[0]);
        close(fd_pipe2[1]);
        close(fd_pipe3[0]);
        close(fd_pipe3[1]);
        close(fd_file2);
        printf("pid 3 ERROR\n");
        return 0;
    }
    // child 3
    if (pid3 == 0)
    {
        if (dup2(fd_pipe2[0], 0) == -1 || dup2(fd_pipe3[1], 1) == -1)
        {
            close(fd_pipe2[0]);
            close(fd_pipe2[1]);
            close(fd_pipe3[0]);
            close(fd_pipe3[1]);
            close(fd_file2);
            printf("dup2 3 ERROR\n");
        }
        close(fd_pipe2[0]);
        close(fd_pipe2[1]);
        close(fd_pipe3[0]);
        close(fd_pipe3[1]);
        close(fd_file2);

        char *arg[] = {"/usr/bin/wc", "-m", NULL};
        execve("/usr/bin/wc", arg, NULL);
    }

    close(fd_pipe2[0]);
    close(fd_pipe2[1]);

    // child 4
    pid_t pid4 = fork();
    if (pid4 == -1)
    {
        close(fd_pipe3[0]);
        close(fd_pipe3[1]);
        close(fd_file2);
        printf("pid 4 ERROR\n");
        return 0;
    }
    if (pid4 == 0)
    {
        printf("CHILD 4\n");
        if (dup2(fd_pipe3[0], 0) == -1 || dup2(fd_file2, 1) == -1)
        {
            close(fd_pipe3[0]);
            close(fd_pipe3[1]);
            close(fd_file2);
            printf("dub2 4 ERROR\n");
        }
        close(fd_pipe3[0]);
        close(fd_pipe3[1]);
        close(fd_file2);
        char *param[] = {"/bin/cat", "-e", NULL};
        if (execve("/bin/cat", param, NULL) == -1)
        {
            printf("execve 4 ERROR\n");
            return 0;
        }
    }
    
    free_prog(&prog);
    return (0);
}
