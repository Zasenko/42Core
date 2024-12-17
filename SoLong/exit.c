/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:53:43 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 11:51:12 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(t_game *game)
{
	if (!game)
		return ;
	write(1, "You won!\n", 9);
	free_game(game);
}

int	close_window(t_game *game)
{
	if (!game)
		return (0);
	free_game(game);
	return (1);
}
