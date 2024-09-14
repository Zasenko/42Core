/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:53:33 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 14:07:23 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_lenght;
	size_t	src_lenght;
	size_t	dest_i;
	size_t	src_i;

	dest_lenght = ft_strlen(dst);
	src_lenght = ft_strlen(src);
	dest_i = 0;
	src_i = 0;
	if (size <= dest_lenght)
		return (size + src_lenght);
	while (dest_i < (size - 1) && dst[dest_i])
		dest_i++;
	while (dest_i < (size - 1) && src[src_i])
	{
		dst[dest_i] = src[src_i];
		src_i++;
		dest_i++;
	}
	dst[dest_i] = '\0';
	return (dest_lenght + src_lenght);
}
/*
//cc -lbsd -Wall -Wextra -Werror libft.h ft_strlcat.c ft_strlen.c

#include <bsd/string.h>

int	main(void)
{
	char dst1[20] = "Hello, ";
	char dst1_ft[20] = "Hello, ";
	const char *src1 = "World!";
	size_t ret1 = strlcat(dst1, src1, sizeof(dst1));
	size_t ret1_ft = ft_strlcat(dst1_ft, src1, sizeof(dst1));
	printf("Test 1: Regular concatenation\n");
	printf("Original strlcat: %s (return: %zu)\n", dst1, ret1);
	printf("Custom ft_strlcat: %s (return: %zu)\n", dst1_ft, ret1_ft);
	printf("--------------------\n");

	char dst2[15] = "Hello";
	char dst2_ft[15] = "Hello";
	const char *src2 = ", World!";
	size_t size2 = 10;
	size_t ret2 = strlcat(dst2, src2, size2);
	size_t ret2_ft = ft_strlcat(dst2_ft, src2, size2);
	printf("Test 2: Concatenation with truncation\n");
	printf("Original strlcat: %s (return: %zu)\n", dst2, ret2);
	printf("Custom ft_strlcat: %s (return: %zu)\n", dst2_ft, ret2_ft);
	printf("--------------------\n");

	char dst3[10] = "Hi";
	char dst3_ft[10] = "Hi";
	const char *src3 = "There!";
	size_t size3 = 5;
	size_t ret3 = strlcat(dst3, src3, size3);
	size_t ret3_ft = ft_strlcat(dst3_ft, src3, size3);
	printf("Test 3: Concatenation with small buffer\n");
	printf("Original strlcat: %s (return: %zu)\n", dst3, ret3);
	printf("Custom ft_strlcat: %s (return: %zu)\n", dst3_ft, ret3_ft);

	return (0);
}*/