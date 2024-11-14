/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:49 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/13 13:59:07 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_stack_sorted(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    if (!tmp)
        return -1;
    while (tmp && tmp->next)
    {
        if (tmp->num < tmp->next->num)
            tmp = tmp->next;
        else
            return 0;
    }
    return 1;
}

int stack_min_n(t_stack *stack)
{
    t_stack *tmp;
    int min;

    tmp = stack;
    min = 2147483647;
    while (tmp)
    {
        if (tmp->num < min)
            min = tmp->num;
        tmp = tmp->next;
    }
    return min;
}

int num_position(t_stack *stack, int num)
{
    t_stack *tmp;
    int i;

    tmp = stack;
    i = 0;
    while (tmp)
    {
        if (num == tmp->num)
            return i;
        tmp = tmp->next;
        i++;
    }
    return i;
}

int sort_stack_top_less_n_pos(t_stack *stack, int num)
{
    t_stack *tmp;
    int i;

    tmp = stack;
    i = 0;
    if (!tmp)
        return (-1);
    while (tmp && num < tmp->num)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

int sort_stack_btm_greater_n_pos333(t_stack *stack, int num, int len)
{
    t_stack *last;
    
    last = stack_last(stack);
    if (!last)
        return (-1);
    if (last->num < num)
    {
        while (len && last->num > num)
        {
            len--;
            last = stack_last_n(stack, len - 1);
        }
    }
    return (len);
}

int sort_stack_btm_less_n_pos333(t_stack *stack, int num, int len)
{
    t_stack *last;
    
    last = stack_last(stack);
    if (!last)
        return (-1);
    if (last->num < num)
    {
        while (len && last->num < num)
        {
            len--;
            last = stack_last_n(stack, len - 1);
        }
    }
    return (len);
}

void sort_3(t_stack **stack)
{
    int n1;
    int n2;
    int n3;

    if (!stack || stack_count(*stack) != 3)
        return; 
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

void sort_2(t_stack **stack_a)
{
    if(!stack_a || stack_count(*stack_a) != 2)
        return;
    if ((*stack_a)->num > (*stack_a)->next->num)
        sa(*stack_a);
}

void set_min_max(t_stack *stack, int *min, int *max)
{
    if (!stack || !min || !max)
        return ;
    if (stack->num < *min)
        *min = stack->num;
    if (stack->num > *max)
        *max = stack->num;
}

void push_b(t_stack **stack_a, t_stack **stack_b, t_prop *prop)
{
    if (!stack_a || !stack_b || !prop)
        return;
    pb(stack_a, stack_b);
    prop->a_count -= 1;
    prop->b_count += 1;
}

// int test()
// {

// }

int pos_for_n_in_stack_b(t_stack *stack, int num, t_prop prop)
{
    int position = 0;
    if (num < prop.b_min || num > prop.b_max)
        position = num_position(stack, prop.b_max);
    else
    {
        if (num < stack->num)
        {
            t_stack *l = stack_last(stack);
            if (l)
                position = sort_stack_top_less_n_pos(stack, num);
        }
        else
        {
                t_stack *l = stack_last(stack);
                if (l)
                {
                    if (num > l->num )
                        position = sort_stack_btm_less_n_pos333(stack, num, prop.b_count);
                    else
                    {
                        if (num < l->num && num < l->num)
                            return 0;
                        else {
                            position = sort_stack_btm_greater_n_pos333(stack, num, prop.b_count);
                        }
                    }
                }
        }
    }
    return position;
}

//+
void set_cheapest_position(t_stack *stack_a, t_stack *stack_b, t_prop prop)
{
    t_stack *temp;
    t_moves moves;

    moves.top_moves_a = 0;
    temp = stack_a;
    while (temp)
    {
        moves.btm_moves_a = prop.a_count - moves.top_moves_a;
        if (moves.btm_moves_a == prop.a_count)
            moves.btm_moves_a = 0;
        moves.top_moves_b = pos_for_n_in_stack_b(stack_b, temp->num, prop);
        moves.btm_moves_b = prop.b_count - moves.top_moves_b;
        if (moves.btm_moves_b == prop.b_count)
            moves.btm_moves_b = 0;
        find_minimum_moves(temp, moves);
        temp->index = moves.top_moves_a;
        temp = temp->next;
        moves.top_moves_a++;
    }
}

//+
int find_cheapest_position(t_stack *stack_a, t_stack *stack_b, t_prop prop)
{
    int i;
    t_stack *temp;
    int min;
    int min_i;
    
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
    return min_i;
}

//+
t_stack *item_in_stack_by_pos(t_stack *stack, int pos)
{
    t_stack *tmp;
    int i;

    tmp = stack;
    i = 0;
    if (!tmp)
        return NULL;
    while (i++ < pos)
        tmp = tmp->next;
    return tmp;
}

void rotate_stack_b_to_max(t_stack **stack_b, t_prop prop)
{
    int i;
    int position;

    i = 0;
    position = num_position(*stack_b, prop.b_max);
    if (position < prop.b_count / 2 || (prop.b_count % 2 != 0 && (prop.b_count / 2) == position))
    {
        while (i++ < position)
            rb(stack_b);
    }
    else
    {
        while (i++ < prop.b_count - position)
            rrb(stack_b);
    }
}

void rotate_stack_a_to_min(t_stack **stack_a, t_prop prop)
{
    int i;
    int position;

    i = 0;
    position = num_position(*stack_a, prop.min);
    if (position < prop.a_count / 2 || (prop.a_count % 2 != 0 && (prop.a_count / 2) == position))
    {
        while (i++ < position)
            ra(stack_a);
    }
    else
    {
        while (i++ < prop.a_count - position)
            rra(stack_a);
    }
}

void sort_back(t_stack **stack_a, t_stack **stack_b, t_prop prop)
{
    int count_3;
    t_stack *last;

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

void set_properties(t_stack *stack_a, t_prop *prop)
{
    if (stack_a && prop)
    {
        prop->a_count = stack_count(stack_a);
        prop->b_count = 0;
        prop->b_min = 2147483647;
        prop->b_max = -2147483648;
        prop->min = stack_min_n(stack_a);
    }
}

void sort_alg(t_stack **stack_a, t_stack **stack_b)
{
    int position;
    t_stack *push_item;
    t_prop prop;

    set_properties(*stack_a, &prop);
    while (prop.a_count > 3)
    {
        if (prop.b_count > 1)
        {
            position = find_cheapest_position(*stack_a, *stack_b, prop);
            push_item = item_in_stack_by_pos(*stack_a, position);
            if(push_item)
                rotate_stacks(*push_item, stack_a, stack_b, prop);
        }
        push_b(stack_a, stack_b, &prop);
        set_min_max(*stack_b, &prop.b_min, &prop.b_max);
    }
    sort_back(stack_a, stack_b, prop);
}

void sort(t_stack **stack_a, t_stack **stack_b)
{
    int a_count;

    a_count = stack_count(*stack_a);
    if (a_count == 1 || is_stack_sorted(*stack_a))
        return;
    else if (a_count == 2)
        sort_2(stack_a);
    else if (a_count == 3)
        sort_3(stack_a);
    else
        sort_alg(stack_a, stack_b);
}
