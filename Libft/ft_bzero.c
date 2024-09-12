/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:05:23 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/11 13:36:21 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int	main(void)
{
	char c[] = "Hello!";
	char c2[] = "Hello!";

	ft_bzero((void *)c, 4);
	bzero((void *)c2, 4);

	printf("%s\n", c);
	printf("%s\n", c2);

	printf("%s\n", &c[3]);
	printf("%s\n", &c2[3]);

	printf("%s\n", &c[4]);
	printf("%s\n", &c2[4]);

	printf("%s\n", &c[5]);
	printf("%s\n", &c2[5]);
}*/