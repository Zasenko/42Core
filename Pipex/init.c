/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:51:37 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/20 12:24:14 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int init_prog(t_prog *prog)
{
    if (!prog)
        return 0;
    prog->fd_file1 = -1;
    prog->fd_file2 = -1;
    prog->fd_pipe[0] = -1;
    prog->fd_pipe[1] = -1;
    prog->commands = NULL;
    prog->folders = NULL;
    return 1;
}
