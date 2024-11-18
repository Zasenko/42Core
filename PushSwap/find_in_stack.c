/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:02:51 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/14 12:12:37 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min_n(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	min = 2147483647;
	while (tmp)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

int	num_position(t_stack *stack, int num)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (num == tmp->num)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*item_in_stack_by_pos(t_stack *stack, int pos)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	if (!tmp)
		return (NULL);
	while (i++ < pos)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

int	is_stack_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (!tmp)
		return (-1);
	while (tmp && tmp->next)
	{
		if (tmp->num < tmp->next->num)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
