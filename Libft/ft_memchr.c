/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:49:15 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 13:17:03 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_buff;
	unsigned char	c_buff;
	size_t			i;

	s_buff = (unsigned char *)s;
	c_buff = (unsigned char)c;
	i = 0;
	while (i++ < n)
	{
		if (*s_buff == c_buff)
			return ((void *)s_buff);
		s_buff++;
	}
	return (NULL);
}
/*
//cc -Wall -Wextra -Werror libft.h ft_memchr.c
int	main(void)
{
	char s[] = "Hello!";

	char *p1 = ft_memchr(s, '\0', 6);
	char *p2 = memchr(s, '\0', 6);

	char *p3 = ft_memchr(s, 'e', 6);
	char *p4 = memchr(s, 'e', 6);

	char *p5 = ft_memchr(s, 'o', 3);
	char *p6 = memchr(s, 'o', 3);

	printf("%s\n", p1);
	printf("%s\n", p2);

	printf("%s\n", p3);
	printf("%s\n", p4);

	printf("%s\n", p5);
	printf("%s\n", p6);
}*/