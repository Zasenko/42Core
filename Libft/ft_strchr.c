/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:40:53 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 12:57:50 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
// cc -Wall -Wextra -Werror libft.h ft_strchr.c
int	main(void)
{
	char str1[] = "Hello World";
	printf("Test 1: %s\n", ft_strchr(str1, 'o'));  // "o World"

	printf("Test 2: %s\n", ft_strchr(str1, 'H'));  // "Hello World"

	printf("Test 3: %p\n", ft_strchr(str1, 'x'));  // NULL

	printf("Test 4: %p\n", ft_strchr(str1, '\0')); // pointer to '\0'

	char str2[] = "";
	printf("Test 5: %p\n", ft_strchr(str2, 'a'));   // NULL

	printf("Test 6: %p\n", ft_strchr(str2, '\0'));  // pointer to '\0'

	char str3[] = "abacadae";
	printf("Test 7: %s\n", ft_strchr(str3, 'a'));  // "abacadae"

	char *null_str = NULL;
	printf("Test 8: %p\n", ft_strchr(null_str, 'a')); // NULL

	char str4[] = "abcdefg";
	printf("Test 9: %s\n", ft_strchr(str4, 'g'));  // "g"

	return (0);
}*/