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

//TODO: Delete counter + printf
extern int counter;

static void	rotate(t_stack **stack)
{
	int		count;
	t_stack	*last;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	count = stack_count(stack);
	if (count < 2)
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
	//printf("ra | ");
	printf("ra\n");
	rotate(stack_a);
	counter++;
}

void	rb(t_stack **stack_b)
{
	//printf("rb | ");
	printf("rb\n");
	rotate(stack_b);
	counter++;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	//printf("rr | ");
	printf("rr\n");
	rotate(stack_a);
	rotate(stack_b);
	counter++;
}
