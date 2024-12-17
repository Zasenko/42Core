/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:05:44 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 13:54:57 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_size(char **arr, t_game *game);
static int	check_walls(char **arr, t_game *game);
static int	check_row(char *line);
static int	check_col(char **arr, int len, int col);

int	check_map(char *str_map, t_game *game)
{
	char	**arr;

	if (!str_map || !game)
		return (0);
	if (!check_str_map(str_map, game))
		return (0);
	arr = ft_split(str_map, '\n');
	if (!arr)
		return (0);
	if (!check_size(arr, game))
		return (print_error("Wrong size of the map."), free_str_arr(arr), 0);
	if (check_walls(arr, game) < 1)
		return (print_error("Invalid map."), free_str_arr(arr), 0);
	if (!check_path(game, arr))
		return (print_error("Invalid map."), free_str_arr(arr), 0);
	free_str_arr(arr);
	return (1);
}

static int	check_size(char **arr, t_game *game)
{
	int	i;

	i = 0;
	if (!arr || !arr[i] || !game)
		return (0);
	game->size.x = (int)ft_strlen(arr[i]);
	if (game->size.x < 3 || game->size.x > 38)
		return (0);
	while (arr[i])
	{
		if ((int)ft_strlen(arr[i]) != game->size.x)
			return (0);
		i++;
	}
	game->size.y = i;
	if (game->size.y < 3 || game->size.y > 18)
		return (0);
	return (1);
}

static int	check_walls(char **arr, t_game *game)
{
	if (!arr || !*arr || !game)
		return (-1);
	if (check_row(*arr) < 1 || check_row(arr[game->size.y - 1]) < 1)
		return (0);
	if (check_col(arr, game->size.x, 0) < 1
		|| check_col(arr, game->size.x, game->size.x - 1) < 1)
		return (0);
	return (1);
}

static int	check_row(char *line)
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

static int	check_col(char **arr, int len, int col)
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
