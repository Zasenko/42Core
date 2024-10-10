#include "get_next_line.h"

void	ft_strcat(char *s1, char *s2, int n)
{
	// printf("--- ft_strcat(s1: %s, s2: %s)\n", s1, s2);
	while (*s1)
		s1++;
	while (*s2 && n-- > 0)
		*s1++ = *s2++;
	*s1 = '\0';
}

void	ft_strcpy(char *dest, char *src)
{
	// printf("--- ft_strcpy(dest: %s, src: %s)\n", dest, src);
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}

void	ft_strlcpy(char *dest, char *src, int n)
{
	if (n <= 0)
		return ;
	// printf("--- ft_strlcpy(dest: %s, src: %s, n: %d)\n", dest, src, n);
	while (*src && n-- > 0)
		*dest++ = *src++;
	*dest = '\0';
}

int	ft_len_till_new_line(char *str)
{
	int	count;

	count = 0;
	while (*str && *str != '\n')
	{
		count++;
		str++;
	}
	if (*str == '\n')
		count++;
	return (count);
}

int	ft_is_new_line_in_buf(char *str)
{
	while (*str)
	{
		if (*str == '\n')
		{
			return (1);
		}
		str++;
	}
	return (0);
}