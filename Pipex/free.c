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

void free_prog(t_prog *prog)
{
    if (!prog)
        return ;
    prog->file1_path = NULL;
    prog->file2_path = NULL;
    if (prog->commands)
    {
        int i = 0;
        while(prog->commands[i])
        {
            if (prog->commands[i]->args)
            {
                int j = 0;
                while(prog->commands[i]->args[j])
                {
                    free(prog->commands[i]->args[j]);
                    prog->commands[i]->args[j] = NULL;
                    j++;
                }
                free(prog->commands[i]->args);
                prog->commands[i]->args = NULL;
            }
            free(prog->commands[i]);
            prog->commands[i] = NULL;  
            i++;
        }
        free(prog->commands);
        prog->commands = NULL;
    }
    return ;
}
