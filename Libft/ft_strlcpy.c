/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:49:01 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 14:09:35 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	i;

	i = 0;
	src_size = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}
/*
//cc -lbsd -Wall -Wextra -Werror libft.h ft_strlcpy.c ft_strlen.c
#include <bsd/string.h>

int	main(void)
{
	// Test case 1: Regular copy
	char dst1[20];
	char dst1_ft[20];
	const char *src1 = "Hello, World!";
	size_t size1 = sizeof(dst1);

	// Test case 2: Copy with truncation
	char dst2[10];
	char dst2_ft[10];
	const char *src2 = "Hello, World!";
	size_t size2 = sizeof(dst2);

	// Test case 3: Buffer size is zero
	char dst3[10];
	char dst3_ft[10];
	const char *src3 = "Hello!";
	size_t size3 = 0;

	// Test case 4: Empty source string
	char dst4[20];
	char dst4_ft[20];
	const char *src4 = "";
	size_t size4 = sizeof(dst4);

	// Using standard strlcpy
	size_t ret1 = strlcpy(dst1, src1, size1);
	size_t ret2 = strlcpy(dst2, src2, size2);
	size_t ret3 = strlcpy(dst3, src3, size3);
	size_t ret4 = strlcpy(dst4, src4, size4);

	// Using custom ft_strlcpy
	size_t ret1_ft = ft_strlcpy(dst1_ft, src1, size1);
	size_t ret2_ft = ft_strlcpy(dst2_ft, src2, size2);
	size_t ret3_ft = ft_strlcpy(dst3_ft, src3, size3);
	size_t ret4_ft = ft_strlcpy(dst4_ft, src4, size4);

	// Comparing results for Test 1
	printf("Test 1: Regular copy\n");
	printf("Original strlcpy: '%s' (return: %zu)\n", dst1, ret1);
	printf("Custom ft_strlcpy: '%s' (return: %zu)\n\n", dst1_ft, ret1_ft);

	// Comparing results for Test 2
	printf("Test 2: Copy with truncation\n");
	printf("Original strlcpy: '%s' (return: %zu)\n", dst2, ret2);
	printf("Custom ft_strlcpy: '%s' (return: %zu)\n\n", dst2_ft, ret2_ft);

	// Comparing results for Test 3
	printf("Test 3: Buffer size is zero\n");
	printf("Original strlcpy: '%s' (return: %zu)\n", dst3, ret3);
	printf("Custom ft_strlcpy: '%s' (return: %zu)\n\n", dst3_ft, ret3_ft);

	// Comparing results for Test 4
	printf("Test 4: Empty source string\n");
	printf("Original strlcpy: '%s' (return: %zu)\n", dst4, ret4);
	printf("Custom ft_strlcpy: '%s' (return: %zu)\n\n", dst4_ft, ret4_ft);

	return 0;
}*/