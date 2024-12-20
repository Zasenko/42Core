/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:55:30 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/19 17:13:45 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void free_commands(t_cmd **commands);

void free_arr_str(char **arr)
{
    int i;

    if (!arr)
        return ;
    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    return;
}

void free_prog(t_prog *prog)
{
    if (!prog)
        return ;
    prog->file1_path = NULL;
    prog->file2_path = NULL;
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
    return ;
}

static void free_commands(t_cmd **commands)
{
    int i;
    
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
    return;
}
