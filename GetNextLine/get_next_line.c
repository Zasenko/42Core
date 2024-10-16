/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:13:39 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/14 14:13:16 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_srtdub(char *str)
{
	char	*dub;
	int		len;
	int		i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	dub = (char *)malloc(sizeof(char) * (len + 1));
	if (dub == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dub[i] = str[i];
		i++;
	}
	dub[i] = '\0';
	return (dub);
}

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

	// line = NULL;
	// new_buf = NULL;
	if (!buf || !*buf)
		return (NULL);
	line_len = ft_len_till_new_line(*buf);
	if (line_len < 0)
	{
		ft_free(buf);
		return (NULL);
	}
	line = (char *)malloc((sizeof(char) * line_len) + 1);
	if (line == NULL)
	{
		ft_free(buf);
		return (NULL);
	}
	line[0] = '\0';
	if (ft_strlcpy(line, *buf, line_len) == NULL)
	{
		ft_free(&line);
		ft_free(buf);
		return (NULL);
	}
	new_buf = ft_srtdub(*buf + line_len);
	ft_free(buf);
	if (new_buf == NULL)
	{
		ft_free(&line);
		return (NULL);
	}
	*buf = new_buf;
	return (line);
}

char	*ft_return_last_line(char **buf)
{
	char	*line;
	int		line_len;

	if (!buf || !*buf)
		return (NULL);
	line_len = ft_strlen(*buf);
	if (line_len > 0)
	{
		line = ft_srtdub(*buf);
		ft_free(buf);
		if (line == NULL)
			return (NULL);
		return (line);
	}
	else
	{
		ft_free(buf);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*buf;
	int			buf_count;
	int			f;
	char		*new_buf;
	int			new_buf_len;
	char		*new_new_buf;
	int			old_buf_len;

	f = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (buf == NULL)
	{
		buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
		if (buf == NULL)
			return (NULL);
		buf_count = read(fd, buf, sizeof(char) * BUFFER_SIZE);
		if (buf_count <= 0)
		{
			ft_free(&buf);
			return (NULL);
		}
		buf[buf_count] = '\0';
	}
	if (ft_is_new_line_in_buf(buf) == 1)
		f = 1;
	while (f == 0)
	{
		old_buf_len = ft_strlen(buf);
		new_buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
		if (new_buf == NULL)
		{
			ft_free(&buf);
			return (NULL);
		}
		new_buf_len = read(fd, new_buf, sizeof(char) * BUFFER_SIZE);
		if (new_buf_len < 0)
		{
			ft_free(&buf);
			ft_free(&new_buf);
			return (NULL);
		}
		if (new_buf_len == 0)
		{
			ft_free(&new_buf);
			return (ft_return_last_line(&buf));
		}
		else
		{
			new_buf[new_buf_len] = '\0';
			new_new_buf = (char *)malloc(sizeof(char) * (new_buf_len
						+ old_buf_len + 1));
			if (new_new_buf == NULL)
			{
				ft_free(&buf);
				ft_free(&new_buf);
				return (NULL);
			}
			new_new_buf[0] = '\0';
			if (ft_strlcpy(new_new_buf, buf, old_buf_len) == NULL)
			{
				ft_free(&buf);
				ft_free(&new_buf);
				return (NULL);
			}
			if (ft_strcat(new_new_buf, new_buf, new_buf_len) == NULL)
			{
				ft_free(&buf);
				ft_free(&new_buf);
				return (NULL);
			}
			if (ft_is_new_line_in_buf(new_buf) == 1)
				f = 1;
			ft_free(&buf);
			ft_free(&new_buf);
			buf = new_new_buf;
		}
	}
	return (ft_get_line(&buf));
}

// #include <fcntl.h>

// // cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line
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