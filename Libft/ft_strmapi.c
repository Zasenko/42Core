/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:29:38 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/11 14:14:36 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*new_str;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s, len + 1);
	i = 0;
	while (new_str[i])
	{
		new_str[i] = (*f)(i, new_str[i]);
		i++;
	}
	return (new_str);
}
/*
char	to_uppercase(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char *str = "hello world";
	char *result = ft_strmapi(str, to_uppercase);
	if (result)
	{
		printf("befor: %s\n", str);
		printf("after: %s\n", result);
		free(result);
	}
}*/