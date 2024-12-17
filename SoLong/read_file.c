/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:03:09 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 15:14:09 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file_name(char *file_name);
static char	*read_file(int fd);
static int	allocate(char **buf, char **str);

int	make_map(char *file_name, t_game *game)
{
	int		fd;
	char	*str_map;

	if (!file_name || !check_file_name(file_name) || !game)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (print_error("Can not open Map file."), 0);
	str_map = read_file(fd);
	if (!str_map)
		return (close(fd), 0);
	if (!check_map(str_map, game))
		return (free_str(&str_map), close(fd), 0);
	game->map = ft_split(str_map, '\n');
	free_str(&str_map);
	if (!game->map)
		return (close(fd), 0);
	if (close(fd) == -1)
		return (0);
	return (1);
}

static int	check_file_name(char *file_name)
{
	size_t	len;

	if (!file_name)
		return (0);
	len = ft_strlen(file_name);
	if (len < 4)
		return (0);
	if (ft_strnstr(&file_name[len - 4], ".ber", 4) == NULL)
		return (print_error("Map file is not .ber"), 0);
	return (1);
}

static char	*read_file(int fd)
{
	char	*str;
	char	*buf;
	char	*temp;
	int		buf_count;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!allocate(&buf, &str))
		return (NULL);
	buf_count = read(fd, buf, sizeof(char) * BUFFER_SIZE);
	while (buf_count > 0)
	{
		buf[buf_count] = '\0';
		temp = ft_strjoin(str, buf);
		if (!temp)
			return (free_str(&buf), free_str(&str), NULL);
		free_str(&str);
		str = temp;
		buf_count = read(fd, buf, sizeof(char) * BUFFER_SIZE);
	}
	if (buf_count < 0)
		return (free_str(&buf), free_str(&str), NULL);
	return (free_str(&buf), str);
}

static int	allocate(char **buf, char **str)
{
	if (!buf || !str || BUFFER_SIZE <= 0)
		return (0);
	*buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (*buf == NULL)
		return (0);
	*str = (char *)malloc(sizeof(char));
	if (*str == NULL)
		return (free_str(buf), 0);
	(*str)[0] = '\0';
	return (1);
}
