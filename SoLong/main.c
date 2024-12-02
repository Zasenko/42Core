/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:03:36 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/27 16:37:11 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	free_images(t_game *game)
{
	printf("free_images\n");
	if (!game)
		return ;
	printf("free_images2\n");
	if (game->textures.c)
	{
		mlx_destroy_image(game->mlx, game->textures.c);
		//game->textures.c = NULL;
	//	printf("c: %p\n", game->textures.c);
	}
	printf("free_images3\n");

	if (game->textures.e_c)
	{
		mlx_destroy_image(game->mlx, game->textures.e_c);
		///printf("e_c: %p\n", game->textures.e_c);
	}
	if (game->textures.e_o)
	{
		mlx_destroy_image(game->mlx, game->textures.e_o);
		//printf("e_o: %p\n", game->textures.e_o);
	}
	if (game->textures.g)
	{
		mlx_destroy_image(game->mlx, game->textures.g);
		//printf("g: %p\n", game->textures.g);
	}
	if (game->textures.p)
	{
		mlx_destroy_image(game->mlx, game->textures.p);
		//printf("p: %p\n", game->textures.p);
	}
	if (game->textures.w)
	{
		mlx_destroy_image(game->mlx, game->textures.w);
		//printf("w: %p\n", game->textures.w);
	}
	
	printf("free_images10\n");

	// mlx_destroy_image(game->mlx, game->textures.c);
	// mlx_destroy_image(game->mlx, game->textures.e_c);
	// mlx_destroy_image(game->mlx, game->textures.e_o);
	// mlx_destroy_image(game->mlx, game->textures.g);
	// mlx_destroy_image(game->mlx, game->textures.p);
	// mlx_destroy_image(game->mlx, game->textures.w);
}

void free_game(t_game *game)
{
	printf("------  free game --------\n");
	if (!game)
		return ;
	if (game->map)
	{
		printf("free game->map\n");
		free_str_arr(game->map);
		game->map = NULL;
		printf("map: %p\n", game->map);
	}
	// free_images(game);
	// if (game->mlx)
	// {
	// 	if (game->win)
	// 	{
	// 		printf("free win\n");
	// 		mlx_destroy_window(game->mlx, game->win);
	// 		game->win = NULL;
	// 		printf("win: %p\n", game->win);
	// 	}
	// 	mlx_destroy_display(game->mlx);
	// 	free(game->mlx);
	// 	game->mlx = NULL;
	// 	printf("free mlx\n");
	// 	printf("mlx: %p\n", game->mlx);

	// }
}

int on_keypress(int key, t_game *game)
{
    if (key == 65307)
	{
		free_game(game);
		printf("ESCAPE\n");
	}
    else if (key == 97 || key == 65361)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->textures.p, 0, 0);
        printf("LEFT\n");
	}
    else if (key == 100 || key == 65363)
        printf("RIGHT\n");
    else if (key == 115 || key == 65364)
        printf("DOWN\n");
    else if (key == 119 || key == 65362)
        printf("UP\n");
    else
        printf("%d\n", key);
    return (0);
}

int close_window(int key, t_game *game)
{
	printf("Pressed X - key: %d\n", key);
	free_game(game);
	return (0);
}

int make_img(t_game *game, int size)
{
	if (!game || !game->map || !game->mlx || !game->win)
	{
		printf("Error make_img\n");
		return (0);
	}
	int y = 0;
	while (game->map[y])
	{
		int x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->textures.w, x * size, y * size);
			}
			else if (game->map[y][x] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->textures.g, x * size, y * size);
			}
			else if (game->map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->textures.c, x * size, y * size);
			}
			else if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->textures.p, x * size, y * size);
			}
			else if (game->map[y][x] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->textures.e_c, x * size, y * size);
			}
			x++;
		}
		y++;
	}
	return 1;
}

int	main(int ac, char **av)
{
	t_game game;

	int size;
	
	size = 60;
	if (ac != 2)
	{
		printf("Error ac\n");
		return (0);
	}
	char *file_name = av[1];
	if (!file_name)
	{
		printf("Error file_name\n");
		return (0);
	}
	// if (ft_strlen(file_name) < 4) //TODO check .ber
	// {
	// 	printf("Error\n");
	// 	return (0);
	// }
	if (!ft_read_file(file_name, &game))
	{
		free_game(&game);
		return 1;
	}
	


	game.mlx = mlx_init();
	if (!game.mlx)
	{
		printf("ERROR MAKE MLX\n");
		free_game(&game);
		return 1;
	}

	game.textures.c = mlx_xpm_file_to_image(game.mlx, "textures/donut.xpm", &size, &size);
	game.textures.p = mlx_xpm_file_to_image(game.mlx, "textures/homer.xpm", &size, &size);
	game.textures.w = mlx_xpm_file_to_image(game.mlx, "textures/wall.xpm", &size, &size);
	game.textures.g = mlx_xpm_file_to_image(game.mlx, "textures/ground.xpm", &size, &size);
	game.textures.e_c = mlx_xpm_file_to_image(game.mlx, "textures/exit_c.xpm", &size, &size);
	
	game.win = mlx_new_window(game.mlx, size * game.size.x, size * game.size.y, "Hello world!");
	if (!game.win)
	{
		printf("ERROR MAKE WIN\n");
		free_game(&game);
		return 1;
	}

	if (!make_img(&game, size))
	{
		printf("ERROR MAKE IMG\n");
		free_game(&game);
		return 1;
	}
    mlx_hook(game.win, 2, 1L << 0, on_keypress, &game);
	mlx_hook(game.win, 17, 1L << 0, close_window, &game);
	mlx_loop(game.mlx);
	
	free_game(&game);
	return 0;
}
