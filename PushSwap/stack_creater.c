/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:01:45 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/15 10:12:47 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_sep(char const *s1, char const *s2, char const sep)
{
	size_t	l;
	char	*s_new;
	size_t	i;
	size_t	f;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	s_new = (char *)malloc((l + 2) * sizeof(char));
	if (s_new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_new[i] = s1[i];
		i++;
	}
	s_new[i++] = sep;
	f = 0;
	while (s2[f])
	{
		s_new[i++] = s2[f++];
	}
	s_new[i] = '\0';
	return (s_new);
}

int	*ft_atoi(const char *nptr)
{
	int		i;
	long	sing;
	long	result;
	int		*num;

	i = 0;
	sing = +1;
	result = 0;
	if (!nptr)
		return (NULL);
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sing *= -1;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
		result = result * 10 + (nptr[i++] - '0');
	result *= sing;
	num = (int *)malloc(sizeof(int));
	if (num == NULL || (result < -2147483648 || result > 2147483647))
		return (NULL);
	*num = (int)result;
	return (num);
}

t_stack	*create_stacks(int argc, char **argv)
{
	char	*str;
	char	**arr_str;
	int		**arr_i;
	t_stack	*stack;

	if (argc < 2 || !argv)
		return (NULL);
	str = args_to_str(argv);
	if (!str)
		return (NULL);
	arr_str = ft_split(str, ' ');
	free_str(&str);
	if (!arr_str || check_str_arr(arr_str) == 0)
		return (free_str_arr(arr_str), NULL);
	arr_i = arr_str_to_arr_int(arr_str);
	free_str_arr(arr_str);
	if (!arr_i || check_int_arr(arr_i) == 0)
		return (free_int_arr(arr_i), NULL);
	stack = arr_int_to_stack(arr_i);
	free_int_arr(arr_i);
	return (stack);
}
