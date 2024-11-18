/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:13:22 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/15 10:17:33 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_char(char c)
{
	int		i;
	char	*s;

	i = 0;
	s = "0123456789";
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (check_char(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_str_arr(char **arr_str)
{
	int	i;

	i = 0;
	if (!arr_str)
		return (0);
	while (arr_str[i])
	{
		if (check_str(arr_str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_int_arr(int **arr)
{
	int	c;
	int	i;
	int	j;

	if (!arr)
		return (0);
	c = 0;
	while (arr[c])
		c++;
	if (c == 0)
		return (0);
	i = 0;
	while (i < c - 1 && arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (*(arr[i]) == *(arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
