/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:58:31 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/14 12:10:43 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_properties(t_stack *stack_a, t_prop *prop)
{
	if (stack_a && prop)
	{
		prop->a_count = stack_count(stack_a);
		prop->b_count = 0;
		prop->b_min = 2147483647;
		prop->b_max = -2147483648;
		prop->min = stack_min_n(stack_a);
	}
}

void	set_cheapest_position(t_stack *stack_a, t_stack *stack_b, t_prop prop)
{
	t_stack	*temp;
	t_moves	moves;

	moves.top_a = 0;
	temp = stack_a;
	while (temp)
	{
		moves.btm_a = prop.a_count - moves.top_a;
		if (moves.btm_a == prop.a_count)
			moves.btm_a = 0;
		moves.top_b = pos_for_n_in_stack_b(stack_b, temp->num, prop);
		moves.btm_b = prop.b_count - moves.top_b;
		if (moves.btm_b == prop.b_count)
			moves.btm_b = 0;
		find_minimum_moves(temp, moves, 0);
		temp->index = moves.top_a;
		temp = temp->next;
		moves.top_a++;
	}
}

void	set_min_max(t_stack *stack, int *min, int *max)
{
	if (!stack || !min || !max)
		return ;
	if (stack->num < *min)
		*min = stack->num;
	if (stack->num > *max)
		*max = stack->num;
}
