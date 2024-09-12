/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:16:52 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/10 09:49:04 by dzasenko         ###   ########.fr       */
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
	while (n > 0)
	{
		*(dest_buff++) = *(src_buff++);
		n--;
	}
	return (dest);
}
