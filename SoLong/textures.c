/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:13:57 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 12:01:35 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	make_t(void **texture, void *mlx, char *filename, int img_size);

int	make_textures(t_game *game)
{
	int	size;

	if (!game || !game->mlx)
		return (0);
	size = game->img_size;
	if (!make_t((void **)&game->t.c, game->mlx, "textures/c.xpm", size))
		return (0);
	if (!make_t((void **)&game->t.p, game->mlx, "textures/p.xpm", size))
		return (0);
	if (!make_t((void **)&game->t.w, game->mlx, "textures/w.xpm", size))
		return (0);
	if (!make_t((void **)&game->t.g, game->mlx, "textures/g.xpm", size))
		return (0);
	if (!make_t((void **)&game->t.e_c, game->mlx, "textures/e_c.xpm", size))
		return (0);
	if (!make_t((void **)&game->t.e_o, game->mlx, "textures/e_o.xpm", size))
		return (0);
	return (1);
}

static int	make_t(void **texture, void *mlx, char *filename, int img_size)
{
	int	width;
	int	height;

	if (!texture || !mlx || !filename)
		return (0);
	width = 0;
	height = 0;
	*texture = mlx_xpm_file_to_image(mlx, filename, &width, &height);
	if (!(*texture))
		return (0);
	if (width != img_size || height != img_size)
		return (0);
	return (1);
}
