/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:19:53 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/10 09:49:06 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_buff;
	unsigned char	*src_buff;

	if (!src && !dest)
		return (dest);
	dest_buff = (unsigned char *)dest;
	src_buff = (unsigned char *)src;
	if (dest_buff > src_buff)
	{
		dest_buff += n;
		src_buff += n;
		while (n--)
			*(--dest_buff) = *(--src_buff);
	}
	else
	{
		while (n--)
			*(dest_buff++) = *(src_buff++);
	}
	return (dest);
}
/*
int	main(void)
{
	char src1[50] = "Hello,Dima!";
	char src11[50] = "Hello,Dima!";

	char src2[50] = "Hello,Dima!";
	char src22[50] = "Hello,Dima!";

	char src3[50] = "Hello,Dima!";
	char src33[50] = "Hello,Dima!";

	ft_memmove(src1 + 3, src1, 4);
	printf("%s\n", src1);

	printf("--------------\n");

	memmove(src11 + 3, src11, 4);
	printf("%s\n", src11);

	printf("--------------\n");
	printf("--------------\n");

	ft_memmove(src2 + 3, src2, 3);
	printf("%s\n", src2);

	printf("--------------\n");

	memmove(src22 + 3, src22, 3);
	printf("%s\n", src22);

	printf("--------------\n");
	printf("--------------\n");

	ft_memmove(src3, src3, 3);
	printf("%s\n", src3);

	printf("--------------\n");

	memmove(src33, src33, 3);
	printf("%s\n", src33);
}*/