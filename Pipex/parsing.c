/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:42:36 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/24 12:41:13 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_folders(t_prog *prog, char **env);
t_cmd	**parse_cmds(t_prog *prog, int ac, char **av);
char	**parse_cmd(char *arg, char **folders);
int		add_path_param(char **prog_name, char **folders);

void	parse(t_prog *prog, int ac, char **av, char **env)
{
	t_cmd	**cmnds;
	char	**folders;

	if (!prog || !av || ac != 5)
		print_err_exit(prog, "Parsing error\n");
	if (ac != 5)
		print_err_exit(prog, "Error: program need 4 arguments\n");
	open_files(prog, av[1], av[ac - 1]);
	folders = parse_folders(prog, env);
	if (!folders)
		print_err_exit(prog, "Can't get folders from env\n");
	prog->folders = folders;
	cmnds = parse_cmds(prog, ac, av);
	if (!cmnds)
		print_err_exit(prog, "Commands parsing error\n");
	prog->commands = cmnds;
}

char	**parse_folders(t_prog *prog, char **env)
{
	char	**folders;
	int		i;

	if (!prog || !env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			folders = ft_split(env[i] + 5, ':');
			if (!folders)
				return (NULL);
			return (folders);
		}
		i++;
	}
	return (NULL);
}

t_cmd	**parse_cmds(t_prog *prog, int ac, char **av)
{
	t_cmd	**commands;
	int		i;
	int		j;

	if (!prog || !av)
		return (printf("!commands[j]->args\n"), NULL);
	commands = init_commands(ac - 3);
	if (!commands)
		return (printf("!commands[j]->args\n"), NULL);
	i = 2;
	j = 0;
	while (i < ac - 1)
	{
		commands[j]->args = parse_cmd(av[i], prog->folders);
		if (!commands[j]->args)
			return (free_commands(commands), printf("!commands[j]->args\n"), NULL);
		i++;
		j++;
	}
	return (commands);
}

char	**parse_cmd(char *arg, char **folders)
{
	char	**args;

	if (!arg)
		return (NULL);
	args = ft_split(arg, ' ');
	if (!args)
		return (NULL);
	if (!add_path_param(args, folders))
	{
		free_arr_str(args);
		printf("parse_cmd add_path_param\n");
		return (NULL);
	}
	return (args);
}

int	add_path(char **prog_name, char *folder)
{
	char	*path;
	char	*full_path;

	if (!prog_name || !*prog_name || !folder)
		return (0);
	path = ft_strjoin(folder, "/");
	if (!path)
		return (0);
	full_path = ft_strjoin(path, *prog_name);
	if (!full_path)
		return (free(path), 0);
	free(path);
	if (!ft_check_file(full_path))
	{
		free(full_path);
		return (0);
	}
	else
	{
		free(*prog_name);
		*prog_name = full_path;
		return (1);
	}
}

int	add_path_param(char **prog_name, char **folders)
{
	int	i;

	if (!prog_name || !*prog_name || !folders)
		return (printf("add_path_param error\n"), -1);
	i = 0;
	while (folders[i])
	{
		if (add_path(prog_name, folders[i]))
			return (1);
		i++;
	}
	return (printf("Programm %s not found\n", *prog_name), -1);
}
