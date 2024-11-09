/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:49 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/08 14:23:46 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: delete counter
extern int counter;

int pos_for_n_in_sort_stack(t_stack *stack, int num, int min, int max, int count);

void sort_back(t_stack **stack_a, t_stack **stack_b);

int moves_in_b(t_stack **stack_a, t_stack **stack_b, int min_b, int max_b, int b_counter);

int moves_in_a(t_stack **stack_a, t_stack **stack_b, int max_b, int a_counter);

int stack_max_n(t_stack *stack)
{
    t_stack *tmp = stack;
    int max = -2147483648;
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
    t_stack *tmp = stack;
    int min = 2147483647;
    while (tmp)
    {
        if (tmp->num < min)
            min = tmp->num;
        tmp = tmp->next;
    }
    return min;
}

int unsort_stack_top_greater_n_pos(t_stack *stack, int num)
{
    t_stack *tmp = stack;
    int i = 0;
    while (tmp && num > tmp->num)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

int unsort_stack_btm_greater_n_pos(t_stack *stack, int num, int len)
{
    t_stack *last = stack_last(stack);
    if (!last)
        return (0);
    if (last->num < num)
    {
        while (len && last->num < num)
        {
            last = stack_last_n(stack, (len--) - 1);
        }
        return (len);
    }
    else
    {
        return (len - 1);
    }
}

int unsort_stack_top_pos_between(t_stack *stack, int min, int max)
{
 ///printf("----- unsort_stack_top_pos_between ------\n");
 ///printf("min: %d, max: %d\n", min, max);
    t_stack *tmp = stack;

    if (!tmp)
        return -1;
    int i = 0;  
    while (tmp)
    {
        if (tmp->num >= min && tmp->num <= max)
        {
            ///printf("last->num: %d, i: %d\n", tmp->num, i);
            return i;
        }
        tmp = tmp->next;
        i++;
    }
    return -1;
}

int unsort_stack_btm_pos_between(t_stack *stack, int min, int max, int len)
{
    /////printf("----- unsort_stack_btm_pos_between ------\n");
    /////printf("min: %d, max: %d, len: %d\n", min, max, len);

    t_stack *last = stack_last(stack);

    if (!last)
    {
    //  ///printf("Error !last\n");
        return (0);
    }

    while (len && last)
    {
        if (last->num >= min && last->num <= max)
        {
        //  ///printf("last->num: %d, len: %d\n", last->num, len);
            return --len;
        }
        len--;
        last = stack_last_n(stack, len - 1);
    }
    return (len);
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

void sort_3(t_stack **stack, char c)
{
    int n1;
    int n2;
    int n3;

    if (!stack || !*stack || stack_count(stack) != 3)
        return; 
    n1 = (*stack)->num;
    n2 = (*stack)->next->num;
    n3 = (*stack)->next->next->num;

    if (n1 < n2 && n2 > n3 && n1 < n3)
    {
        //  1
        //  3
        //  2
        /////printf("------ sort 0.1 ------\n");
        if (c == 'a')
        {
            rra(stack);
            sa(*stack);
        }
        else
        {
            rb(stack);
        }
    }
    else if (n1 < n2 && n2 > n3 && n1 > n3)
    {
        //  2
        //  3
        //  1
        /////printf("------ sort 0.2 ------\n");
        if (c == 'a')
        {
            rra(stack);
        }
        else
        {
            sb(*stack);
        }
    }
    else if (n1 > n2 && n2 < n3 && n1 < n3)
    {
        //  2
        //  1
        //  3
        /////printf("------ sort 0.3 ------\n");
        if (c == 'a')
        {
            sa(*stack);
        }
        else
        {
            rrb(stack);
        }
    }
    else if (n1 > n2 && n2 < n3 && n1 > n3)
    {
        //  3
        //  1
        //  2
        /////printf("------ sort 0.4 ------\n");
        if (c == 'a')
        {
            ra(stack);
        }
        else
        {
            sb(*stack);
            rb(stack);
        }
    }
    else if (n1 > n2 && n2 > n3 && n1 > n3)
    {
        //  3
        //  2
        //  1
        /////printf("------ sort 0.5 ------\n");
        if (c == 'a')
        {
            ra(stack);
            sa(*stack);
        }
        else
            return;
    }
    else
    {
        //  1
        //  2
        //  3
        /////printf("------ sort 0.0 ------\n");

        if (c == 'a')
            return;
        else
        {
            rb(stack);
            sb(*stack);
        }
    }
}

void sort_2(t_stack **stack_a)
{
    if ((*stack_a)->num > (*stack_a)->next->num)
        sa(*stack_a);
}

int stack_range(int min, int max)
{
    int i = 0;

    while(min <= max)
    {
        i++;
        min++;
    }
    return i;
}

int count_n_in_range_in_stask(t_stack *stack, int min, int max)
{
    int i = 0;
    t_stack *temp = stack;

    if (!temp)
        return (0);
    while(temp)
    {
        if (temp->num >= min && temp->num <= max)
            i++;
        temp = temp->next;
    }
    return i;
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    int r_c = 10;
    int max = stack_max_n(*stack_a);
    int min = stack_min_n(*stack_a);
    int all_range =  stack_range(min, max);
    int range = all_range / r_c;

    int count = 0;
    int i = 0;
    
    int a_count = stack_count(stack_a);
    int b_count = stack_count(stack_b);
    // ///printf("max: %d, min: %d, all_range: %d, range: %d, a_count: %d\n", max, min, all_range, range, a_count);

    while (i < r_c)
    {
        //printf("------ RANGE %d ------\n", i);
        if (i == r_c - 1)
        {
            count = count_n_in_range_in_stask(*stack_a, min + (range * i), max);
            //printf("count: %d, in range %d - %d\n", count, min + (range * i), max);
        }
        else
        {
            count = count_n_in_range_in_stask(*stack_a, min + (range * i), min + (range * (i + 1)));
            //printf("count: %d, in range %d - %d\n", count, min + (range * i), min + (range * (i + 1)));
        }
        if (count > 0)//todo удалить этот if else?
        {
            while (count > 0 && a_count > 3)
            {
                //printf("------ numbers: %d ------\n", count);
                
                int top_pos;
                int btm_pos;
                if (i == r_c - 1)
                {
                    top_pos = unsort_stack_top_pos_between(*stack_a, min + (range * i), max);
                    btm_pos = unsort_stack_btm_pos_between(*stack_a, min + (range * i), max, a_count);

                }
                else
                {
                    top_pos = unsort_stack_top_pos_between(*stack_a, min + (range * i), min + (range * (i + 1)));
                    btm_pos = unsort_stack_btm_pos_between(*stack_a, min + (range * i), min + (range * (i + 1)), a_count);
                }
                //printf("top moves: %d, btm moves: %d | top pos: %d, btm pos: %d | a_count: %d\n", top_pos, a_count - btm_pos, top_pos, btm_pos, a_count);

                if (btm_pos == 0 || top_pos == -1)
                {
                    //printf("numbers NOT FOUND\n");
                    break;
                }
                else if (top_pos <= a_count - btm_pos)
                {
                    //printf("--- 1.1 ---\n");

                    while (top_pos-- > 0)
                    {
                        //printf("-moves: %d\n", top_pos);
                        ra(stack_a);
                    }
                    pb(stack_a, stack_b);
                    a_count--;
                    b_count++;
                }
                else if (top_pos > a_count - btm_pos)
                {
                    //printf("--- 1.2 ---\n");
                    while ((a_count - btm_pos) > 0)
                    {
                        //printf("-moves: %d\n", a_count - btm_pos);
                        rra(stack_a);
                        btm_pos++;
                    }
                    pb(stack_a, stack_b);
                    a_count--;
                    b_count++;
                }

                // if (b_count > 1 && a_count > 3)
                // {
                //     if ((*stack_a)->num > (*stack_a)->next->num)
                //         ss(*stack_a, *stack_b);
                    
                //     // else if ((*stack_a)->num > (*stack_a)->next->num)
                //     //     sb(*stack_b);
                // }
                count--;
                //printf("\n-- stack_a after --\n");
                //print_stack(*stack_a);
                //printf("\n-- stack_b after --\n");
                //print_stack(*stack_b);

               
            }
            //printf("-END numbers count: %d --\n", count);
        }
        else// todo удалить этот if else?
        {
            //printf("-NO numbers in range\n");            
        }
        i++;
    }

    
    // printf("\n-- stack_a after range sort --\n");
    // print_stack(*stack_a);
    // printf("\n-- stack_b after range sort --\n");
    // print_stack(*stack_b);

    sort_back(stack_a, stack_b);
}

void sort_back(t_stack **stack_a, t_stack **stack_b)
{
    //printf("\n----- SORT BACK -----\n");
    sort_3(stack_a, 'a');

   // printf("\n-- stack_a after SORT 3 --\n");
   // print_stack(*stack_a);

    int min_a = stack_min_n(*stack_a);
    int max_a = stack_max_n(*stack_a);
    int a_count = stack_count(stack_a);
  //  int b_count = stack_count(stack_b);

    while (*stack_b)
    {
       // printf("--- for NUM %d ---\n", (*stack_b)->num);
        if ((*stack_b)->num < min_a || (*stack_b)->num > max_a)
        {
            //printf("--- 1 ---\n");
            int position = stack_n_pos(*stack_a, min_a); //+
         //   printf("position: %d, counter / 2: %d\n", position, a_count / 2);
            if (position < a_count / 2 || (a_count % 2 != 0 && (a_count / 2) == position))
            {
               // printf("--- + ! 1.1.1 ---\n");
                int i = 0;
                while (i < position)
                {
                    ra(stack_a);
                    i++;
                }
            }
            else
            {
            //    printf("--- ! 1.1.2 ---\n");
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
            //printf("--- 2 ---\n");
            if ((*stack_b)->num < (*stack_a)->num)
            {
               // printf("--- 2.1 ---\n");

                t_stack *last = stack_last(*stack_a);
                if (last)
                {
                    if (last->num > (*stack_b)->num)
                    {
                        //printf("--- 2.1.1 ---\n");
                        int position = sort_stack_btm_greater_n_pos(*stack_a, (*stack_b)->num, a_count);
                        //printf("position: %d, count: %d, counter / 2: %d\n", position, a_count, a_count / 2);

                        if (position < a_count / 2 || (a_count % 2 != 0 && (a_count / 2) == position))
                        {
                           // printf("--- + 2.1.1.11 ---\n");
                            int i = 0;
                            while (i < position)
                            {
                                ra(stack_a);
                                i++;
                            }
                        }
                        else
                        {
                           // printf("--- + 2.1.1.22 ---\n");
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
                       // printf("--- ! 2.1.2 no move needed ---\n");
                    }
                }
            }
            else
            {
                int position = sort_stack_top_greater_n_pos(*stack_a, (*stack_b)->num);
                //printf("position: %d, counter / 2: %d\n", position, a_count / 2);
                if (position < a_count / 2 || (a_count % 2 != 0 && a_count / 2 == position))
                {
                    //printf("--- ! 2.2.1 ---\n");
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
                        //    printf("--- ! 2.2.2.1 ---\n");
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
                           // printf("--- + 2.2.2.2 ---\n");
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
        {
            min_a = (*stack_a)->num;
        }
        else if ((*stack_a)->num > max_a)
        {
            max_a = (*stack_a)->num;
        }

        //printf("\n-- stack_a after sort --\n");
        //print_stack(*stack_a);
        // printf("\n-- stack_b after sort --\n");
        // print_stack(*stack_b);
    }

    //printf("--- 0000 last ---\n");

    //TODO!!!!! doublicate
    int position = stack_n_pos(*stack_a, min_a); //+
    //printf("position: %d, counter / 2: %d\n", position, a_count / 2);
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
    {
        position = stack_n_pos(stack, max);
        // if (pos_exact < count / 2 || (count % 2 != 0 && (count / 2) == pos_exact))
        // {
        //     while (i < pos_exact)
        //     {
        //         //rb
        //         i++;
        //     }
        // }
        // else
        // {
        //     while (i < count - pos_exact)
        //     {
        //         //rrb
        //         i++;
        //     }
        // }
    }
    else
    {
        if (num < stack->num)
        {
            position = sort_stack_top_greater_n_pos(stack, num);
            // if (position < (count / 2) || (count % 2 != 0 && (count / 2) == position))
            // {
            //     while (i < position)
            //     {
            //         //rb
            //         i++;
            //     }
            // }
            // else
            // {
            //     while (i < count - position)
            //     {
            //         //rrb
            //         i++;
            //     }
            // }
        }
        else
        {
            position = sort_stack_btm_greater_n_pos(stack, num, count);
            // if (position < count / 2 || (count % 2 != 0 && count / 2 == position))
            // {
            //     while (i < position)
            //     {
            //         //rb
            //         i++;
            //     }
            // }
            // else
            // {
            //     t_stack *l = stack_last(stack);
            //     if (l)
            //     {
            //         if (l->num < num)
            //         {
            //             int s = count - position;
            //             while (i < s)
            //             {
            //                 //rrb
            //                 i++;
            //             }
            //         }
            //     }
            // }
        }
    }
    return position;
}