/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:08:08 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 12:00:13 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	set_exit_texture(t_game *g, int y, int x);
static int	set_textures(t_game *g, int y, int x);
static int	set_textures_in_row(t_game *game, int y);

int	make_img(t_game *game)
{
	int	y;

	if (!game || !game->map)
		return (0);
	y = 0;
	while (game->map[y])
	{
		if (!set_textures_in_row(game, y))
			return (0);
		y++;
	}
	return (1);
}

static int	set_exit_texture(t_game *g, int y, int x)
{
	int	s;

	if (!g || !g->mlx || !g->win || !g->t.e_o || !g->t.e_c)
		return (0);
	s = g->img_size;
	if (g->coins_count == g->map_check.coins_count)
		mlx_put_image_to_window(g->mlx, g->win, g->t.e_o, x * s, y * s);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->t.e_c, x * s, y * s);
	return (1);
}

static int	set_textures(t_game *g, int y, int x)
{
	int	s;

	if (!g || !g->map
		|| !g->mlx || !g->win || !g->t.w || !g->t.g || !g->t.c || !g->t.p)
		return (0);
	s = g->img_size;
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->t.w, x * s, y * s);
	else if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->t.g, x * s, y * s);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->t.c, x * s, y * s);
	else if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->t.p, x * s, y * s);
	else if (g->map[y][x] == 'E')
	{
		if (!set_exit_texture(g, y, x))
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	set_textures_in_row(t_game *game, int y)
{
	int	x;

	if (!game || !game->map)
		return (0);
	x = 0;
	while (game->map[y][x])
	{
		if (!set_textures(game, y, x))
			return (0);
		x++;
	}
	return (1);
}
