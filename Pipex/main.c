#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <fcntl.h>
#include <stdlib.h>

int main(int ac, char **av,char **env)
{
    if (ac < 5)
        return (0);
    char *path_file1 = av[1];
    int i = 2;
    while (i < ac - 1)
    {
        printf("%s\n", av[i]);
        i++;
    }
    char *path_file2 = av[ac - 1];
    printf("file1: %s\n", path_file1);
    printf("file2: %s\n", path_file2);

    //int access(const char *pathname, int mode);
    // F_OK — проверяет существование файла.
    // R_OK — проверяет права на чтение.
    // W_OK — проверяет права на запись.
    // X_OK — проверяет права на выполнение.
    if (access(path_file1, F_OK) == 0)
    {
        printf("F_OK\n");
    }
    else
    {
        printf("F_OK NO\n");
    }
    if (access(path_file1, R_OK) == 0)
    {
        printf("R_OK\n");
    }
    else
    {
        printf("R_OK NO\n");
    }
    if (access(path_file1, W_OK) == 0)
    {
        printf("W_OK\n");
    }
    else
    {
        printf("W_OK NO\n");
    }
    if (access(path_file1, F_OK) == 0)
    {
        printf("X_OK\n");
    }
    else
    {
        printf("X_OK NO\n");
    }
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
    // access file2 ???

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
        if (execve("/bin/cat", param, env) == -1)
        {
            printf("execve ERROR\n");
            close(fd_file2);
         //   close(fd_dup_in);
        //    close(fd_dup_out);
            return 0;
        }
    }
    // child 2
    pid = fork();
    if (pid == -1)
    {
        close(fd_file2);
        printf("pid ERROR\n");
        return 0;
    }
    if (pid == 0)
    {
        printf("CHILD 2\n");
        int fd_dup_in = dup2(fd_pipe[0], 0);
        if (fd_dup_in == -1)
        {
            close(fd_pipe[0]);
            close(fd_pipe[1]);
            close(fd_file2);
            close(fd_file1);
            printf("fd_dup_in ERROR\n");
            return 0;
        }
        int fd_dup_out = dup2(fd_file2, 1);
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
        char *param[] = {"/usr/bin/wc", "-w", NULL};
        if (execve("/usr/bin/wc", param, env) == -1)
        {
            printf("execve 2 ERROR\n");
            close(fd_dup_in);
            close(fd_dup_out);
            return 0;
        }
    }

    // Закрываем ненужные дескрипторы в родительском процессе
    close(fd_file1);
    close(fd_file2);
    close(fd_pipe[0]);
    close(fd_pipe[1]);

    // Ожидаем завершения дочерних процессов
    waitpid(-1, NULL, 0);
    waitpid(-1, NULL, 0);
    return (0);
}
