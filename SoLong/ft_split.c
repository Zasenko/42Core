/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:48:55 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/25 11:33:20 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_words_count(char const *s, char c)
{
	int	count;
	int	f;

	count = 0;
	f = 1;
	while (*s)
	{
		if (*s == c)
			f = 1;
		else
		{
			if (f == 1)
			{
				count++;
				f = 0;
			}
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
	if (arr)
	{
		while (i >= 0)
		{
			if (arr[i])
			{
				free(arr[i]);
				arr[i] = NULL;
			}
			i--;
		}
		free(arr);	
	}
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
	char	**arr;
	int		w_count;

	if (!s)
		return (NULL);
	w_count = ft_words_count(s, c);
	arr = (char **)malloc((w_count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	if (ft_malloc_words(s, w_count, c, arr) == 0)
		return (NULL);
	return (arr);
}
/*
//cc -Wall -Wextra -Werror libft.h ft_split.c
void	test_ft_split(char *s, char c, char **expected_result)
{
	char	**result;
	int		i;

	result = ft_split(s, c);
	i = 0;
	printf("Testing string: \"%s\" with delimiter '%c'\n", s, c);
	while (result[i])
	{
		printf("result[%d]: \"%s\"\n", i, result[i]);
		if (expected_result[i] == NULL || strcmp(result[i],
				expected_result[i]) != 0)
		{
			printf("Test failed at index %d: expected \"%s\", but got \"%s\"\n",
				i, expected_result[i], result[i]);
			return ;
		}
		i++;
	}
	if (expected_result[i] != NULL)
		printf("Test failed: expected more elements in the result.\n");
	else
		printf("Test passed!\n");
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	main(void)
{
	// Example string with spaces
	char s1[] = " hello world Dima";
	char *expected1[] = {"hello", "world", "Dima", NULL};
	test_ft_split(s1, ' ', expected1);
	printf("------------\n");

	// Example string with multiple spaces
	char s2[] = "  hello   world   ";
	char *expected2[] = {"hello", "world", NULL};
	test_ft_split(s2, ' ', expected2);
	printf("------------\n");

	// Example string with no delimiters
	char s3[] = "helloworld";
	char *expected3[] = {"helloworld", NULL};
	test_ft_split(s3, ' ', expected3);
	printf("------------\n");

	// Example string that is empty
	char s4[] = "";
	char *expected4[] = {NULL};
	test_ft_split(s4, ' ', expected4);
	printf("------------\n");

	// Example with only delimiter characters
	char s5[] = "      ";
	char *expected5[] = {NULL};
	test_ft_split(s5, ' ', expected5);
	printf("------------\n");

	return (0);
}*/