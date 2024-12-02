/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:46:59 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/22 10:32:59 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcat(char *s1, const char *s2, int n)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	if (!s1 || !s2 || n < 0)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[l] && n-- > 0)
	{
		s1[i] = s2[l];
		i++;
		l++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strlcpy(char *dest, char *src, int n)
{
	int	i;

	if (!src || n < 0)
		return (NULL);
	i = 0;
	while (src[i] && n-- > 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_srtdub(char *str)
{
	char	*dub;
	int		len;
	int		i;

	if (!str)
		return (NULL);
	len = nl_l(str, 0);
	dub = (char *)malloc(sizeof(char) * (len + 1));
	if (dub == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dub[i] = str[i];
		i++;
	}
	dub[i] = '\0';
	return (dub);
}

int	nl_l(char *str, int till_nl)
{
	int	count;
	int	i;

	i = 0;
	if (!str)
		return (i);
	count = 0;
	if (till_nl == 1)
	{
		while (str[i] && str[i] != '\n')
		{
			count++;
			i++;
		}
		if (str[i] == '\n')
			count++;
	}
	else
	{
		while (str[i++])
			count++;
	}
	return (count);
}

int	ft_is_new_line_in_buf(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}