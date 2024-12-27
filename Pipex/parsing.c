/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:42:36 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/26 17:05:32 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	**parse_cmds(t_prog *prog, int ac, char **av);
char	**parse_cmd(char *arg, char **folders);
int		add_path_param(char **prog_name, char **folders);
int		add_path(char **prog_name, char *folder);

int	parse(t_prog *prog, int ac, char **av, char **env)
{
	t_cmd	**cmnds;
	char	**folders;

	if (!prog || !av || !env)
		return (ft_putstr("Parsing error\n"), 0);
	if (ac != 5)
		return (ft_putstr("Program need 4 arguments\n"), print_example(), 0);
	if (!open_files(prog, av[1], av[ac - 1]))
		return (0);
	folders = parse_folders(prog, env);
	if (!folders)
		return (ft_putstr("Error: parsing folders from env\n"), 0);
	prog->folders = folders;
	cmnds = parse_cmds(prog, ac, av);
	if (!cmnds)
		return (0);
	prog->commands = cmnds;
	return (1);
}

t_cmd	**parse_cmds(t_prog *prog, int ac, char **av)
{
	t_cmd	**commands;
	int		i;
	int		j;

	if (!prog || !av)
		return (ft_putstr("Commands parsing error\n"), NULL);
	commands = init_commands(ac - 3);
	if (!commands)
		return (ft_putstr("Init commands error\n"), NULL);
	i = 2;
	j = 0;
	while (i < ac - 1)
	{
		commands[j]->args = parse_cmd(av[i], prog->folders);
		if (!commands[j]->args)
			return (free_commands(commands), NULL);
		i++;
		j++;
	}
	return (commands);
}

char	**parse_cmd(char *arg, char **folders)
{
	char	**args;
	char	*new;

	if (!arg)
		return (ft_putstr("Command parsing error\n"), NULL);
	new = ft_trim(arg, " \t", " ");
	if (!new)
		return (ft_putstr("Command parsing error: trimm\n"), NULL);
	args = ft_split(new, ' ');
	free(new);
	if (!args)
		return (ft_putstr("Wrong arguments\n"), print_example(), NULL);
	if (!add_path_param(args, folders))
		return (free_arr_str(args), NULL);
	return (args);
}

int	add_path_param(char **prog_name, char **folders)
{
	int	i;
	int	result;

	if (!prog_name || !*prog_name || !folders)
		return (ft_putstr("Add path error\n"), 0);
	i = 0;
	while (folders[i])
	{
		result = add_path(prog_name, folders[i]);
		if (result == -1)
			return (ft_putstr("Add path error\n"), 0);
		else if (result == 1)
			return (1);
		i++;
	}
	ft_putstr("Programm \"");
	ft_putstr(*prog_name);
	ft_putstr("\" not found\n");
	return (0);
}

int	add_path(char **prog_name, char *folder)
{
	char	*path;
	char	*full_path;

	if (!prog_name || !*prog_name || !folder)
		return (-1);
	path = ft_strjoin(folder, "/");
	if (!path)
		return (-1);
	full_path = ft_strjoin(path, *prog_name);
	if (!full_path)
		return (free(path), -1);
	free(path);
	if (!ft_check_file(full_path))
		return (free(full_path), 0);
	else
	{
		free(*prog_name);
		*prog_name = full_path;
		return (1);
	}
}
