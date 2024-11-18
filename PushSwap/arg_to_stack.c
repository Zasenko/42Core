/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:59:30 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/15 10:17:29 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*args_to_str(char **argv)
{
	char	*str;
	char	*new_str;
	int		i;

	if (!argv || !argv[1])
		return (NULL);
	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	i = 1;
	while (argv[i])
	{
		new_str = ft_strjoin_sep(str, argv[i++], ' ');
		free_str(&str);
		if (!new_str)
			return (NULL);
		str = new_str;
	}
	return (str);
}

int	arr_str_to_int(char **arr_str, int **arr_i)
{
	int	*n;
	int	i;

	i = 0;
	if (!arr_str || !arr_str)
		return (0);
	while (arr_str[i] != NULL)
	{
		n = ft_atoi(arr_str[i]);
		if (!n)
			return (0);
		arr_i[i++] = n;
	}
	return (1);
}

int	**arr_str_to_arr_int(char **arr_str)
{
	int	**arr_i;
	int	i;
	int	count;

	if (!arr_str)
		return (NULL);
	i = 0;
	count = 0;
	while (arr_str[i++])
		count++;
	arr_i = (int **)malloc(sizeof(int *) * (count + 1));
	if (!arr_i)
		return (NULL);
	i = 0;
	while (i <= count)
		arr_i[i++] = NULL;
	if (!arr_str_to_int(arr_str, arr_i))
		return (free_int_arr(arr_i), NULL);
	return (arr_i);
}

t_stack	*arr_int_to_stack(int **arr)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	stack = NULL;
	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i])
	{
		new = new_stack(*(arr[i]));
		if (!new)
			return (free_stack(&stack), NULL);
		stack_add_back(&stack, new);
		i++;
	}
	return (stack);
}
