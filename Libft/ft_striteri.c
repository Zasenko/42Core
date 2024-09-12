/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:41:52 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/11 14:12:01 by dzasenko         ###   ########.fr       */
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
void	to_uppercase_inplace(unsigned int i, char *c)
{
	(void)i;  // Unused param
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	shift_char_by_index_inplace(unsigned int i, char *c)
{
	*c = *c + i;
}

int	main(void)
{
	char str1[] = "hello world";
	char str2[] = "abcdef";

	printf("Original: %s\n", str1);
	ft_striteri(str1, to_uppercase_inplace);
	printf("Uppercase in-place: %s\n", str1);

	printf("Original: %s\n", str2);
	ft_striteri(str2, shift_char_by_index_inplace);
	printf("Shifted in-place: %s\n", str2);

	return (0);
}*/
