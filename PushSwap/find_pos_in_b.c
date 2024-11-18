/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_in_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:29:12 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/14 12:31:50 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	less_num_pos_top_b(t_stack *stack, int num)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	if (!tmp)
		return (-1);
	while (tmp && num < tmp->num)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	greater_num_pos_btm_b(t_stack *stack, int num, int len)
{
	t_stack	*last;

	last = stack_last(stack);
	if (!last)
		return (-1);
	if (last->num < num)
	{
		while (len && last->num > num)
		{
			len--;
			last = stack_last_n(stack, len - 1);
		}
	}
	return (len);
}

int	less_num_pos_btm_b(t_stack *stack, int num, int len)
{
	t_stack	*last;

	last = stack_last(stack);
	if (!last)
		return (-1);
	if (last->num < num)
	{
		while (len && last->num < num)
		{
			len--;
			last = stack_last_n(stack, len - 1);
		}
	}
	return (len);
}

int	find_pos_in_stack_b(t_stack *stack, int num, t_prop prop)
{
	int		position;
	t_stack	*last;

	position = 0;
	last = stack_last(stack);
	if (last)
	{
		if (num < stack->num)
			position = less_num_pos_top_b(stack, num);
		else
		{
			if (num > last->num)
				position = less_num_pos_btm_b(stack, num, prop.b_count);
			else
			{
				if (num < last->num && num < last->num)
					return (0);
				else
					position = greater_num_pos_btm_b(stack, num, prop.b_count);
			}
		}
	}
	return (position);
}

int	pos_for_n_in_stack_b(t_stack *stack, int num, t_prop prop)
{
	int	position;

	position = 0;
	if (num < prop.b_min || num > prop.b_max)
		position = num_position(stack, prop.b_max);
	else
		position = find_pos_in_stack_b(stack, num, prop);
	return (position);
}
