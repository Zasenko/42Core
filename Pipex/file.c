/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:33:50 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/26 16:45:34 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_file(char *path)
{
	if (!path)
		return (0);
	if (access(path, F_OK) == -1)
		return (0);
	if (access(path, R_OK) == -1)
		return (0);
	if (access(path, X_OK) == -1)
		return (0);
	return (1);
}

int	open_files(t_prog *prog, char *f1_path, char *f2_path)
{
	if (!prog || !f1_path || !f2_path)
		return (ft_putstr("Open files error\n"), 0);
	if (!ft_strlen(f1_path))
		return (ft_putstr("Input file path less then 1\n"), 0);
	if (!ft_strlen(f2_path))
		return (ft_putstr("Output file path less then 1\n"), 0);
	prog->fd_file1 = open(f1_path, O_RDONLY);
	if (prog->fd_file1 < 0)
		return (perror("Can't open the input file"), 0);
	prog->fd_file2 = open(f2_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (prog->fd_file2 < 0)
		return (perror("Can't open the output file"), 0);
	return (1);
}
