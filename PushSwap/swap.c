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

//TODO: Delete counter + printf
extern int counter;

static void	swap(t_stack *stack)
{
	int	temp;
	int	c;

	if (!stack)
		return ;
	c = stack_count(stack);
	if (c < 2)
		return ;
	temp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = temp;
	return ;
}

void	sa(t_stack *stack_a)
{
	//printf("sa | ");
	printf("sa\n");
	swap(stack_a);
	counter++;
}

void	sb(t_stack *stack_b)
{
	//printf("sb | ");
	printf("sb\n");
	swap(stack_b);
	counter++;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	//printf("ss | ");
	printf("ss\n");
	swap(stack_a);
	swap(stack_b);
	counter++;
}
