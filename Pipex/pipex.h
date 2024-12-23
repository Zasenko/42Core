/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:58:55 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/23 13:10:24 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char	**args;
}	t_cmd;

typedef struct s_prog
{
	int		fd_file1;
	int		fd_file2;
	int		fd_pipe[2];
	t_cmd	**commands;
	char	**folders;
}	t_prog;

int		init_prog(t_prog *prog);
t_cmd	**init_commands(int count);
void	free_arr_str(char **arr);
void	free_commands(t_cmd **commands);
void	free_prog(t_prog *prog);
void	close_fd(t_prog *prog);
char	**ft_split(char const *s, char c);
void	parse(t_prog *prog, int ac, char **av, char **env);
int		ft_check_file(char *path);
void	open_files(t_prog *prog, char *f1_path, char *f2_path);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		arr_str_count(char **arr);
char	*ft_strjoin(char const *s1, char const *s2);

#endif