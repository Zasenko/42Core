/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:31:36 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/11 13:35:07 by dzasenko         ###   ########.fr       */
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
int	main(void)
{
	char str1[] = "Hello";
	char str2[] = "Hello";
	printf("Test 1: %d\n", ft_strncmp(str1, str2, 5)); // Should return 0

	char str3[] = "Hello";
	char str4[] = "World";
	printf("Test 2: %d\n", ft_strncmp(str3, str4, 5));
		// Should return non-zero value

	char str5[] = "Hello";
	char str6[] = "Hell";
	printf("Test 3: %d\n", ft_strncmp(str5, str6, 4));
		// Should return 0 (only compare first 4 chars)
	printf("Test 3.1: %d\n", ft_strncmp(str5, str6, 5));
		// Should return non-zero (5th char differs)

	char str7[] = "";
	char str8[] = "Hello";
	printf("Test 4: %d\n", ft_strncmp(str7, str8, 5));
		// Should return negative value (empty string < non-empty string)

	printf("Test 5: %d\n", ft_strncmp(str1, str2, 0));
		// Should return 0 (since n = 0, no comparison is made)

	printf("Test 6: %d\n", ft_strncmp(str3, str4, 2));
		// Should return non-zero (since 'H' != 'W')

	char str9[] = "hello";
	printf("Test 7: %d\n", ft_strncmp(str1, str9, 5));
		// Should return non-zero (case-sensitive)

	return (0);
}*/