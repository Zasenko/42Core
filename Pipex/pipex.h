/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:58:55 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/19 15:48:57 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_cmd
{
    char **args;
} t_cmd;

typedef struct s_prog
{
    char *file1_path;
    char *file2_path;
    t_cmd **commands;
    char **folders;
} t_prog;

int init_prog(t_prog *prog);
void free_arr_str(char **arr);
void free_prog(t_prog *prog);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int parse(t_prog *prog, int ac, char **av, char **env);

#endif
