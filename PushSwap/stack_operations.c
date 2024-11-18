/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:46:32 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/14 13:26:52 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_count(t_stack *stack)
{
	t_stack	*temp;
	int		count;

	count = 0;
	if (!stack)
		return (count);
	temp = stack;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (new)
	{
		last = stack_last(stack[0]);
		if (last)
			last->next = new;
		else
			*stack = new;
	}
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (new)
	{
		new->next = stack[0];
		stack[0] = new;
	}
}

t_stack	*new_stack(int i)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = i;
	stack->next = NULL;
	return (stack);
}
