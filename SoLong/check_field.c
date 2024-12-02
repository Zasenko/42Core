/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:05:44 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/27 10:52:58 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	chech_row(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	chech_col(char **arr, int len, int col)
{
	int	i;

	i = 0;
	if (!arr || !*arr || len < 3)
		return (-1);
	while (arr[i] && len--)
	{
		if (arr[i][col] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int chech_walls(char **arr, t_game *game)
{
	if (!arr || !*arr || !game)
		return (-1);
	if (chech_row(*arr) < 1 || chech_row(arr[game->size.y - 1]) < 1)
		return (0);
	if (chech_col(arr, game->size.x, 0) < 1 || chech_col(arr, game->size.x, game->size.x - 1) < 1)
		return (0);
	return 1;
}

static int chech_size(char **arr, t_game *game)
{
	int i;

	i = 0;
	if (!arr || !arr[i] || !game)
		return (-1);
	game->size.x = (int)ft_strlen(arr[i]);
	if (game->size.x < 3)
		return (0);
	while (arr[i])
	{
		if ((int)ft_strlen(arr[i]) != game->size.x)
			return (0);
		i++;
	}
	game->size.y = i;
	if (game->size.y < 3)
		return (0);
	return 1;
}

int check_map(char *str_map, t_game *game)
{
	char	**arr;

	if (!str_map)
		return (0);
	if (!check_str_map(str_map, game))
    {
		return 0;
    }
	arr = ft_split(str_map, '\n');
	if (!arr)
		return (0);
	if (chech_size(arr, game) < 1 || chech_walls(arr, game) < 1)
	{
		printf("ERROR size or walls\n");
		return (free_str_arr(arr) ,0);
	}
	if (!check_path(game, arr))
	{
		printf("\n---- ERROR path -----\n");
		return (free_str_arr(arr), 0);
	}
	free_str_arr(arr);
	return (1);
}

// char	**make_map(char *str_map, t_game *game)
// {
// 	char	**arr;

// 	if (!str_map)
// 		return (NULL);	
// 	arr = ft_split(str_map, '\n');
// 	if (!arr)
// 		return (NULL);
// 	if (chech_size(arr, game) < 1 || chech_walls(arr, game) < 1)
// 	{
// 		printf("ERROR size or walls\n");
// 		return (free_str_arr(arr) ,NULL);
// 	}
// 	if (!check_path(game, arr))
// 	{
// 		free_str_arr(arr);
// 		printf("\n---- ERROR path -----\n");
// 		return NULL;
// 	}
// 	return (arr);
// }