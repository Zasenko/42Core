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
int		add_path(char **prog_name, char *folder);

int parse(t_prog *prog, int ac, char **av, char **env)
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

int is_char_is_sep(char c, char *sep)
{
	int i;

	i = 0;
	if (!sep)
		return (i);
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int count_till_sep(char *str, char *sep)
{
	int i;

	i = 0;
	if (!str || !sep)
		return (i);
	while (str[i])
	{
		if (is_char_is_sep(str[i], sep) == 0)
			i++;
		else
			break;
	}
	return (i);
}

char *ft_trimm(char *str, char *sep, char *c)
{
	char *trimmed;
	int count;

	if (!str || !sep || !c)
		return (NULL);
	trimmed = NULL;
	count = ft_strlen(str);
	if (count < 1)
		return (NULL);
	trimmed = malloc(sizeof(char));
	if (!trimmed)
		return (NULL);
	trimmed[0] = '\0';

	while (*str)
	{
		if (is_char_is_sep(*str, sep) == 1)
			str++;
		else
			break;
	}
	while (*str)
	{
		int count = count_till_sep(str, sep);
		if (count > 0)
		{
			char *new = malloc(sizeof(char) * (count + 1));
			if (!new)
			{
				free(trimmed);
				return (NULL);
			}
			int d = 0;
			while (d <= count)
			{
				new[d] = '\0';
				d++;
			}
			d = 0;
			while (d < count)
			{
				new[d] = *str;
				d++;
				str++;
			}

			int flag = 0;
			while (is_char_is_sep(*str, sep) == 1)
			{
				str++;
				flag = 1;
			}
			if (flag && *str != '\0')
			{
				char *new_char = ft_strjoin(new, c);
				if (!new_char)
					return (free(trimmed), free(new), NULL);
				free(new);
				char *new_new = ft_strjoin(trimmed, new_char);
				if (!new_new)
					return (free(trimmed), free(new_char), NULL);
				free(trimmed);
				free(new_char);
				trimmed = new_new;
			}
			else
			{
				char *new_new = ft_strjoin(trimmed, new);
				if (!new_new)
					return (free(trimmed), free(new), NULL);
				free(trimmed);
				free(new);
				trimmed = new_new;
			}
		}
	}
	return (trimmed);
}

char	**parse_cmd(char *arg, char **folders)
{
	char	**args;
	char *trimmed_str;

	if (!arg)
		return (ft_putstr("Command parsing error\n"), NULL);
	trimmed_str = ft_trimm(arg, " \t", " ");
	if (!trimmed_str)
		return (ft_putstr("Command parsing error: trimm\n"), NULL);
	args = ft_split(trimmed_str, ' ');
	free(trimmed_str);
	if (!args)
		return (ft_putstr("Wrong arguments\n"), print_example(), NULL);
	if (!add_path_param(args, folders))
		return (free_arr_str(args), NULL);
	return (args);
}

int	add_path_param(char **prog_name, char **folders)
{
	int	i;
	int result;

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
