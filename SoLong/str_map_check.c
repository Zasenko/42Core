/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_map_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:58:07 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/27 10:20:09 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_char_map(char c);
static int	check_count(int e, int c, int p, t_game *game);

char	*make_map_str(char *str_map, char *line)
{
	char	*new_str;

	if (!line)
		return NULL;
	if (!str_map)
		str_map = "";
	new_str = ft_strjoin(str_map, line);
	if (!new_str)
		return NULL;
	return new_str;
}

char	**make_map(char *str_map)
{
	char	**arr;

	if (!str_map)
		return (NULL);	
	arr = ft_split(str_map, '\n');
	if (!arr)
		return (NULL);
	return (arr);
}

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
			return (0);
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
			return 1;
		s++;
	}
	return 0;
}

static int	check_count(int e, int c, int p, t_game *game)
{
	if (!game)
		return (-1);
	if (e != 1 || p != 1 || c < 1)
		return (0);
	game->coins_count = c;
	game->exit_count = 1;
	return (1);
}
