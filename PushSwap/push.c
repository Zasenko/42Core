/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/11/06 11:21:18 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/06 11:21:20 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*temp1;

	if (!stack_1 || stack_count(*stack_1) < 1)
		return ;
	temp1 = stack_1[0];
	stack_1[0] = (stack_1[0])->next;
	stack_add_front(stack_2, temp1);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "pa\n", 3);
	push(stack_b, stack_a);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "pb\n", 3);
	push(stack_a, stack_b);
}

void	push_b(t_stack **stack_a, t_stack **stack_b, t_prop *prop)
{
	if (!stack_a || !stack_b || !prop)
		return ;
	pb(stack_a, stack_b);
	prop->a_count -= 1;
	prop->b_count += 1;
}
