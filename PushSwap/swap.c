/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:22:04 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/06 11:22:07 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || stack_count(stack) < 2)
		return ;
	temp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = temp;
	return ;
}

void	sa(t_stack *stack_a)
{
	write(1, "sa\n", 3);
	swap(stack_a);
}

void	sb(t_stack *stack_b)
{
	write(1, "sb\n", 3);
	swap(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "ss\n", 3);
	swap(stack_a);
	swap(stack_b);
}
