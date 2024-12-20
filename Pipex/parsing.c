/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:42:36 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/20 13:10:53 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
    if (!s)
    {
        return (i);
    }
	while (s[i])
		i++;
	return (i);
}

char **parse_folders(t_prog *prog, char **env);
t_cmd **parse_cmds(t_prog *prog, int ac, char **av);
char **parse_cmd(char *arg);

int parse(t_prog *prog, int ac, char **av, char **env)
{
    t_cmd **cmnds;
    char **folders;

    if (!prog || !av || ac < 5)
        return (0);
    prog->file1_path = av[1];
    prog->file2_path = av[ac - 1];
    //todo check files path > 0
    if (!prog->file1_path || !prog->file2_path)
        return (0);
    cmnds = parse_cmds(prog, ac, av);
    if (!cmnds)
        return (0);
    prog->commands = cmnds;
    // todo check parse_cmds > 2 ???
    folders = parse_folders(prog, env);
    if (!folders)
        return (0);
    prog->folders = folders;
    // todo check folders > 0 ??? 
    return 1;
}

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    if (!big || !little)
        return (NULL);
    i = 0;
    if (little[i] == '\0')
        return ((char *)big);
    while (big[i] && i < len)
    {
        j = 0;
        while (big[i + j] && (i + j) < len && big[i + j] == little[j])
        {
            j++;
            if (little[j] == '\0')
                return ((char *)&big[i]);
        }
        i++;
    }
    return (NULL);
}

int arr_str_count(char **arr)
{
    int i;

    if (!arr)
        return 0;
    i = 0;
    while (arr[i])
        i++;
    return i;
}

char **parse_folders(t_prog *prog, char **env)
{
    char **folders;
    int i;

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

t_cmd **parse_cmds(t_prog *prog, int ac, char **av)
{
    t_cmd **commands;

    if (!prog || !av || ac < 5)
        return (NULL);

    int commands_count = ac - 3;
    commands = (t_cmd **)malloc(sizeof(t_cmd *) * (commands_count + 1));
    if (!commands)
        return (NULL);
    //set to NULL
    int a = 0;
    while (a <= commands_count)
    {
        commands[a] = NULL;
        a++;
    }

    // parse commands
    int s = 0;
    while (s < commands_count)
    {
        t_cmd *new_cmd = malloc(sizeof(t_cmd));
        if (!new_cmd)
        {
            free_commands(commands);
            return NULL;
        }
        new_cmd->args = NULL;
        commands[s] = new_cmd;
        s++;
    }

    // parse argums for commands
    int i = 2;
    int j = 0;
    while (i < ac - 1)
    {
        commands[j]->args = parse_cmd(av[i]);
        if (!commands[j]->args)
        {
            free_commands(commands);
            return (NULL);
        }
        i++;
        j++;
    }
    return (commands);
}

char **parse_cmd(char *arg)
{
    char **args;
    
    if (!arg)
        return (NULL);
    args = ft_split(arg, ' ');
    if (!args)
        return (NULL);
    return (args);
}