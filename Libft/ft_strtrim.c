/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:33:37 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/06 13:55:24 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_trim(char c, char const *set)
{
	int	i;

	i = 0;
	while (*set)
	{
		if (*set == c)
			i = 1;
		set++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	int		s_l;
	int		e_l;
	int		len;
	int		i;

	s_l = 0;
	e_l = 0;
	len = (int)ft_strlen(s1);
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
int	main(void)
{
	char *new;
	new = ft_strtrim("00131241240   abS cdefe 454 434234234ghij11345345442", "0123456789");
	if (new)
	{
		printf("%s\n", new);
		free(new);
	}
}*/