/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:47:27 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 11:45:22 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_str(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
	}
}

static void	free_images(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->t.c)
		mlx_destroy_image(game->mlx, game->t.c);
	if (game->t.e_c)
		mlx_destroy_image(game->mlx, game->t.e_c);
	if (game->t.e_o)
		mlx_destroy_image(game->mlx, game->t.e_o);
	if (game->t.g)
		mlx_destroy_image(game->mlx, game->t.g);
	if (game->t.p)
		mlx_destroy_image(game->mlx, game->t.p);
	if (game->t.w)
		mlx_destroy_image(game->mlx, game->t.w);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_str_arr(game->map);
	free_images(game);
	if (game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}
