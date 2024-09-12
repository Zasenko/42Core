/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:46:43 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/11 17:14:52 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	f;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		f = 0;
		while (big[i + f] != '\0' && (i + f) < len && big[i + f] == little[f])
		{
			f++;
			if (little[f] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <bsd/string.h>

int	main(void)
{
	char	s[] = "Hello, World!";
	char	f1[] = "World";
	char	f2[] = "Hello";
	char	f3[] = "";
	char	f4[] = "!";
	char	f5[] = "Nonexistent";

	printf("1 %s\n", ft_strnstr(s, f1, 13));
	printf("1 %s\n", ft_strnstr(s, f1, 0));
	printf("2 %s\n", ft_strnstr(s, f2, 5));
	printf("3 %s\n", ft_strnstr(s, f3, 13));
	printf("4 %s\n", ft_strnstr(s, f4, 13));
	printf("5 %s\n", ft_strnstr(s, f5, 13));
	printf("6 %s\n", ft_strnstr(s, f1, 5));
	printf("7 %s\n", ft_strnstr(s, "Hell", 4));
	printf("8 %s\n", ft_strnstr(NULL, f1, 5));
	printf("9 %s\n", ft_strnstr(s, NULL, 5));
	printf("1 %s\n", strnstr(s, f1, 13));
	printf("1 %s\n", strnstr(s, f1, 0));
	printf("2 %s\n", strnstr(s, f2, 5));
	printf("3 %s\n", strnstr(s, f3, 13));
	printf("4 %s\n", strnstr(s, f4, 13));
	printf("5 %s\n", strnstr(s, f5, 13));
	printf("6 %s\n", strnstr(s, f1, 5));
	printf("7 %s\n", strnstr(s, "Hell", 4));
	printf("8 %s\n", strnstr(NULL, f1, 5));
	printf("9 %s\n", strnstr(s, NULL, 5));
}*/