/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:48:55 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/20 13:00:05 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_words_count(char const *s, char c);
static char	*ft_malloc_word(char const *s, char c);
static int	ft_malloc_words(char const *s, int w_count, char c, char **arr);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		w_count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	w_count = ft_words_count(s, c);
	if (w_count < 1)
		return (NULL);
	arr = (char **)malloc((w_count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (i < w_count + 1)
	{
		arr[i] = NULL;
		i++;
	}
	if (ft_malloc_words(s, w_count, c, arr) == 0)
		return (NULL);
	return (arr);
}

static int	ft_words_count(char const *s, char c)
{
	int	count;

	count = 1;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			count++;
		}
		s++;
	}
	return (count);
}

static char	*ft_malloc_word(char const *s, char c)
{
	char	*word;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	word = (char *)malloc((count + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_malloc_words(char const *s, int w_count, char c, char **arr)
{
	int	i;

	i = 0;
	while (*s && i < w_count)
	{
		if (*s == c)
			s++;
		else
		{
			arr[i] = ft_malloc_word(s, c);
			if (arr[i] == NULL)
				return (free_arr_str(arr), 0);
			i++;
			s++;
			while (*s != c && *s)
				s++;
		}
	}
	if (i != w_count)
		return (free_arr_str(arr), 0);
	arr[i] = NULL;
	return (1);
}
