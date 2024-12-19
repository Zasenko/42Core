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

int main(int ac, char **av,  char **env)
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
    init_prog(&prog);
    if (!parse(&prog, ac, av))
    {
        free_prog(&prog);
        return (0);
    }

    int i = 0; 
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

    // int dup2(int oldfd, int newfd);
    // oldfd — файловый дескриптор, который нужно скопировать. Это уже открытый файловый дескриптор.
    // newfd — файловый дескриптор, который нужно заменить. Если он уже открыт, то будет закрыт перед копированием.
    // После вызова dup2, оба дескриптора(oldfd и newfd) будут указывать на один и тот же ресурс.
    // Если операция успешна, возвращается newfd.
    // При ошибке возвращается - 1, и errno устанавливается в код ошибки.if (pid == -1)
    
    int fd_pipe[2];
    if (pipe(fd_pipe) == -1)
    {
        close(fd_file1);
        close(fd_file2);
        printf("fd_pipe ERROR\n");
        return 0;
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        close(fd_file1);
        close(fd_file2);
        printf("pid ERROR\n");
        return 0;
    }
    
    // child 1
    if (pid == 0)
    {
        printf("CHILD 1\n");
        int fd_dup_in = dup2(fd_file1, 0);
        if (fd_dup_in == -1)
        {
            close(fd_file1);
            close(fd_file2);
            close(fd_pipe[0]);
            close(fd_pipe[1]);
            printf("fd_dup_in ERROR\n");
            return 0;
        }
        int fd_dup_out = dup2(fd_pipe[1], 1);
        if (fd_dup_out == -1)
        {
            close(fd_pipe[0]);
            close(fd_pipe[1]);
            close(fd_file2);
            close(fd_file1);
           // close(fd_dup_in);
            printf("fd_dup_in ERROR\n");
            return 0;
        }
        close(fd_pipe[0]);
        close(fd_pipe[1]);
        close(fd_file2);
        close(fd_file1);
        // char *param[] = {"/bin/ls",  "-l", NULL};
        // if (execve("/bin/ls", param, env) == -1)
        char *param[] = {"/bin/cat", NULL};
        if (execve("/bin/cat", param, NULL) == -1)
        {
            printf("execve ERROR\n");
            close(fd_file2);
         //   close(fd_dup_in);
        //    close(fd_dup_out);
            return 0;
        }
    }

    int fd_pipe2[2];
    if (pipe(fd_pipe2) == -1)
    {
        printf("fd_pipe2 ERROR\n");
        return 0;
    }

    pid = fork();
    if (pid == -1)
    {
        close(fd_file1);
        close(fd_file2);
        printf("pid middle ERROR\n");
        return 0;
    }
    
    // child 2
    if (pid == 0)
    {
        printf("CHILD 2\n");
        int fd_dup_in = dup2(fd_pipe[0], 0);
        if (fd_dup_in == -1)
        {
            close(fd_file1);
            close(fd_file2);
            close(fd_pipe[0]);
            close(fd_pipe[1]);
            printf("fd_dup_in 3 ERROR\n");
            return 0;
        }
        int fd_dup_out = dup2(fd_pipe2[1], 1);
        if (fd_dup_out == -1)
        {
            close(fd_pipe[0]);
            close(fd_pipe[1]);
            close(fd_file2);
            close(fd_file1);
           // close(fd_dup_in);
            printf("fd_dup_in 2 ERROR\n");
            return 0;
        }
        close(fd_pipe[0]);
        close(fd_pipe[1]);
        close(fd_pipe2[0]);
        close(fd_pipe2[1]);
        close(fd_file2);
        close(fd_file1);
        // char *param[] = {"/bin/ls",  "-l", NULL};
        // if (execve("/bin/ls", param, env) == -1)
        char *param[] = {"/bin/wc", "-w", NULL};
        if (execve("/bin/wc", param, NULL) == -1)
        {
            printf("execve 2 ERROR\n");
            close(fd_file2);
         //   close(fd_dup_in);
        //    close(fd_dup_out);
            return 0;
        }
    }

    int fd_pipe3[2];
    if (pipe(fd_pipe3) == -1)
    {
        printf("fd_pipe3 ERROR\n");
        return 0;
    }
    pid = fork();
    if (pid == -1)
    {
        printf("pid 3 ERROR\n");
        return 0;
    }
    // child 3
    if (pid == 0)
    {
        dup2(fd_pipe2[0], 0);
        dup2(fd_pipe3[1], 1);
        close(fd_pipe[0]);
        close(fd_pipe[1]);
        close(fd_pipe2[0]);
        close(fd_pipe2[1]);
        close(fd_pipe3[1]);
        close(fd_pipe3[0]);

        char *arg[] = {"/usr/bin/wc", "-m", NULL};
       // char **env = NULL;
        execve("/usr/bin/wc", arg, NULL);
    }

    // child 4
    pid = fork();
    if (pid == -1)
    {
        close(fd_file2);
        printf("pid ERROR\n");
        return 0;
    }
    if (pid == 0)
    {
        printf("CHILD 4\n");
        int fd_dup_in = dup2(fd_pipe3[0], 0);
        if (fd_dup_in == -1)
        {
            close(fd_pipe[0]);
            close(fd_pipe[1]);
            close(fd_pipe2[0]);
            close(fd_pipe2[1]);
            close(fd_file2);
            close(fd_file1);
            printf("fd_dup_in 4 ERROR\n");
            return 0;
        }
        int fd_dup_out = dup2(fd_file2, 1);
        if (fd_dup_out == -1)
        {
            close(fd_pipe[0]);
        close(fd_pipe[1]);
        close(fd_pipe2[0]);
        close(fd_pipe2[1]);
        close(fd_pipe3[1]);
        close(fd_pipe3[0]);
            close(fd_file2);
            close(fd_file1);
           // close(fd_dup_in);
            printf("fd_dup_in 4.2 ERROR\n");
            return 0;
        }
        close(fd_pipe[0]);
        close(fd_pipe[1]);
        close(fd_pipe2[0]);
        close(fd_pipe2[1]);
        close(fd_pipe3[1]);
        close(fd_pipe3[0]);
        close(fd_file2);
        close(fd_file1);
        char *param[] = {"/bin/cat", "-e", NULL};
        if (execve("/bin/cat", param, NULL) == -1)
        {
            printf("execve 4 ERROR\n");
            close(fd_dup_in);
            close(fd_dup_out);
            return 0;
        }
    }
    
    
    free_prog(&prog);
    return (0);
}
