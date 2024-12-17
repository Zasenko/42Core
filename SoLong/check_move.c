/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:54:33 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 14:58:48 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_game *game, int x, int y)
{
	char	c;

	if (!game || !game->map || x < 1 || y < 1
		|| x >= game->size.x - 1 || y >= game->size.y - 1)
		return (0);
	c = game->map[y][x];
	if (c == '1')
		return (0);
	else if (c == 'C')
		game->coins_count++;
	else if (c == 'E')
	{
		if (game->coins_count == game->map_check.coins_count)
			game->is_finish = 1;
		else
			return (666);
	}
	return (1);
}
