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

//+
int stack_max_n(t_stack *stack)
{
    t_stack *tmp;
    int max;

    tmp = stack;
    max = -2147483648;
    while (tmp)
    {
        if (tmp->num > max)
            max = tmp->num;
        tmp = tmp->next;
    }
    return max;
}

//+
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

//+
int stack_n_pos(t_stack *stack, int num)
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

//+
int sort_stack_top_greater_n_pos(t_stack *stack, int num)
{
    t_stack *tmp;
    int i;

    tmp = stack;
    i = 0;
    if (!tmp)
        return (-1);
    while (tmp && num > tmp->num)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

//+
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

//+
int sort_stack_btm_greater_n_pos(t_stack *stack, int num, int len)
{
    t_stack *last;
    
    last = stack_last(stack);
    if (!last)
        return (-1);
    while (len && last->num > num)
    {
        len--;
        last = stack_last_n(stack, len - 1);
    }
    return (len);
}

//+
int sort_stack_btm_greater_n_pos222(t_stack *stack, int num, int len)
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
    else
        return (len - 1);
    return (len);
}

//+
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

//+
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

//+
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

//+
void sort_2(t_stack **stack_a)
{
    if(!stack_a || stack_count(*stack_a) != 2)
    if ((*stack_a)->num > (*stack_a)->next->num)
        sa(*stack_a);
}

//+
void set_min_max(t_stack *stack, int *min, int *max)
{
    if (!stack || !min || !max)
        return ;
    if (stack->num < *min)
        *min = stack->num;
    if (stack->num > *max)
        *max = stack->num;
}

//+
void push_b(t_stack **stack_a, t_stack **stack_b, int *a_count, int *b_count)
{
    if (!stack_a || !stack_b || !a_count || !b_count)
        return;
    pb(stack_a, stack_b);
    *a_count -= 1;
    *b_count += 1;
}

int pos_for_n_in_sort_stack(t_stack *stack, int num, t_prop prop)
{
    int position = 0;
    if (num < prop.b_min || num > prop.b_max)
        position = stack_n_pos(stack, prop.b_max);
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
        moves.top_moves_b = pos_for_n_in_sort_stack(stack_b, temp->num, prop);
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



void sort_back(t_stack **stack_a, t_stack **stack_b)
{
    sort_3(stack_a);

    int min_a = stack_min_n(*stack_a);
    int max_a = stack_max_n(*stack_a);
    int a_count = stack_count(*stack_a);

    while (*stack_b)
    {
        if ((*stack_b)->num < min_a || (*stack_b)->num > max_a)
        {
            int position = stack_n_pos(*stack_a, min_a);
            if (position < a_count / 2 || (a_count % 2 != 0 && (a_count / 2) == position))
            {
                int i = 0;
                while (i < position)
                {
                    ra(stack_a);
                    i++;
                }
            }
            else
            {
                int i = 0;
                while (i < a_count - position)
                {
                    rra(stack_a);
                    i++;
                }
            }
        }
        else
        {
            if ((*stack_b)->num < (*stack_a)->num)
            {
                t_stack *last = stack_last(*stack_a);
                if (last)
                {
                    if (last->num > (*stack_b)->num)
                    {
                        int position = sort_stack_btm_greater_n_pos(*stack_a, (*stack_b)->num, a_count);
                        if (position < a_count / 2 || (a_count % 2 != 0 && (a_count / 2) == position))
                        {
                            int i = 0;
                            while (i < position)
                            {
                                ra(stack_a);
                                i++;
                            }
                        }
                        else
                        {
                            int i = 0;
                            while (i < a_count - position)
                            {
                                rra(stack_a);
                                i++;
                            }
                        }
                    }
                }
            }
            else
            {
                int position = sort_stack_top_greater_n_pos(*stack_a, (*stack_b)->num);
                if (position < a_count / 2 || (a_count % 2 != 0 && a_count / 2 == position))
                {
                    int i = 0;
                    while (i < position)
                    {
                        ra(stack_a);
                        i++;
                    }
                }
                else
                {
                    t_stack *stack_a_last = stack_last(*stack_a);
                    if (stack_a_last)
                    {
                        if (stack_a_last->num < (*stack_b)->num)
                        {
                            int s = a_count - position;
                            int i = 0;
                            while (i < s)
                            {
                                rra(stack_a);
                                i++;
                            }
                        }
                        else
                        {
                            int s = a_count - position;
                            int i = 0;
                            while (i < s)
                            {
                                rra(stack_a);
                                i++;
                            }
                        }
                    }
                }
            }
        }
        pa(stack_a, stack_b);
        a_count++;
        set_min_max(*stack_a, &min_a, &max_a);
    }

    ////printf("--- 0000 last ---\n");
    //TODO!!!!! doublicate
    int position = stack_n_pos(*stack_a, min_a);
    if (position < a_count / 2 || (a_count % 2 != 0 && (a_count / 2) == position))
    {
        int i = 0;
        while (i < position)
        {
            ra(stack_a);
            i++;
        }
    }
    else
    {
        int i = 0;
        while (i < a_count - position)
        {
            rra(stack_a);
            i++;
        }
    }
}

void sort_alg(t_stack **stack_a, t_stack **stack_b)
{
    int position;
    t_stack *push_item;
    t_prop prop;
    
    //todo func - set properties?
    prop.a_count = stack_count(*stack_a);
    prop.b_count = 0;
    prop.b_min = 2147483647;
    prop.b_max = -2147483648;

    while (prop.a_count > 3)
    {
        if (prop.b_count > 1)
        {
            position = find_cheapest_position(*stack_a, *stack_b, prop);
            push_item = item_in_stack_by_pos(*stack_a, position);
            if(push_item)
                rotate_stacks(*push_item, stack_a, stack_b, prop);
        }
        push_b(stack_a, stack_b, &prop.a_count, &prop.b_count);
        set_min_max(*stack_b, &prop.b_min, &prop.b_max);
    }
    sort_back(stack_a, stack_b);
}

//+
void sort(t_stack **stack_a, t_stack **stack_b)
{
    int a_count;

    a_count = stack_count(*stack_a);
    if (a_count == 1)
        return ;
    else if (a_count == 2)
        sort_2(stack_a);
    else if (a_count == 3)
        sort_3(stack_a);
    else
        sort_alg(stack_a, stack_b);
}
