/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:31:36 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 12:45:59 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
// cc -Wall -Wextra -Werror libft.h ft_strncmp.c
int	main(void)
{
	char str1[] = "Hello";
	char str2[] = "Hello";
	printf("Test 1: %d\n", ft_strncmp(str1, str2, 5));
	printf("Test 1: %d\n", strncmp(str1, str2, 5));
	printf("------------------\n");

	char str3[] = "Hello";
	char str4[] = "World";
	printf("Test 2: %d\n", ft_strncmp(str3, str4, 5));
	printf("Test 2: %d\n", strncmp(str3, str4, 5));
	printf("------------------\n");

	char str5[] = "Hello";
	char str6[] = "Hell";
	printf("Test 3: %d\n", ft_strncmp(str5, str6, 4));
	printf("Test 3: %d\n", strncmp(str5, str6, 4));
	printf("------------------\n");

	printf("Test 3.1: %d\n", ft_strncmp(str5, str6, 5));
	printf("Test 3.1: %d\n", strncmp(str5, str6, 5));
	printf("------------------\n");

	char str7[] = "";
	char str8[] = "Hello";
	printf("Test 4: %d\n", ft_strncmp(str7, str8, 5));
	printf("Test 4: %d\n", strncmp(str7, str8, 5));
	printf("------------------\n");

	printf("Test 5: %d\n", ft_strncmp(str1, str2, 0));
	printf("Test 5: %d\n", strncmp(str1, str2, 0));
	printf("------------------\n");

	printf("Test 6: %d\n", ft_strncmp(str3, str4, 2));
	printf("Test 6: %d\n", strncmp(str3, str4, 2));
	printf("------------------\n");

	char str9[] = "hello";
	printf("Test 7: %d\n", ft_strncmp(str1, str9, 5));
	printf("Test 7: %d\n", strncmp(str1, str9, 5));
	return (0);
}*/