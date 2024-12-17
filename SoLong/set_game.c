/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:06:15 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 14:33:22 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_new_game(t_game *game)
{
	if (!game)
		return (0);
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_check.coins_count = 0;
	game->map_check.exit_count = 0;
	game->size.x = 0;
	game->size.y = 0;
	game->start.x = 0;
	game->start.y = 0;
	game->coins_count = 0;
	game->moves = 0;
	game->is_finish = 0;
	game->t.c = NULL;
	game->t.p = NULL;
	game->t.w = NULL;
	game->t.g = NULL;
	game->t.e_c = NULL;
	game->t.e_o = NULL;
	game->img_size = 50;
	game->is_p_on_e = 0;
	return (1);
}
