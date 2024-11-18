/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:37:47 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/14 11:38:02 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_words_count(char const *s, char c)
{
	int	l;
	int	f;

	l = 0;
	f = 1;
	while (*s)
	{
		if (*s == c)
			f = 1;
		else
		{
			if (f == 1)
			{
				l++;
				f = 0;
			}
		}
		s++;
	}
	return (l);
}

static char	*ft_malloc_word(char const *s, char c)
{
	int		i;
	char	*word;
	int		count;

	i = 0;
	count = 0;
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

static void	ft_free_arr(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
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
			{
				ft_free_arr(arr, i--);
				return (0);
			}
			i++;
			s++;
			while (*s != c && *s)
				s++;
		}
	}
	arr[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**arr;
	int		w_count;

	if (!s)
		return (NULL);
	w_count = ft_words_count(s, c);
	arr = (char **)malloc((w_count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i <= w_count)
		arr[i++] = NULL;
	if (ft_malloc_words(s, w_count, c, arr) == 0)
		return (NULL);
	return (arr);
}
