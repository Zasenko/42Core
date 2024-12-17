/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:15:14 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 11:43:39 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	set_start(t_game *game, char **map);
static void	fill(t_game *game, char **map, int row, int col);

int	check_path(t_game *game, char **map)
{
	if (!game || !map || !set_start(game, map))
		return (-1);
	fill(game, map, game->start.y, game->start.x);
	if (game->map_check.coins_count != 0 || game->map_check.exit_count != 0)
		return (0);
	game->map_check.coins_count = game->coins_count;
	game->coins_count = 0;
	return (1);
}

static int	set_start(t_game *game, char **map)
{
	int	i;
	int	f;

	if (!game || !map)
		return (-1);
	i = 0;
	while (map[i])
	{
		f = 0;
		while (map[i][f])
		{
			if (map[i][f] == 'P')
			{
				game->start.x = f;
				game->start.y = i;
				return (1);
			}
			f++;
		}
		i++;
	}
	return (0);
}

static void	fill(t_game *game, char **map, int row, int col)
{
	if (!game || !map)
		return ;
	if (row < 0 || col < 0 || row >= game->size.y || col >= game->size.x)
		return ;
	if (map[row][col] == '1' || map[row][col] == 'Z')
		return ;
	if (map[row][col] == 'C')
		game->map_check.coins_count--;
	else if (map[row][col] == 'E')
		game->map_check.exit_count--;
	map[row][col] = 'Z';
	fill(game, map, row -1, col);
	fill(game, map, row +1, col);
	fill(game, map, row, col - 1);
	fill(game, map, row, col + 1);
}
