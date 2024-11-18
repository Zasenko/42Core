/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:09:54 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/14 12:41:39 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	moves_top_top(int top_a, int top_b)
{
	if (top_a >= top_b)
		return (top_a);
	return (top_b);
}

static int	moves_btm_btm(int btm_a, int btm_b)
{
	if (btm_a >= btm_b)
		return (btm_a);
	return (btm_b);
}

static void	set_minimum_moves(t_stack *temp, int is_top_a, int is_top_b)
{
	if (temp)
	{
		temp->is_top_a = is_top_a;
		temp->is_top_b = is_top_b;
	}
}

void	find_minimum_moves(t_stack *temp, t_moves moves, int min)
{
	int	btm_btm;
	int	top_btm;
	int	btm_top;

	min = moves_top_top(moves.top_a, moves.top_b);
	set_minimum_moves(temp, 1, 1);
	btm_btm = moves_btm_btm(moves.btm_a, moves.btm_b);
	if (min > btm_btm)
	{
		min = btm_btm;
		set_minimum_moves(temp, 0, 0);
	}
	top_btm = moves.top_a + moves.btm_b;
	if (min > top_btm)
	{
		min = top_btm;
		set_minimum_moves(temp, 1, 0);
	}
	btm_top = moves.btm_a + moves.top_b;
	if (min > btm_top)
	{
		min = btm_top;
		set_minimum_moves(temp, 0, 1);
	}
	temp->moves = min;
}

int	find_cheapest_position(t_stack *stack_a, t_stack *stack_b, t_prop prop)
{
	int		i;
	t_stack	*temp;
	int		min;
	int		min_i;

	set_cheapest_position(stack_a, stack_b, prop);
	i = 0;
	temp = stack_a;
	min = temp->moves;
	min_i = 0;
	while (temp)
	{
		if (temp->moves < min)
		{
			min = temp->moves;
			min_i = i;
		}
		i++;
		temp = temp->next;
	}
	return (min_i);
}
