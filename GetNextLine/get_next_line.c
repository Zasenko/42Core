/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:13:39 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/15 14:01:23 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

char	*ft_get_line(char **buf)
{
	char	*line;
	int		line_len;
	char	*new_buf;

	if (!buf || !*buf)
		return (NULL);
	line_len = nl_l(*buf, 1);
	if (line_len < 0)
		return (ft_free(buf), NULL);
	line = (char *)malloc((sizeof(char) * line_len) + 1);
	if (line == NULL)
		return (ft_free(buf), NULL);
	line[0] = '\0';
	if (ft_strlcpy(line, *buf, line_len) == NULL)
		return (ft_free(&line), ft_free(buf), NULL);
	new_buf = ft_srtdub(*buf + line_len);
	ft_free(buf);
	if (new_buf == NULL)
		return (ft_free(&line), NULL);
	*buf = new_buf;
	return (line);
}

char	*ft_return_last_line(char **buf)
{
	char	*line;
	int		line_len;

	if (!buf || !*buf)
		return (NULL);
	line_len = nl_l(*buf, 0);
	if (line_len > 0)
	{
		line = ft_srtdub(*buf);
		ft_free(buf);
		if (line == NULL)
			return (NULL);
		return (line);
	}
	ft_free(buf);
	return (NULL);
}

int	ft_add_from_buf(int fd, char **buf)
{
	int		tbl;
	char	*tb;
	char	*nb;

	tb = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (tb == NULL)
		return (ft_free(buf), -1);
	tbl = read(fd, tb, sizeof(char) * BUFFER_SIZE);
	if (tbl < 0)
		return (ft_free(buf), ft_free(&tb), -1);
	if (tbl == 0)
		return (ft_free(&tb), 1);
	else
	{
		tb[tbl] = '\0';
		nb = (char *)malloc(sizeof(char) * (tbl + nl_l(*buf, 0) + 1));
		if (nb == NULL)
			return (ft_free(buf), ft_free(&tb), -1);
		if (!ft_strlcpy(nb, *buf, nl_l(*buf, 0)) || !ft_strcat(nb, tb, tbl))
			return (ft_free(buf), ft_free(&tb), -1);
		ft_free(buf);
		ft_free(&tb);
		*buf = nb;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	int			buf_count;
	int			res;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (buf == NULL)
	{
		buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
		if (buf == NULL)
			return (NULL);
		buf_count = read(fd, buf, sizeof(char) * BUFFER_SIZE);
		if (buf_count <= 0)
			return (ft_free(&buf), NULL);
		buf[buf_count] = '\0';
	}
	while (ft_is_new_line_in_buf(buf) == 0)
	{
		res = ft_add_from_buf(fd, &buf);
		if (res == 1)
			return (ft_return_last_line(&buf));
		if (res < 0)
			return (NULL);
	}
	return (ft_get_line(&buf));
}

// #include <fcntl.h>

// // cc -Wall -Wextra -Werror -D BUFFER_SIZE=1
// int	main(void)
// {
// 	char	*c;
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("open error\n");
// 		return (1);
// 	}
// 	while ((c = get_next_line(fd)) != NULL)
// 	{
// 		printf("\n----- NEW LINE -----\n");
// 		printf("%s", c);
// 		free(c);
// 	}
// 	close(fd);
// 	return (0);
// }