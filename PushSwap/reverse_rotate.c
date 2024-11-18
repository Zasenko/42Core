/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:41:49 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/14 11:41:54 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_last_n(t_stack *stack, int count)
{
	t_stack	*temp;

	temp = stack;
	if (!temp || count <= 0)
		return (NULL);
	while (temp->next != NULL && count--)
		temp = temp->next;
	return (temp);
}

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second_last = *stack;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	write(1, "rra\n", 4);
	reverse_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	write(1, "rrb\n", 4);
	reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "rrr\n", 4);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
