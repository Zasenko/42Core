/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:42:36 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/19 17:11:36 by dzasenko         ###   ########.fr       */
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

t_cmd **parse_cmds(t_prog *prog, int ac, char **av);
char **parse_cmd(char *arg);

int parse(t_prog *prog, int ac, char **av)
{
    if (!prog || !av)
        return (0);
    if (ac < 5)
        return (0);
    prog->file1_path = av[1];
    prog->file2_path = av[ac - 1];
    if (!prog->file1_path || !prog->file2_path)
        return (0);
    // parse command
    t_cmd **cmnds = parse_cmds(prog, ac, av);
    if (!cmnds)
        return (0);
    prog->commands = cmnds;
    return 1;
}

// ./pipex "infile" "ls -l" "wc -l -w" "outfile"

t_cmd **parse_cmds(t_prog *prog, int ac, char **av)
{
    t_cmd **commands;

    if (!prog || !av || ac < 5)
        return (NULL);

    int commands_count = ac - 3;
    commands = (t_cmd **)malloc(sizeof(t_cmd *) * (commands_count + 1));
    if (!commands)
        return (NULL);
    int a = 0;
    while (a <= commands_count)
    {
        commands[a] = NULL;
        a++;
    }
    int s = 0;
    while (s < commands_count)
    {
        t_cmd *new_cmd = malloc(sizeof(t_cmd));
        if (!new_cmd)
        {
            //todo free commands;
            return NULL;
        }
        new_cmd->args = NULL;
        commands[s] = new_cmd;
        s++;
    }
    
    int i = 2;
    int j = 0;
    while (i < ac - 1)
    {
        commands[j]->args = parse_cmd(av[i]);
        if (!commands[j]->args)
        {
            //todo free commands;
            return (NULL);
        }
        i++;
        j++;
    }
    return (commands);
}


// char *clean_str(char *s)
// {
//     char *clean_str;
//     int len;
    
//     clean_str = NULL;
//     if (!s)
//         return (NULL);
//     len = ft_strlen(s);
//     *clean_str = malloc(sizeof(char) * (len + 1));
//     if (!clean_str)
//         return (NULL);
//     int i = 0;
//     int j = 0;
//     while (s[i] == ' ' || s[i] == '\t')
//     {
//         i++;
//     }
//     return (clean_str)
// }

// char **ft_split(char *arg)
// {
//     char **arr;
    
//     arr = NULL;
//     if (!arg)
//         return NULL;
//     int arg_c;
// }

char **parse_cmd(char *arg)// "ls -l -w" 
{
    char **args;
    //int count;
    
    if (!arg)
        return (NULL);

    args = ft_split(arg, ' ');
    if (!args)
        return (NULL);

       
    // count = ft_strlen(arg);
    // if (!count)
    //     return (0);

    // how much arg
    //malloc + 1 NULL;
    // split?

    return (args);
}