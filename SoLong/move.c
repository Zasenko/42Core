/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:38:28 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 15:05:07 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game, int x, int y);
static void	move_down(t_game *game, int x, int y);
static void	move_left(t_game *game, int x, int y);
static void	move_right(t_game *game, int x, int y);

int	move(t_game *game, int move)
{
	int	x;
	int	y;

	if (!game || !game->map)
		return (0);
	x = game->start.x;
	y = game->start.y;
	if (move == 1)
		move_up(game, x, y);
	else if (move == 2)
		move_left(game, x, y);
	else if (move == 3)
		move_right(game, x, y);
	else if (move == 4)
		move_down(game, x, y);
	return (make_img(game));
}

static void	move_up(t_game *game, int x, int y)
{
	int	i;

	if (!game || !game->map)
		return ;
	i = check_move(game, x, y - 1);
	if (i)
	{
		game->map[y - 1][x] = 'P';
		if (game->is_p_on_e == 1)
		{
			game->map[y][x] = 'E';
			game->is_p_on_e = 0;
		}
		else
			game->map[y][x] = '0';
		if (i == 666)
			game->is_p_on_e = 1;
		game->start.x = x;
		game->start.y = y - 1;
		game->moves++;
		print_moves(game->moves);
	}
}

static void	move_down(t_game *game, int x, int y)
{
	int	i;

	if (!game || !game->map)
		return ;
	i = check_move(game, x, y + 1);
	if (i)
	{
		game->map[y + 1][x] = 'P';
		if (game->is_p_on_e == 1)
		{
			game->map[y][x] = 'E';
			game->is_p_on_e = 0;
		}
		else
			game->map[y][x] = '0';
		if (i == 666)
			game->is_p_on_e = 1;
		game->start.x = x;
		game->start.y = y + 1;
		game->moves++;
		print_moves(game->moves);
	}
}

static void	move_left(t_game *game, int x, int y)
{
	int	i;

	if (!game || !game->map)
		return ;
	i = check_move(game, x - 1, y);
	if (i)
	{
		game->map[y][x - 1] = 'P';
		if (game->is_p_on_e == 1)
		{
			game->map[y][x] = 'E';
			game->is_p_on_e = 0;
		}
		else
			game->map[y][x] = '0';
		if (i == 666)
			game->is_p_on_e = 1;
		game->start.x = x - 1;
		game->start.y = y;
		game->moves++;
		print_moves(game->moves);
	}
}

static void	move_right(t_game *game, int x, int y)
{
	int	i;

	if (!game || !game->map)
		return ;
	i = check_move(game, x + 1, y);
	if (i)
	{
		game->map[y][x + 1] = 'P';
		if (game->is_p_on_e == 1)
		{
			game->map[y][x] = 'E';
			game->is_p_on_e = 0;
		}
		else
			game->map[y][x] = '0';
		if (i == 666)
			game->is_p_on_e = 1;
		game->start.x = x + 1;
		game->start.y = y;
		game->moves++;
		print_moves(game->moves);
	}
}
