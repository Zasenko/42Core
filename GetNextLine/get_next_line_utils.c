#include "get_next_line.h"

void ft_strcat(char *s1, char *s2, int n)
{
	int i = 0;
	int l = 0;

	if (!s1 || !s2)
		return ;
	while (s1[i])
		i++;
	while (s2[l] && n-- > 0)
	{
		s1[i] = s2[l];
		i++;
		l++;
	}
	s1[i] = '\0';
}

void	ft_strlcpy(char *dest, char *src, int n)
{
	if (!src)
		return ;
	if (n <= 0)
		return ;
	int i = 0;
	while (src[i] && n-- > 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_len_till_new_line(char *str)
{
	int	count;
	int	i;

	if (!str)
		return (-1);
	count = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		count++;
		i++;
	}
	if (str[i] == '\n')
		count++;
	return (count);
}

int	ft_is_new_line_in_buf(char *str)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
