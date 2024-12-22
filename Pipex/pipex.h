/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:58:55 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/20 12:23:28 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_cmd
{
    char **args;
} t_cmd;

typedef struct s_prog
{
    int fd_file1;
    int fd_file2;
    int fd_pipe[2];
    t_cmd **commands;
    char **folders;
} t_prog;

int init_prog(t_prog *prog);
void free_arr_str(char **arr);
void free_commands(t_cmd **commands);
void free_prog(t_prog *prog);
void close_fd(t_prog *prog);
size_t ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int parse(t_prog *prog, int ac, char **av, char **env);
int check_file(char *path);

#endif