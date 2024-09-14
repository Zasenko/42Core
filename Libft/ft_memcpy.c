/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:16:52 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 13:15:25 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_buff;
	unsigned char	*src_buff;

	if (!src && !dest)
		return (dest);
	dest_buff = (unsigned char *)dest;
	src_buff = (unsigned char *)src;
	while (n-- > 0)
		*(dest_buff++) = *(src_buff++);
	return (dest);
}
/*
//cc -Wall -Wextra -Werror libft.h ft_memcpy.c
int	main(void)
{
	char src1[] = "Hello, World!";
	char dest1[20];
	char dest1_ft[20];

	int src2[] = {1, 2, 3, 4, 5};
	int dest2[5];
	int dest2_ft[5];

	memcpy(dest1, src1, sizeof(src1));
	memcpy(dest2, src2, sizeof(src2));

	ft_memcpy(dest1_ft, src1, sizeof(src1));
	ft_memcpy(dest2_ft, src2, sizeof(src2));

	printf("Test 1: Strings\n");
	printf("Standard memcpy: %s\n", dest1);
	printf("Custom ft_memcpy: %s\n\n", dest1_ft);

	printf("Test 2: Integer arrays\n");
	printf("Standard memcpy: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", dest2[i]);
	printf("\nCustom ft_memcpy: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", dest2_ft[i]);
	printf("\n\n");
	return 0;
}*/