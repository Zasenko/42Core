/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:44:33 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/14 11:52:05 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_top_top(t_stack **s_a, t_stack **s_b, int top_a, int top_b)
{
	if (top_a >= top_b)
	{
		while (top_a-- > 0)
		{
			if (top_b-- > 0)
				rr(s_a, s_b);
			else
				ra(s_a);
		}
	}
	else
	{
		while (top_b-- > 0)
		{
			if (top_a-- > 0)
				rr(s_a, s_b);
			else
				rb(s_b);
		}
	}
}

static void	rotate_top_btm(t_stack **s_a, t_stack **s_b, int top_a, int btm_b)
{
	while (top_a-- > 0)
		ra(s_a);
	while (btm_b-- > 0)
		rrb(s_b);
}

static void	rotate_btm_btm(t_stack **s_a, t_stack **s_b, int btm_a, int btm_b)
{
	if (btm_a >= btm_b)
	{
		while (btm_a-- > 0)
		{
			if (btm_b-- > 0)
				rrr(s_a, s_b);
			else
				rra(s_a);
		}
	}
	else
	{
		while (btm_b-- > 0)
		{
			if (btm_a-- > 0)
				rrr(s_a, s_b);
			else
				rrb(s_b);
		}
	}
}

static void	rotate_btm_top(t_stack **s_a, t_stack **s_b, int btm_a, int top_b)
{
	while (top_b-- > 0)
		rb(s_b);
	while (btm_a-- > 0)
		rra(s_a);
}

void	rotate_stacks(t_stack item, t_stack **s_a, t_stack **s_b, t_prop prop)
{
	int	top_moves_a;
	int	btm_moves_a;
	int	top_moves_b;
	int	btm_moves_b;

	top_moves_a = item.index;
	btm_moves_a = prop.a_count - item.index;
	if (btm_moves_a == prop.a_count)
		btm_moves_a = 0;
	top_moves_b = pos_for_n_in_stack_b(*s_b, item.num, prop);
	btm_moves_b = prop.b_count - top_moves_b;
	if (btm_moves_b == prop.b_count)
		btm_moves_b = 0;
	if (item.is_top_a && item.is_top_b)
		rotate_top_top(s_a, s_b, top_moves_a, top_moves_b);
	else if (!item.is_top_a && !item.is_top_b)
		rotate_btm_btm(s_a, s_b, btm_moves_a, btm_moves_b);
	else if (item.is_top_a && !item.is_top_b)
		rotate_top_btm(s_a, s_b, top_moves_a, btm_moves_b);
	else if (!item.is_top_a && item.is_top_b)
		rotate_btm_top(s_a, s_b, btm_moves_a, top_moves_b);
}
