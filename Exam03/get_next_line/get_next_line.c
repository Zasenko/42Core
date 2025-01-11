
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 0
#endif

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void free_str(char **str)
{
	if (!str)
		return;
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

int ft_strlen(char *s)
{
	int i = 0;
	if (!s)
		return i;
	while(s[i])
		i++;
	return i;
}

int if_nl_in_buff(char *buffer)
{
	if (!buffer)
		return -1;

	int i = 0;
	while(buffer[i])
	{
		if (buffer[i] == '\n')
		{
			return (++i);
		}
		i++;
	}
	return 0;
}

char *ft_strjoin(char *s1, char *s2)
{
	if (!s1 || !s2)
		return NULL;

	int s1_size = ft_strlen(s1);
	int s2_size = ft_strlen(s2);
	int size = s1_size + s2_size;
	char *new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return NULL;
	int i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	int j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return new;
}

int size_till_nl(char *s)
{
	if (!s)
		return -1;
	int i = 0;
	while(s[i])
	{
		if (s[i] == '\n')
		{
			return (++i);
		}
		i++;
	}
	return -1;
}


char *get_next_line(int fd)
{
	

	static char *buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return free_str(&buffer), NULL;

	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return NULL;
		int read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			return free_str(&buffer), NULL;
		buffer[read_size] = '\0';
	}

	int nl_result = if_nl_in_buff(buffer);
	if (nl_result == -1)
		return free_str(&buffer), NULL;
	while(!nl_result)
	{
		char *new_text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!new_text)
			return free_str(&buffer), NULL;
		int read_size = read(fd, new_text, BUFFER_SIZE);
		if (read_size < 0)
			return free_str(&new_text),free_str(&buffer), NULL;
		else if (read_size == 0)
		{
			free_str(&new_text);
			int last_line_size = ft_strlen(buffer);
			if (last_line_size < 1)
				return free_str(&buffer), NULL;

			char *last_line = malloc(sizeof(char) * (last_line_size + 1));
			if (!last_line)
				return free_str(&buffer), NULL;

			int i = 0;
			while(i < last_line_size)
			{
				last_line[i] = buffer[i];
				i++;
			}
			last_line[last_line_size] = '\0';
			free_str(&buffer);
			return last_line;
		}
		new_text[read_size] = '\0';

		char *new_buff = ft_strjoin(buffer, new_text);
		if (!new_buff)
		{
			free_str(&buffer);
			free_str(&new_text);
			return NULL;
		}
		free_str(&buffer);
		free_str(&new_text);
		buffer = new_buff;
		nl_result = if_nl_in_buff(buffer);
		if (nl_result == -1)
			return free_str(&buffer), NULL;
	}


	int line_size = size_till_nl(buffer);
	if (line_size < 1)
		return free_str(&buffer), NULL;

	char *line = malloc(sizeof(char) * (line_size + 1));
	if (!line)
		return free_str(&buffer), NULL;

	int i = 0;
	while(i < line_size)
	{
		line[i] = buffer[i];
		i++;
	}
	line[line_size] = '\0';

	int new_size = ft_strlen(buffer + i);
	if (new_size < 1)
	{
		return free_str(&buffer), line;
	}
	char *new_buff = ft_strjoin(buffer + i, "");
	if (!new_buff)
		return free_str(&buffer), free_str(&line), NULL;
	free_str(&buffer);
	buffer = new_buff;
	return line;
}

// int main(void)
// {

// 	int fd = open("file", O_RDONLY);
// 	if (fd < 1)
// 	{
// 		printf("open error\n");
// 		return 1;
// 	}

// 	char *line = get_next_line(fd);
// 	while(line)
// 	{
// 		printf("%s",line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}

// 	close(fd);
// 	return 0;
// }