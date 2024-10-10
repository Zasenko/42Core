/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:13:39 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/09 15:44:45 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	buf_count;

	char	*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 255)
	{
		return (NULL);
	}
	if (buf == NULL)
	{
		buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
		if (buf == NULL)
			return (NULL);
		buf_count = read(fd, buf, sizeof(char) * BUFFER_SIZE);
	}
	if (buf_count <= 0)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	else
	{
		if (ft_is_new_line_in_buf(buf) == 1)
		{
			// printf("new line simb in buf found\n");
			// printf("---buf: %s---\n", buf);
			int line_len = ft_len_till_new_line(buf);
			// printf("first line in buf (len with \\n): %d\n", line_len);
			line = (char *)malloc((sizeof(char) * line_len) + 1);
			if (line == NULL)
			{
				// printf("ERROR creationg new line\n");
				// printf("- free: buf\n");
				free(buf);
				buf = NULL;
				return (NULL);
			}
			// printf("+ Allocete: line\n");
			ft_strlcpy(line, buf, line_len);
			// printf("--- line after: %s---\n", line);
			ft_strcpy(buf, buf + line_len);
			// printf("--- sizeof(buf): %lu---\n", sizeof(buf));
			// printf("--- size buf: %d---\n", buf_count);
			printf("!!!!!!!!!!!!!!!!!!--%s--\n", line);
			return (line);
		}
		else
		{
			// printf("new line simb in buf NOT found\n");
			// printf("---buf: %s---\n", buf);

			int old_buf_len = ft_len_till_new_line(buf);
			// printf("old_buf_len: %d\n", old_buf_len);
			
			char	*new_buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
			if (new_buf == NULL)
			{
				// printf("ERROR creationg new_buf\n");
				// printf("- free: buf\n");
				free(buf);
				buf = NULL;
				return (NULL);
			}
			// printf("+ Allocete: new_buf\n");
			int new_buf_len = read(fd, new_buf, sizeof(char) * BUFFER_SIZE);
			// printf("---new_buf: %s---\n", new_buf);
			// printf("new_buf_len: %d\n", new_buf_len);
			if (new_buf_len < 0)
			{
				// printf("new_buf_len < 0, free(buf)\n");
				// printf("- free: new_buf\n");
				// printf("- free: buf\n");
				free(new_buf);
				free(buf);
				new_buf = NULL;
				buf = NULL;
				return (NULL);
			}
			if (new_buf_len == 0)
			{
				int line_len = ft_len_till_new_line(buf);
				// printf("last line_len: %d\n", line_len);
				if (line_len > 0)
				{
					line = (char *)malloc((sizeof(char) * line_len) + 1);
					if (line == NULL)
					{
						printf("ERROR creationg last line\n");
						printf("- free: new_buf\n");
						printf("- free: buf\n");
						free(new_buf);
						free(buf);
						new_buf = NULL;
						buf = NULL;
						return (NULL);
					}
					// printf("+ Allocete: last line\n");
					ft_strlcpy(line, buf, line_len);
					// printf("--- last line after: %s---\n", line);
					// printf("--- buf after: %s---\n", buf);


					// printf("- free: new_buf\n");
					// printf("- free: buf\n");
					free(new_buf);
					free(buf);
					new_buf = NULL;
					buf = NULL;
					printf("!!!!!!!!!!!!!!!!!!--%s--\n", line);
					return (line);	
				}
				else
				{
					// printf("new_buf_len < 0, free(buf)\n");
					// printf("- free: new_buf\n");
					// printf("- free: buf\n");
					free(new_buf);
					free(buf);
					new_buf = NULL;
					buf = NULL;
					return (NULL);
				}
			}
			
			char *new_new_buf = (char *)malloc(sizeof(char) * (new_buf_len + old_buf_len + 1));
			if (new_new_buf == NULL)
			{
				// printf("ERROR creationg new_new_buf\n");
				// printf("- free: new_buf\n");
				// printf("- free: buf\n");
				free(buf);
				buf = NULL;
				free(new_buf);
				new_buf = NULL;
				return (NULL);
			} else {
			// printf("+ Allocete: new_new_buf\n");

			ft_strcpy(new_new_buf, buf);
			// printf("--- new_new_buf after: %s---\n", new_new_buf);

			ft_strcat(new_new_buf, new_buf, new_buf_len);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			// printf("--- new_new_buf after: %s---\n", new_new_buf);

			// printf("- free: new_buf\n");
			// printf("- free: buf\n");
			free(new_buf);
			free(buf);
			new_buf = NULL;
			buf = NULL;
			
			buf = new_new_buf;
			buf_count = new_buf_len + old_buf_len;
			// printf("--- buf: %s---\n", buf);
			// printf("buf_count: %d\n", buf_count);
			// printf("!!!!!!get_next_line()\n");
			return (get_next_line(fd));
			}
		}
	}
}

#include <fcntl.h>

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=4 get_next_line.c
int	main(void)
{
	char	*c;
	int		fd;

	fd = open("text.txt", O_RDONLY | O_CREAT);
	if (fd == -1)
	{
		printf("open error\n");
		return (1);
	}
	printf("\n----- NEW LINE -----\n");
	c = get_next_line(fd);
	printf("\n----------\n");
	printf("%s", c);
	if (c)
		free(c);
	
	printf("\n----- NEW LINE -----\n");
	c = get_next_line(fd);
	printf("\n----------\n");
	printf("%s", c);
	if (c)
		free(c);

	printf("\n----- NEW LINE -----\n");
	c = get_next_line(fd);
	printf("\n----------\n");
	printf("%s", c);
	if (c)
		free(c);

	printf("\n----- NEW LINE -----\n");
	c = get_next_line(fd);
	printf("\n----------\n");
	printf("%s", c);
	if (c)
		free(c);
	
	printf("\n----- NEW LINE -----\n");
	c = get_next_line(fd);
	printf("\n----------\n");
	printf("%s", c);
	if (c)
		free(c);
	
	printf("\n----- NEW LINE -----\n");
	c = get_next_line(fd);
	printf("\n----------\n");
	printf("%s", c);
	if (c)
		free(c);
	
	printf("\n----- NEW LINE -----\n");
	c = get_next_line(fd);
	printf("\n----------\n");
	printf("%s", c);
	if (c)
		free(c);
	printf("\n----- NEW LINE -----\n");
	c = get_next_line(fd);
	printf("\n----------\n");
	printf("%s", c);
	if (c)
		free(c);
	
	printf("\n----- NEW LINE -----\n");
	c = get_next_line(fd);
	printf("\n----------\n");
	printf("%s", c);
	if (c)
		free(c);

	printf("\n----- NEW LINE -----\n");
	c = get_next_line(fd);
	printf("\n----------\n");
	printf("%s", c);
	if (c)
		free(c);

	printf("\n----- NEW LINE -----\n");
	c = get_next_line(fd);
	printf("\n----------\n");
	printf("%s", c);
	if (c)
		free(c);
	
	if (close(fd) < 0)
	{
		printf("close error\n");
		exit(1);
	}
	printf("closed the fd.\n");
	return (0);
}