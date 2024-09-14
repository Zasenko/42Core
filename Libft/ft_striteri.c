/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:41:52 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 12:55:04 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
//cc -Wall -Wextra -Werror libft.h ft_striteri.c

void	to_uppercase_inplace(unsigned int i, char *c)
{
	(void)i;  // Unused param
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	main(void)
{
	char str1[] = "hello world";

	printf("Original: %s\n", str1);
	ft_striteri(str1, to_uppercase_inplace);
	printf("After: %s\n", str1);

	return (0);
}*/