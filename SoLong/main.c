/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:03:36 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 15:02:39 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int key, t_game *game)
{
	if (!game)
		return (0);
	if (key == 65307)
		free_game(game);
	else if (key == 97 || key == 65361)
		move(game, 2);
	else if (key == 100 || key == 65363)
		move(game, 3);
	else if (key == 115 || key == 65364)
		move(game, 4);
	else if (key == 119 || key == 65362)
		move(game, 1);
	if (game->is_finish)
		finish_game(game);
	return (1);
}

int	set_window(t_game *game)
{
	int		size_x;
	int		size_y;
	char	*title;

	if (!game)
		return (0);
	size_x = game->img_size * game->size.x;
	size_y = game->img_size * game->size.y;
	title = "Simpsons game";
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	if (!make_textures(game))
		return (0);
	game->win = mlx_new_window(game->mlx, size_x, size_y, title);
	if (!game->win)
		return (0);
	if (!make_img(game))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;
	char	*file_name;

	if (ac != 2)
		return (0);
	file_name = av[1];
	if (!file_name)
		return (0);
	if (!set_new_game(&game))
		free_game(&game);
	if (!make_map(file_name, &game))
		free_game(&game);
	if (!set_window(&game))
		free_game(&game);
	if (!mlx_hook(game.win, 17, 0, &close_window, &game))
		free_game(&game);
	if (!mlx_key_hook(game.win, &on_keypress, &game))
		free_game(&game);
	if (!mlx_loop(game.mlx))
		free_game(&game);
	free_game(&game);
	return (0);
}
