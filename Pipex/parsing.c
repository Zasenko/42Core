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

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t l;
    char *s_new;
    size_t i;
    size_t f;

    if (!s1 || !s2)
        return (NULL);
    l = ft_strlen(s1) + ft_strlen(s2);
    s_new = (char *)malloc((l + 1) * sizeof(char));
    if (s_new == NULL)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        s_new[i] = s1[i];
        i++;
    }
    f = 0;
    while (s2[f])
    {
        s_new[i++] = s2[f++];
    }
    s_new[i] = '\0';
    return (s_new);
}

char **parse_folders(t_prog *prog, char **env);
t_cmd **parse_cmds(t_prog *prog, int ac, char **av, char **folders);
char **parse_cmd(char *arg, char **folders);

int parse(t_prog *prog, int ac, char **av, char **env)
{
    t_cmd **cmnds;
    char **folders;

    if (!prog || !av || ac != 5)
    {
        //todo print error
        printf("ERROR PARSE\n");
        return (-1);//todo exit
    }

    if (!ft_strlen(av[1]) || !ft_strlen(av[ac - 1]))
    {
        // todo print error
        return (-1); // todo exit
    }

    prog->fd_file1 = open(av[1], O_RDONLY);
    if (prog->fd_file1 < 0)
    {
        free_prog(prog);
        perror("Can't open the file");
        exit(EXIT_FAILURE);
    }
    prog->fd_file2 = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644); // todo O_RDWR? or O_WRITE
    if (prog->fd_file2 < 0)
    {
        free_prog(prog);
        perror("Can't open or create the file");
        exit(EXIT_FAILURE);
    }
    folders = parse_folders(prog, env);
    if (!folders)
    {
        printf("!folders\n");
        return (-1); // todo exit
    }
    prog->folders = folders;//to do не нужно?
    // todo check folders > 0 ???

    cmnds = parse_cmds(prog, ac, av, folders);
    if (!cmnds)
    {
        printf("!cmnds\n");
        return (-1); // todo exit
    }
    prog->commands = cmnds;
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

t_cmd **parse_cmds(t_prog *prog, int ac, char **av, char **folders)
{
    t_cmd **commands;

    if (!prog || !av || ac < 5)
    {
        printf("!prog || !av || ac < 5\n");
        return (NULL);
    }

    int commands_count = ac - 3;
    commands = (t_cmd **)malloc(sizeof(t_cmd *) * (commands_count + 1));
    if (!commands)
    {
        printf("!commands\n");
        return (NULL);
    }
    //set to NULL
    int a = 0;
    while (a <= commands_count)
    {
        commands[a] = NULL;
        a++;
    }

    // new commands
    int s = 0;
    while (s < commands_count)
    {
        t_cmd *new_cmd = malloc(sizeof(t_cmd));
        if (!new_cmd)
        {
            free_commands(commands);
            printf("!new_cmd\n");
            return (NULL);
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
        commands[j]->args = parse_cmd(av[i], folders);
        if (!commands[j]->args)
        {
            free_commands(commands);
            printf("!commands[j]->args\n");
            return (NULL);
        }
        i++;
        j++;
    }
    return (commands);
}

int add_path_param(char **prog_name, char **folders)
{
    if (!prog_name || !*prog_name || !folders)
    {
        return -1; // todo
    }

    int i = 0;
    while (folders[i])
    {

        // path prog->folders[i] + / ??? + prog name
        char *folder = ft_strjoin(folders[i], "/");
        if (!folder)
        {
            //free
            return -1;
        }
        char *full_path = ft_strjoin(folder, *prog_name);
        if (!full_path)
        {
            free(folder);
            return -1;
        }
        printf("path to check: %s\n", full_path);

        int f = ft_check_file(full_path);
        printf("result: %d\n", f);

        if (f == -1) // todo path  prog->folders[i] + / ??? + prog name
        {
            printf("NO path: %s\n", full_path);
            free(folder);
            folder = NULL;
            free(full_path);
            full_path = NULL;
            i++;
        } else {
   

            printf("OK path: %s\n", full_path);
            free(folder);
            free(*prog_name);
            *prog_name = full_path;
            //////////////////////////
            // folders[i] = full_path;
            return 1;
        }
    }
    // exit error команда/программа не найдена
    return (-1);
}

char **parse_cmd(char *arg, char **folders)
{
    char **args;

    if (!arg)
        return (NULL);
    args = ft_split(arg, ' ');
    if (!args)
        return (NULL);
    int arg_count = arr_str_count(args);
    if (arg_count < 1)
    {
        free_arr_str(args);
        printf("parse_cmd arg_count < 2\n");
        return (NULL);
    }
    if (!add_path_param(args, folders))
    {
        free_arr_str(args);
        printf("parse_cmd add_path_param\n");
        return (NULL);
    }
    return (args);
}
