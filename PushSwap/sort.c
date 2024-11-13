/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:49 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/12 14:29:14 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: delete counter
extern int counter;

int pos_for_n_in_sort_stack(t_stack *stack, int num, int min, int max, int count);

void sort_back(t_stack **stack_a, t_stack **stack_b);

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

int stack_n_pos(t_stack *stack, int num)
{
    t_stack *tmp = stack;
    int i = 0;
    while (tmp)
    {
        if (num == tmp->num)
            return i;
        tmp = tmp->next;
        i++;
    }
    return i;
}

int sort_stack_top_greater_n_pos(t_stack *stack, int num)
{
    t_stack *tmp = stack;
    int i = 0;

    if (!tmp)
        return (-1);
    while (tmp && num > tmp->num)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

int sort_stack_top_less_n_pos(t_stack *stack, int num)
{
    t_stack *tmp = stack;
    int i = 0;

    if (!tmp)
        return (-1);
    while (tmp && num < tmp->num)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

int sort_stack_btm_greater_n_pos(t_stack *stack, int num, int len)
{
    t_stack *last = stack_last(stack);
    if (!last)
        return (-1);
    while (len && last->num > num)
    {
        len--;
        last = stack_last_n(stack, len - 1);
    }
    return (len);//+ // return 0 - ERROR????
}

int sort_stack_btm_greater_n_pos222(t_stack *stack, int num, int len)
{
    t_stack *last = stack_last(stack);
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

int sort_stack_btm_greater_n_pos333(t_stack *stack, int num, int len)
{
    t_stack *last = stack_last(stack);
    if (!last)
        return (-1);
    //printf("num: %d, len: %d, last num: %d\n", num, len, last->num);
    if (last->num < num)
    {
        while (len && last->num > num)
        {
            //printf("--num: %d, len: %d\n", num, len);
            len--;
            last = stack_last_n(stack, len - 1);
        }
    }
    return (len); //+ // return 0 - ERROR????
}

int sort_stack_btm_less_n_pos333(t_stack *stack, int num, int len)
{
    t_stack *last = stack_last(stack);
    if (!last)
        return (-1);
    //printf("num: %d, len: %d, last num: %d\n", num, len, last->num);
    if (last->num < num)
    {
        while (len && last->num < num)
        {
            //printf("--num: %d, len: %d\n", num, len);
            len--;
            last = stack_last_n(stack, len - 1);
        }
    }
    return (len); //+ // return 0 - ERROR????
}

void sort_3(t_stack **stack)
{
    int n1;
    int n2;
    int n3;

    if (!stack || !*stack || stack_count(*stack) != 3)
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
    else
        return ;
}

void sort_2(t_stack **stack_a)
{
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

void push_b(t_stack **stack_a, t_stack **stack_b, int *a_count, int *b_count)
{
    if (!stack_a || !stack_b || !a_count || !b_count)
        return;
    pb(stack_a, stack_b);
    *a_count -= 1;
    *b_count += 1;
}

int moves_top_top(int top_a, int top_b)
{
    if (top_a >= top_b)
        return top_a;
    return top_b;
}

int moves_btm_btm(int btm_a, int btm_b)
{
    if (btm_a >= btm_b)
        return btm_a;
    return btm_b;
}

int moves_top_btm(int top_a, int btm_b)
{
    return top_a + btm_b;
}

int moves_btm_top(int btm_a, int top_b)
{
    return btm_a + top_b;
}

void set_minimum_moves(t_stack *temp, int top_moves_a, int btm_moves_a, int top_moves_b, int btm_moves_b)
{
    int min_moves = 0;
    min_moves = moves_top_top(top_moves_a, top_moves_b);
    temp->is_top_a = 1;
    temp->is_top_b = 1;
    int min_btm_btm = moves_btm_btm(btm_moves_a, btm_moves_b);
    if (min_moves > min_btm_btm)
    {
        min_moves = min_btm_btm;
        temp->is_top_a = 0;
        temp->is_top_b = 0;
    }
    int min_top_btm = moves_top_btm(top_moves_a, btm_moves_b);
    if (min_moves > min_top_btm)
    {
        min_moves = min_top_btm;
        temp->is_top_a = 1;
        temp->is_top_b = 0;
    }
    int min_btm_top = moves_btm_top(btm_moves_a, top_moves_b);
    if (min_moves > min_btm_top)
    {
        min_moves = min_btm_top;
        temp->is_top_a = 0;
        temp->is_top_b = 1;
    }
    temp->moves = min_moves;
}

void set_cheapest_position(t_stack *stack_a, t_stack *stack_b, int a_count, int b_count, int b_min, int b_max)
{
    t_stack *temp;
    int top_moves_a;
    int btm_moves_a;
    int top_moves_b;
    int btm_moves_b;

    top_moves_a = 0;
    temp = stack_a;
    while (temp)
    {
        btm_moves_a = a_count - top_moves_a;
        if (btm_moves_a == a_count)
            btm_moves_a = 0;
        top_moves_b = pos_for_n_in_sort_stack(stack_b, temp->num, b_min, b_max, b_count);
        btm_moves_b = b_count - top_moves_b;
        if (btm_moves_b == b_count)
            btm_moves_b = 0;
        set_minimum_moves(temp, top_moves_a, btm_moves_a, top_moves_b, btm_moves_b);
        temp = temp->next;
        top_moves_a++;
    }
}

int find_cheapest_position(t_stack *stack_a, t_stack *stack_b, int a_count, int b_count, int b_min, int b_max)
{
    int i;
    t_stack *temp;
    int min;
    int min_i;
    set_cheapest_position(stack_a, stack_b, a_count, b_count, b_min, b_max);

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

t_stack *item_in_stack_by_pos(t_stack *stack, int pos)
{
    t_stack *tmp = stack;
    if (!tmp)
        return NULL;
    int i = 0;
    while (i < pos)
    {
        tmp = tmp->next;
        i++;
    }
    return tmp;
}

void rotate_stacks(t_stack push_item, int position, t_stack **stack_a, t_stack **stack_b, int a_count, int b_count, int b_min, int b_max)
{
    int top_moves_a;
    int btm_moves_a;
    int top_moves_b;
    int btm_moves_b;

    top_moves_a = position;
    btm_moves_a = a_count - position;
    if (btm_moves_a == a_count)
            btm_moves_a = 0;

    top_moves_b = pos_for_n_in_sort_stack(*stack_b, push_item.num, b_min, b_max, b_count);
    btm_moves_b = b_count - top_moves_b;
    if (btm_moves_b == b_count)
        btm_moves_b = 0;
    
    if (push_item.is_top_a && push_item.is_top_b)
    {
        if (top_moves_a >= top_moves_b)
        {
            while (top_moves_a-- > 0)
            {
                if (top_moves_b-- > 0)
                    rr(stack_a, stack_b);
                else
                    ra(stack_a);
            }
        }
        else
        {
            while (top_moves_b-- > 0)
            {
                if (top_moves_a-- > 0)
                    rr(stack_a, stack_b);
                else
                    rb(stack_b);
            }
        }
    }
    else if (!push_item.is_top_a && !push_item.is_top_b)
    {
        if (btm_moves_a >= btm_moves_b)
        {
            while (btm_moves_a-- > 0)
            {
                if (btm_moves_b-- > 0)
                    rrr(stack_a, stack_b);
                else
                    rra(stack_a);
            }
        }
        else
        {
            while (btm_moves_b-- > 0)
            {
                if (btm_moves_a-- > 0)
                    rrr(stack_a, stack_b);
                else
                    rrb(stack_b);
            }
        }
    }
    else if (push_item.is_top_a && !push_item.is_top_b)
    {
        while (top_moves_a-- > 0)
            ra(stack_a);
        while (btm_moves_b-- > 0)
            rrb(stack_b); 
    }
    else if (!push_item.is_top_a && push_item.is_top_b)
    {
        while (top_moves_b-- > 0)
            rb(stack_b);
        while (btm_moves_a-- > 0)
            rra(stack_a); 
    }
}

void test(t_stack **stack_a, t_stack **stack_b)
{
    int a_count;
    int b_count;
    int b_min;
    int b_max;
    int position;
    t_stack *push_item;

    a_count = stack_count(*stack_a);
    b_count = 0;
    b_min = 2147483647;
    b_max = -2147483648;
    while (a_count > 3)
    {
        if (b_count > 1)
        {
            position = find_cheapest_position(*stack_a, *stack_b, a_count, b_count, b_min, b_max);
            push_item = item_in_stack_by_pos(*stack_a, position);
            if(push_item)
                rotate_stacks(*push_item, position, stack_a, stack_b, a_count, b_count, b_min, b_max);
        }
        push_b(stack_a, stack_b, &a_count, &b_count);
        set_min_max(*stack_b, &b_min, &b_max);
    }
    sort_back(stack_a, stack_b);
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
            int position = stack_n_pos(*stack_a, min_a); //+
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
        
        // NEW MIN MAX
        if ((*stack_a)->num < min_a)
            min_a = (*stack_a)->num;
        else if ((*stack_a)->num > max_a)
            max_a = (*stack_a)->num;
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

int pos_for_n_in_sort_stack(t_stack *stack, int num, int min, int max, int count)
{
    int position = 0;
    if (num < min || num > max)
        position = stack_n_pos(stack, max);
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
                        position = sort_stack_btm_less_n_pos333(stack, num, count);
                    else
                    {
                        if (num < l->num && num < l->num)
                            return 0;
                        else {
                            printf("--- 6 ---\n");
                            position = sort_stack_btm_greater_n_pos333(stack, num, count);
                        }
                    }
                }
        }
    }
    return position;
}

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
        test(stack_a, stack_b);
    return ;
}