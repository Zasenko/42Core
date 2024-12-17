/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:26:31 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 12:03:53 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	f;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		f = 0;
		while (big[i + f] != '\0' && (i + f) < len && big[i + f] == little[f])
		{
			f++;
			if (little[f] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l;
	char	*s_new;
	size_t	i;
	size_t	f;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	s_new = (char *)malloc((l + 1) * sizeof(char));
	if (s_new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_new[i] = s1[i];
		i++;
	}
	f = 0;
	while (s2[f])
		s_new[i++] = s2[f++];
	s_new[i] = '\0';
	return (s_new);
}
