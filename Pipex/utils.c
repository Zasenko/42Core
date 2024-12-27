/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:59:58 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/27 13:33:24 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && (i + j) < len && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

int	arr_str_count(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
