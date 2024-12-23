/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:51:37 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/23 13:09:31 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_prog(t_prog *prog)
{
	if (!prog)
		return (0);
	prog->fd_file1 = -1;
	prog->fd_file2 = -1;
	prog->fd_pipe[0] = -1;
	prog->fd_pipe[1] = -1;
	prog->commands = NULL;
	prog->folders = NULL;
	return (1);
}

t_cmd	**init_commands(int count)
{
	t_cmd **commands;
	int i;

	commands = (t_cmd **)malloc(sizeof(t_cmd *) * (count + 1));
	if (!commands)
		return (printf("!commands\n"), NULL);
	i = 0;
	while (i <= count)
	{
		commands[i] = NULL;
		i++;
	}
	i = 0;
	while (i < count)
	{
		t_cmd *new_cmd = malloc(sizeof(t_cmd));
		if (!new_cmd)
			return (free_commands(commands), printf("!new_cmd\n"), NULL);
		new_cmd->args = NULL;
		commands[i] = new_cmd;
		i++;
	}
	return (commands);
}
