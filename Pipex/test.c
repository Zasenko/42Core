#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

extern char **environ; // Для передачи окружения в execve

int main(int ac, char **av)
{
    if (ac < 5)
        return (0);

    char *path_file1 = av[1];
    char *path_file2 = av[ac - 1];

    // Открытие файлов
    int fd_file1 = open(path_file1, O_RDONLY);
    if (fd_file1 < 0)
    {
        perror("Ошибка открытия file1");
        return 1;
    }

    int fd_file2 = open(path_file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd_file2 < 0)
    {
        perror("Ошибка открытия file2");
        close(fd_file1);
        return 1;
    }

    // Создание pipe
    int fd_pipe[2];
    if (pipe(fd_pipe) == -1)
    {
        perror("Ошибка создания pipe");
        close(fd_file1);
        close(fd_file2);
        return 1;
    }

    // Первый дочерний процесс (ls -l)
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("Ошибка fork (child 1)");
        close(fd_file1);
        close(fd_file2);
        close(fd_pipe[0]);
        close(fd_pipe[1]);
        return 1;
    }

    if (pid == 0)
    {
        dup2(fd_file1, 0);   // Перенаправляем stdin на file1
        dup2(fd_pipe[1], 1); // Перенаправляем stdout в pipe
        close(fd_file1);
        close(fd_pipe[0]);
        close(fd_pipe[1]);
        char *param[] = {"/bin/ls", "-l", NULL};
        if (execve("/bin/ls", param, environ) == -1)
        {
            perror("Ошибка execve (ls -l)");
            exit(1);
        }
    }

    // Второй дочерний процесс (wc -l)
    pid = fork();
    if (pid == -1)
    {
        perror("Ошибка fork (child 2)");
        close(fd_file2);
        close(fd_pipe[0]);
        close(fd_pipe[1]);
        return 1;
    }

    if (pid == 0)
    {
        dup2(fd_pipe[0], 0); // Перенаправляем stdin из pipe
        dup2(fd_file2, 1);   // Перенаправляем stdout в file2
        close(fd_pipe[0]);
        close(fd_pipe[1]);
        close(fd_file2);
        char *param[] = {"/usr/bin/wc", "-l", NULL};
        if (execve("/usr//bin/wc", param, environ) == -1)
        {
            perror("Ошибка execve (wc -l)");
            exit(1);
        }
    }

    // Закрываем дескрипторы в родительском процессе
    close(fd_file1);
    close(fd_file2);
    close(fd_pipe[0]);
    close(fd_pipe[1]);

    // Ожидаем завершения дочерних процессов
    waitpid(-1, NULL, 0);
    waitpid(-1, NULL, 0);

    return 0;
}
