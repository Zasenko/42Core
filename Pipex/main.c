#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <fcntl.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac < 5)
        return (0);
    char *file1 = av[1];
    int i = 2;
    while (i < ac - 1)
    {
        printf("%s\n", av[i]);
        i++;
    }
    char *file2 = av[ac - 1];
    printf("file1: %s\n", file1);
    printf("file2: %s\n", file2);

    //int access(const char *pathname, int mode);
    // F_OK — проверяет существование файла.
    // R_OK — проверяет права на чтение.
    // W_OK — проверяет права на запись.
    // X_OK — проверяет права на выполнение.
    if (access(file1, F_OK) == 0)
    {
        printf("F_OK\n");
    }
    else
    {
        printf("F_OK NO\n");
    }
    if (access(file1, R_OK) == 0)
    {
        printf("R_OK\n");
    }
    else
    {
        printf("R_OK NO\n");
    }
    if (access(file1, W_OK) == 0)
    {
        printf("W_OK\n");
    }
    else
    {
        printf("W_OK NO\n");
    }
    if (access(file1, F_OK) == 0)
    {
        printf("X_OK\n");
    }
    else
    {
        printf("X_OK NO\n");
    }

    int fd_file1 = open(file1, O_RDONLY);
    if (fd_file1 < 0)
    {
        printf("ERROR fd_file1\n");
        return 1;
    }
    int fd_file2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

    int fd_dup_in = dup2(fd_file1, 0);
    if (fd_dup_in == -1)
    {
        close(fd_file1);
        close(fd_file2);
        printf("dup2 ERROR\n");
        return 0;
    }
    close(fd_file1);

    char file1_text[100];
    int size = read(0, file1_text, 99);
    if (!size)
        file1_text[size] = '\0';

    if (dup2(fd_file2, 1) == -1)
    {
        close(fd_file2);
        printf("dup2 ERROR\n");
        return 0;
    }
    close(fd_file2);
    write(1, file1_text, size);

    // int pipe(int pipefd[2]);
    //  pipefd[0] — для чтения.
    //  pipefd[1] — для записи.
    // fd — массив из двух элементов: fd[0] и fd[1].
    // Если функция выполнилась успешно, она вернёт 0.
    // В случае ошибки вернёт -1
    
    // int pipe_fd[2]; // Массив для дескрипторов
    // if (pipe(pipe_fd) == -1)
    // {
    //     perror("Ошибка pipe");
    //     return 1;
    // }

    // //pid_t fork(void); дочерний процесс
    // // == -1 error
    // // == 0 child
    // //  > 0 parent

    // pid_t pid = fork();    
    // if (pid == -1)
    // {
    //     printf("fork1 == -1 error\n");
    // }
    // if (pid == 0)
    // {
    //     printf("CHILD:\n");
    //     close(pipe_fd[1]);

    //     char buffer[50];
    //     int size = read(pipe_fd[0], buffer, 50);
    //     buffer[size] = '\0';
    //     printf("child size: %d\n", size);
    //     printf("child buffer: %s\n", buffer);
    //     write(fd_file2, buffer, size);

    //     close(fd_file2);
    //     close(pipe_fd[0]);

    //     printf("END CHILD\n");
    // }
    // else
    // {
    //     printf("PARENT:\n");
    //     close(pipe_fd[0]);

    //     char buffer[50];
    //     int size = read(fd_file1, buffer, 50);
    //     buffer[size] = '\0';
    //     printf("parent size: %d\n", size);
    //     printf("parent buffer: %s\n", buffer);

    //     write(pipe_fd[1], buffer, size);

    //     close(fd_file1);
    //     close(pipe_fd[1]);

    //     wait(NULL); // Ожидание завершения дочернего процесса
    //     printf("END PARENT\n");

    //     // char *argv[] = {"/bin/ls", "-l", NULL};
    //     // char *env[] = {NULL};
    //     // if (execve("/bin/ls", argv, env) == -1)
    //     // {
    //     //     printf("ERROR execve\n");
    //     //     return (0);
    //     // }

    //     // return(0);
    // }
    
    return (0);
}
