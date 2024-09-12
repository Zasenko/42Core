/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:03:13 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/10 09:49:01 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_buff;
	unsigned char	*s2_buff;
	size_t			i;

	s1_buff = (unsigned char *)s1;
	s2_buff = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_buff[i] != s2_buff[i])
			return ((int)s1_buff[i] - (int)s2_buff[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char s1[] = "Dima";
	char s2[] = "Dima";

	char s3[] = "Diaa";
	char s4[] = "Dima";

	char s5[] = "dima";
	char s6[] = "Dima";

	char s7[] = "Dima";
	char s8[] = "";

	char s9[10];
	char s10[10];

	printf("%d | %d\n", ft_memcmp(s1, s2, 4), memcmp(s1, s2, 4));
	printf("%d | %d\n", ft_memcmp(s1, s2, 1), memcmp(s1, s2, 0));

	printf("%d | %d\n", ft_memcmp(s3, s4, 4), memcmp(s3, s4, 4));
	printf("%d | %d\n", ft_memcmp(s3, s4, 2), memcmp(s3, s4, 2));

	printf("%d | %d\n", ft_memcmp(s5, s6, 4), memcmp(s5, s6, 4));
	printf("%d | %d\n", ft_memcmp(s5, s6, 1), memcmp(s5, s6, 1));

	printf("%d | %d\n", ft_memcmp(s7, s8, 4), memcmp(s7, s8, 4));
	printf("%d | %d\n", ft_memcmp(s9, s10, 4), memcmp(s9, s10, 4));

	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {1, 2, 3, 4, 6};

	int result1 = ft_memcmp(arr1, arr2, sizeof(arr1));
	int result2 = memcmp(arr1, arr2, sizeof(arr1));

	if (result1 == 0)
	{
		printf("Arrays are equal\n");
	}
	else
	{
		printf("Arrays are not equal\n");
	}

	if (result2 == 0)
	{
		printf("Arrays are equal\n");
	}
	else
	{
		printf("Arrays are not equal\n");
	}

	char str1[] = "12345678901400345678";
	char str2[] = "1234567";

	int result3 = ft_memcmp(str1, str2, 10);
	int result4 = memcmp(str1, str2, 10);

	if (result3 < 0)
	{
		printf("First is less than second.\n");
	}
	else if (result3 == 0)
	{
		printf("First is equal to second.\n");
	}
	else
	{
		printf("First is greater than second.\n");
	}

	if (result4 < 0)
	{
		printf("First is less than second.\n");
	}
	else if (result4 == 0)
	{
		printf("First is equal to second.\n");
	}
	else
	{
		printf("First is greater than second.\n");
	}
}*/