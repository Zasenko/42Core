/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:33:37 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 12:52:46 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	size_t	s_l;
	size_t	e_l;
	size_t	len;
	size_t	i;

	s_l = 0;
	e_l = 0;
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_trim(s1[i], set) == 1)
	{
		s_l++;
		i++;
	}
	i = len - 1;
	while (s1[i] && ft_trim(s1[i], set) == 1)
	{
		e_l++;
		i--;
	}
	new_s = ft_substr(s1, s_l, len - e_l - s_l);
	if (new_s == NULL)
		return (NULL);
	return (new_s);
}
/*
//cc -Wall -Wextra -Werror libft.h ft_strtrim.c ft_strlen.c
ft_substr.c ft_strlcpy.c

int	main(void)
{
	char *new;
	new = ft_strtrim("00131241240abc cdefe 454 434234234ghij xyz11345345442",
			"0123456789");
	if (new)
	{
		printf("%s\n", new);
		free(new);
	}
}*/