/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:49:19 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 12:30:22 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub_s = (char *)malloc(1 * sizeof(char));
		if (sub_s == NULL)
			return (NULL);
		sub_s[0] = '\0';
		return (sub_s);
	}
	if (len > s_len - start)
		len = s_len - start;
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (sub_s == NULL)
		return (NULL);
	ft_strlcpy(sub_s, s + start, len + 1);
	return (sub_s);
}
/*
//cc -Wall -Wextra -Werror libft.h ft_substr.c ft_strlen.c ft_strlcpy.c
int	main(void)
{
	char s[] = "Hello, Dimitry!";
	char	*sub;
	sub = ft_substr(s, 0, 4);
	if (sub)
	{
		printf("%s\n", sub);
		free(sub);
	}
	sub = ft_substr(s, 7, 4);
	if (sub)
	{
		printf("%s\n", sub);
		free(sub);
	}
	sub = ft_substr(s, 13, 4);
	if (sub)
	{
		printf("%s\n", sub);
		free(sub);
	}
	sub = ft_substr(s, 17, 4);
	if (sub)
	{
		printf("%s\n", sub);
		free(sub);
	}
}*/