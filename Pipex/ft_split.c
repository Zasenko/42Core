/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:48:55 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/27 13:51:15 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_words_count(char const *s, char *c);
static int	is_char_is_sep(char c, char *sep);
static char	*ft_malloc_word(char const *s, char *c);
static int	ft_malloc_words(char const *s, int w_count, char *c, char **arr);

char	**ft_split(char const *s, char *c)
{
	char	**arr;
	int		w_count;
	int		i;

	i = 0;
	if (!s || !c)
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

static int	is_char_is_sep(char c, char *sep)
{
	int	i;

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

static int	ft_words_count(char const *s, char *c)
{
	int	count;

	count = 0;
	if (!s || !c)
		return (0);
	while (*s && is_char_is_sep(*s, c))
		s++;
	while (*s)
	{
		if (!is_char_is_sep(*s, c))
		{
			count++;
			while (*s && !is_char_is_sep(*s, c))
				s++;
		}
		while (*s && is_char_is_sep(*s, c))
			s++;
	}
	return (count);
}

static char	*ft_malloc_word(char const *s, char *c)
{
	char	*word;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s || !c)
		return (NULL);
	while (s[i] && !is_char_is_sep(s[i], c))
	{
		count++;
		i++;
	}
	word = (char *)malloc((count + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (s[i] && !is_char_is_sep(s[i], c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_malloc_words(char const *s, int w_count, char *c, char **arr)
{
	int	i;

	i = 0;
	if (!s || !c || !arr)
		return (free_arr_str(arr), 0);
	while (*s && i < w_count)
	{
		if (is_char_is_sep(*s, c))
			s++;
		else
		{
			arr[i] = ft_malloc_word(s, c);
			if (arr[i] == NULL)
				return (free_arr_str(arr), 0);
			i++;
			s++;
			while (*s && !is_char_is_sep(*s, c))
				s++;
		}
	}
	if (i != w_count)
		return (free_arr_str(arr), 0);
	arr[i] = NULL;
	return (1);
}
