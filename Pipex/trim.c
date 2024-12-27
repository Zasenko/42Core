/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:00:29 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/26 17:02:33 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int is_char_is_sep(char c, char *sep)
{
	int i;

	i = 0;
	if (!sep)
		return (i);
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int count_till_sep(char *str, char *sep)
{
	int i;

	i = 0;
	if (!str || !sep)
		return (i);
	while (str[i])
	{
		if (is_char_is_sep(str[i], sep) == 0)
			i++;
		else
			break;
	}
	return (i);
}

char *ft_trim(char *str, char *sep, char *c)
{
	char *trimmed;
	int count;

	if (!str || !sep || !c)
		return (NULL);
	trimmed = NULL;
	count = ft_strlen(str);
	if (count < 1)
		return (NULL);
	trimmed = malloc(sizeof(char));
	if (!trimmed)
		return (NULL);
	trimmed[0] = '\0';

	while (*str)
	{
		if (is_char_is_sep(*str, sep) == 1)
			str++;
		else
			break;
	}
	while (*str)
	{
		int count = count_till_sep(str, sep);
		if (count > 0)
		{
			char *new = malloc(sizeof(char) * (count + 1));
			if (!new)
			{
				free(trimmed);
				return (NULL);
			}
			int d = 0;
			while (d <= count)
			{
				new[d] = '\0';
				d++;
			}
			d = 0;
			while (d < count)
			{
				new[d] = *str;
				d++;
				str++;
			}

			int flag = 0;
			while (is_char_is_sep(*str, sep) == 1)
			{
				str++;
				flag = 1;
			}
			if (flag && *str != '\0')
			{
				char *new_char = ft_strjoin(new, c);
				if (!new_char)
					return (free(trimmed), free(new), NULL);
				free(new);
				char *new_new = ft_strjoin(trimmed, new_char);
				if (!new_new)
					return (free(trimmed), free(new_char), NULL);
				free(trimmed);
				free(new_char);
				trimmed = new_new;
			}
			else
			{
				char *new_new = ft_strjoin(trimmed, new);
				if (!new_new)
					return (free(trimmed), free(new), NULL);
				free(trimmed);
				free(new);
				trimmed = new_new;
			}
		}
	}
	return (trimmed);
}
