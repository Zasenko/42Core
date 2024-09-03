/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:53:33 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/03 12:36:53 by dzasenko         ###   ########.fr       */
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
