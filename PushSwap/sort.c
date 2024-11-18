/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:49 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/14 12:44:15 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	int	n1;
	int	n2;
	int	n3;

	if (!stack || stack_count(*stack) != 3)
		return ;
	n1 = (*stack)->num;
	n2 = (*stack)->next->num;
	n3 = (*stack)->next->next->num;
	if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		rra(stack);
		sa(*stack);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(stack);
	else if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(*stack);
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(stack);
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		ra(stack);
		sa(*stack);
	}
}

void	sort_2(t_stack **stack_a)
{
	if (!stack_a || stack_count(*stack_a) != 2)
		return ;
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(*stack_a);
}

void	sort_back(t_stack **stack_a, t_stack **stack_b, t_prop prop)
{
	int		count_3;
	t_stack	*last;

	count_3 = 0;
	rotate_stack_b_to_max(stack_b, prop);
	sort_3(stack_a);
	last = NULL;
	while (prop.b_count > 0)
	{
		last = stack_last(*stack_a);
		if (last && last->num > (*stack_b)->num && count_3 < 3)
		{
			rra(stack_a);
			count_3++;
		}
		else
		{
			pa(stack_a, stack_b);
			prop.b_count--;
			prop.a_count++;
		}
	}
	rotate_stack_a_to_min(stack_a, prop);
}

void	sort_alg(t_stack **stack_a, t_stack **stack_b)
{
	int		position;
	t_stack	*push_item;
	t_prop	prop;

	set_properties(*stack_a, &prop);
	while (prop.a_count > 3)
	{
		if (prop.b_count > 1)
		{
			position = find_cheapest_position(*stack_a, *stack_b, prop);
			push_item = item_in_stack_by_pos(*stack_a, position);
			if (push_item)
				rotate_stacks(*push_item, stack_a, stack_b, prop);
		}
		push_b(stack_a, stack_b, &prop);
		set_min_max(*stack_b, &prop.b_min, &prop.b_max);
	}
	sort_back(stack_a, stack_b, prop);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	a_count;

	a_count = stack_count(*stack_a);
	if (a_count == 1 || is_stack_sorted(*stack_a))
		return ;
	else if (a_count == 2)
		sort_2(stack_a);
	else if (a_count == 3)
		sort_3(stack_a);
	else
		sort_alg(stack_a, stack_b);
}
