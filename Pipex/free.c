/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:55:30 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/24 10:15:51 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr_str(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	return ;
}

void	close_fd(t_prog *prog)
{
	if (!prog)
		return ;
	if (prog->fd_pipe[0] > 2)
		close(prog->fd_pipe[0]);
	if (prog->fd_pipe[1] > 2)
		close(prog->fd_pipe[1]);
	if (prog->fd_file1 > 2)
		close(prog->fd_file1);
	if (prog->fd_file2 > 2)
		close(prog->fd_file2);
}

void	free_prog(t_prog *prog)
{
	if (!prog)
		return ;
	close_fd(prog);
	if (prog->commands)
	{
		free_commands(prog->commands);
		prog->commands = NULL;
	}
	if (prog->folders)
	{
		free_arr_str(prog->folders);
		prog->folders = NULL;
	}
}

void	free_commands(t_cmd **commands)
{
	int	i;

	if (!commands)
		return ;
	i = 0;
	while (commands[i])
	{
		if (commands[i]->args)
		{
			free_arr_str(commands[i]->args);
			commands[i]->args = NULL;
		}
		free(commands[i]);
		commands[i] = NULL;
		i++;
	}
	free(commands);
	return ;
}
