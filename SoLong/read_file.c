/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:03:09 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/27 10:55:10 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	char	*s_new;
	size_t	i;
	size_t	f;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	s_new = (char *)malloc((l + 1) * sizeof(char));
	if (s_new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_new[i] = s1[i];
		i++;
	}
	f = 0;
	while (s2[f])
	{
		s_new[i++] = s2[f++];
	}
	s_new[i] = '\0';
	return (s_new);
}

void	free_str_arr(char **arr)
{
	int i;
	
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

int	str_arr_count(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (-1);
	while (arr[i])
		i++;
	return (i);
}

int ft_read_file(char *file_name, t_game *game)
{
    char	*line;
	int		fd;
	char	*str_map;

	str_map = NULL;
    if (!file_name || !game)
    {
        return 0;
    }
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
        return 0;
	while ((line = get_next_line(fd)) != NULL)
    {
        char *new_str = make_map_str(str_map, line);
        ft_free(&line);
        if (!new_str)
        {
            ft_free(&str_map);
            close(fd);
            return 0;
        }
        ft_free(&str_map);
        str_map = new_str;
    }
    // if (!check_str_map(str_map, game))
    // {
	// 	ft_free(&str_map);
	// 	return 0;
    // }
    
	if (!check_map(str_map, game))
	{
		ft_free(&str_map);
		return 0;
	}
	char **map = make_map(str_map);
	if (!map)
	{
		ft_free(&str_map);
		return 0;
	}
	game->map = map;

	ft_free(&str_map);

	if (close(fd) == -1)
        return 0;
	return 1;
}
