/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:34:51 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/14 12:35:11 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_b_to_max(t_stack **stack_b, t_prop pr)
{
	int	i;
	int	p;

	i = 0;
	p = num_position(*stack_b, pr.b_max);
	if (p < pr.b_count / 2 || (pr.b_count % 2 != 0 && (pr.b_count / 2) == p))
	{
		while (i++ < p)
			rb(stack_b);
	}
	else
	{
		while (i++ < pr.b_count - p)
			rrb(stack_b);
	}
}

void	rotate_stack_a_to_min(t_stack **stack, t_prop pr)
{
	int	i;
	int	p;

	i = 0;
	p = num_position(*stack, pr.min);
	if (p < pr.a_count / 2 || (pr.a_count % 2 != 0 && (pr.a_count / 2) == p))
	{
		while (i++ < p)
			ra(stack);
	}
	else
	{
		while (i++ < pr.a_count - p)
			rra(stack);
	}
}
