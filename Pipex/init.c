/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:51:37 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/19 17:23:03 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int init_prog(t_prog *prog)
{
    if (!prog)
        return 0;
    prog->file1_path = NULL;
    prog->file2_path = NULL;
    prog->commands = NULL;
    prog->folders = NULL;
    return 1;
}
