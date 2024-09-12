/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:43:56 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/11 17:14:17 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buff;

	buff = NULL;
	while (*s)
	{
		if (*s == (char)c)
			buff = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		buff = (char *)s;
	return (buff);
}
/*
int	main(void)
{
	char s[] = "Hello!";

	char *p1 = ft_strrchr(s, 'o');
	char *p2 = strrchr(s, 'o');

	char *p3 = ft_strrchr(s, '\0');
	char *p4 = strrchr(s, '\0');

	char *p5 = ft_strrchr(s, 'l');
	char *p6 = strrchr(s, 'l');

	char *p7 = ft_strrchr("", 'l');
	char *p8 = strrchr("", 'l');

	printf("%s\n", p1);
	printf("%s\n", p2);

	printf("%s\n", p3);
	printf("%s\n", p4);

	printf("%s\n", p5);
	printf("%s\n", p6);

	printf("%s\n", p7);
	printf("%s\n", p8);
}*/