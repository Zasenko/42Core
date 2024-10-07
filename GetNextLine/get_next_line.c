/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:13:39 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/07 12:42:38 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// what if BUFFER_SIZE > then line
// what if BUFFER_SIZE == 0?

char    *get_next_line(int fd)
{
    char    *buf;
    int     n;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
    if (buf == NULL)
        return (NULL);
    n = read(fd, buf, sizeof(char) * BUFFER_SIZE);
    if (n < 0)
    {
        *buf = NULL;
        free(buf);
        return (NULL);
    }
    else if (n == 0)
    {
        // if n == 0 end of file
    }
    else
    {
        *buf = NULL;
        free(buf);
        return (NULL);
        // if n == -1 error
    }
    printf("%d | c = %s\n", n, buf);
    return (buf);
}

#include <fcntl.h>

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=4 get_next_line.c
int main(void)
{
    char    *c;
    int     fd;

    fd = open("text.txt", O_RDONLY | O_CREAT);
    if (fd == -1)
    {
        printf("open error\n");
        return (1);
    }
    c = get_next_line(fd);
    c = get_next_line(fd);
    c = get_next_line(fd);
    c = get_next_line(fd);
    c = get_next_line(fd);
    c = get_next_line(fd);
    c = get_next_line(fd);
    c = get_next_line(fd);
    // i = read(fd1, c, BUFFER_SIZE);
    // printf("%d | c = %s\n", i, c);
    // i = read(fd1, c, BUFFER_SIZE);
    // printf("%d | c = %s\n", i, c);
    // i = read(fd1, c, BUFFER_SIZE);
    // printf("%d | c = %s\n", i, c);
    // i = read(fd1, c, BUFFER_SIZE);
    // printf("%d | c = %s\n", i, c);
    // i = read(fd1, c, BUFFER_SIZE);
    // printf("%d | c = %s\n", i, c);
    // i = read(fd1, c, BUFFER_SIZE);
    // printf("%d | c = %s\n", i, c);
    // i = read(fd1, c, BUFFER_SIZE);
    // printf("%d | c = %s\n", i, c);
    // i = read(fd1, c, BUFFER_SIZE);
    // printf("%d | c = %s\n", i, c);
    // int fd = open("text.txt", O_RDONLY | O_CREAT);
    // if (fd == -1) {
    //     printf("open error\n");
    //     exit(1);
    // }
    // char *test = get_next_line(fd);
    // if (close(fd) < 0) {
    //     printf("close error\n");
    //     exit(1);
    // }
    // printf("closed the fd.\n");
    return (0);
}
