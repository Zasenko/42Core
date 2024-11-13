/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:21:47 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/06 11:21:50 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;

	if (!stack || stack_count(*stack) < 2)
		return ;
	last = stack_last(*stack);
	if (!last)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	last->next = temp;
}

void	ra(t_stack **stack_a)
{
	printf("ra\n");
	rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	printf("rb\n");
	rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	printf("rr\n");
	rotate(stack_a);
	rotate(stack_b);
}
