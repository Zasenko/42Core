/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:21:31 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/06 11:21:34 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO: Delete counter + printf
extern int counter;

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
	int		count;
	t_stack	*last;
	t_stack	*last2;

	if (!stack || !*stack)
		return ;
	count = stack_count(stack);
	if (count < 2)
		return ;
	last = stack_last(*stack);
	last2 = stack_last_n(*stack, count - 2);
	if (!last || !last2)
		return ;
	last->next = stack[0];
	*stack = last;
	last2->next = NULL;
}

void	rra(t_stack **stack_a)
{
	printf("rra | ");
	reverse_rotate(stack_a);
	counter++;
}

void	rrb(t_stack **stack_b)
{
	printf("rrb | ");
	reverse_rotate(stack_b);
	counter++;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	printf("rrr | ");
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	counter++;
}
