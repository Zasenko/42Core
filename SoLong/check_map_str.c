/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:58:07 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 13:43:06 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_char_map(char c);
static int	check_count(int e, int c, int p, t_game *game);

int	check_str_map(char *map, t_game *game)
{
	int	i;
	int	e;
	int	c;
	int	p;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	if (!map || !game)
		return (-1);
	while (map[i])
	{
		if (check_char_map(map[i]) == 0)
			return (print_error("Wrong simbol on map."), 0);
		if (map[i] == 'C')
			c++;
		else if (map[i] == 'E')
			e++;
		else if (map[i] == 'P')
			p++;
		i++;
	}
	return (check_count(e, c, p, game));
}

static int	check_char_map(char c)
{
	char	*s;

	s = "01CEP\n";
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static int	check_count(int e, int c, int p, t_game *game)
{
	if (!game)
		return (-1);
	if (e < 1)
		return (print_error("Exit on map not found."), 0);
	if (e > 1)
		return (print_error("Too many exits on map."), 0);
	if (p < 1)
		return (print_error("Player on map not found."), 0);
	if (p > 1)
		return (print_error("Too many players on map."), 0);
	if (c < 1)
		return (print_error("Collectable on map not found."), 0);
	game->coins_count = c;
	game->map_check.coins_count = c;
	game->map_check.exit_count = 1;
	return (1);
}
