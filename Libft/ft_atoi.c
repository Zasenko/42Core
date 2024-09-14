/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:03:10 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 12:52:22 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sing;
	int	result;

	i = 0;
	sing = +1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sing *= -1;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sing);
}
/*
//cc -Wall -Wextra -Werror ft_atoi.c
int	main(void)
{
	const char *test1 = "42";
	const char *test2 = "-42";
	const char *test3 = "   +123";
	const char *test4 = "   -123abc";
	const char *test5 = "0";
	const char *test6 = "-0";
	const char *test7 = "2147483647";
	const char *test8 = "-2147483648";
	const char *test9 = "   +2147483648";  // Overflow for int
	const char *test10 = "  \t\t ";

	printf("Test 1: '%s' -> %d\n", test1, ft_atoi(test1));
	printf("Test 2: '%s' -> %d\n", test2, ft_atoi(test2));
	printf("Test 3: '%s' -> %d\n", test3, ft_atoi(test3));
	printf("Test 4: '%s' -> %d\n", test4, ft_atoi(test4));
	printf("Test 5: '%s' -> %d\n", test5, ft_atoi(test5));
	printf("Test 6: '%s' -> %d\n", test6, ft_atoi(test6));
	printf("Test 7: '%s' -> %d\n", test7, ft_atoi(test7));
	printf("Test 8: '%s' -> %d\n", test8, ft_atoi(test8));
	printf("Test 9: '%s' -> %d\n", test9, ft_atoi(test9));// Overflow can vary
	printf("Test 10: '%s' -> %d\n", test10, ft_atoi(test10));  // 0
}*/