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

// 5 1 11 2 8 18 15 12 4 14 17 3 10 7 19 16 6 20 13 9

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
    
    int max = stack_max_n(*stack_a);
    int min = stack_min_n(*stack_a);
    int all_range =  stack_range(min, max);
    int range = all_range / 10;
    
    int count = 0;
    int i = 0;
    
    int a_count = stack_count(stack_a);

   // ///printf("max: %d, min: %d, all_range: %d, range: %d, a_count: %d\n", max, min, all_range, range, a_count);
    
    while (i < 10)
    {
        //printf("------ RANGE %d ------\n", i);        
        if (i == 9)
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
                if (i == 9)
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
                }
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

void test_alg(t_stack **stack_a, t_stack **stack_b)
{
    int a_counter;
    int b_counter;
    int min_b;
    int max_b;

    a_counter = stack_count(stack_a);
    b_counter = 0;
    min_b = 0;
    max_b = 0;

    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    a_counter = a_counter - 2;
    b_counter = 2;

    if ((*stack_b)->num < (*stack_b)->next->num)
    {
        max_b = (*stack_b)->next->num;
        min_b = (*stack_b)->num;
    }
    else
    {
        max_b = (*stack_b)->num;
        min_b = (*stack_b)->next->num;
    }

    int time = 1;
    while (a_counter > 3)
    {
        printf("\n============== %d ==============\n", time);

        pb(stack_a, stack_b);
        a_counter--;
        b_counter++;

         /////printf("\n--- stack_a ---\n");
    	 //print_stack(*stack_a);

        // MIN MAX_b FROM TOP A
        if ((*stack_b)->num < min_b)
        {
            min_b = (*stack_b)->num;
        }
        else if ((*stack_b)->num > max_b)
        {
            max_b = (*stack_b)->num;
        }

        if (b_counter == 3)
        {
            sort_3(stack_b, 'b');
            // ///printf("\n--- stack_a after ---\n");
            // print_stack(*stack_a);
            // ///printf("--- stack_b after ---\n");
            // print_stack(*stack_b);
        }

         /////printf("\n-stack_b-\n");
         //print_stack(*stack_b);


        /////printf("max_b = %d, min_b = %d\n", max_b, min_b);

        if (a_counter > 3)
        {
			if ((*stack_a)->num < (*stack_a)->next->num)
			{
				sa(*stack_a);
				//ra(stack_a);
			}
			// if ((*stack_a)->num > (*stack_b)->num)
			// {
				if ((*stack_a)->num > (*stack_a)->next->num && (*stack_a)->next->num > (*stack_b)->num)
				{
					ra(stack_a);
					ra(stack_a);
				}
			// 	else
			// 		ra(stack_a);
			// }

			if ((*stack_a)->num > (*stack_b)->num)
			{
				ra(stack_a);
			}

            // MOVES COUNTING
            int m_in_a = moves_in_a(stack_a, stack_b, max_b, a_counter);
            int m_in_b = moves_in_b(stack_a, stack_b, min_b, max_b, b_counter);

            /////printf("--------- MOVE IN A: %d\n--------- MOVE IN B: %d\n", m_in_a, m_in_b);

            if (m_in_a >= 0 && m_in_a < m_in_b)
            {
                /////printf("========= ROTATE A ==========\n");
                if ((*stack_b)->num == max_b)
                {
                    /////printf("---- 1 ----\n");
                    int top_pos = unsort_stack_top_greater_n_pos(*stack_a, max_b);
                    int btm_pos = unsort_stack_btm_greater_n_pos(*stack_a, max_b, a_counter);
                    /////printf("top_pos: %d, btm_pos: %d | a_counter - btm_pos: %d\n", top_pos, btm_pos, a_counter - btm_pos);
                    if (btm_pos > 0 || top_pos == a_counter)
                    {
                        if (top_pos <= a_counter - btm_pos)
                            {
                                while (top_pos-- > 0)
                                    ra(stack_a);
                            }
                            if (top_pos > a_counter - btm_pos)
                            {
                                while (a_counter - btm_pos > 0)
                                {
                                //  ///printf("---- 00.2 ----\n");
                                    rra(stack_a);
                                    btm_pos++;
                                }
                            }
                    }
                }
                else
                {
                    /////printf("---- 2 ----\n");
                    t_stack *last = stack_last(*stack_b);
                    if (last)
                    {
                        int top_pos = unsort_stack_top_pos_between(*stack_a, (*stack_b)->num, last->num);
                        int btm_pos = unsort_stack_btm_pos_between(*stack_a, (*stack_b)->num, last->num, a_counter);

                        /////printf("top_pos: %d, btm_pos: %d | btm moves: %d\n", top_pos, btm_pos, a_counter - btm_pos);

                        if (btm_pos > 0 || top_pos >= 0)
                        {
                            if (top_pos <= a_counter - btm_pos)
                            {
                                while (top_pos-- > 0)
                                    ra(stack_a);
                            }
                            if (top_pos > a_counter - btm_pos)
                            {
                                while ((a_counter - btm_pos) > 0)
                                {
                                    /////printf("---- 00.1 ----\n");
                                    rra(stack_a);
                                    btm_pos++;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                /////printf("========= ROTATE B ==========\n");
                if ((*stack_a)->num < min_b || (*stack_a)->num > max_b)
                {
                 /////printf("------ 1 ------\n");
                    int pos_exact = stack_n_pos(*stack_b, max_b);
                 /////printf("max_b position: %d, counter / 2: %d\n", pos_exact, b_counter / 2);

                    if (pos_exact < b_counter / 2 || (b_counter % 2 != 0 && (b_counter / 2) == pos_exact))
                    {
                      /////printf("------1.1------\n");
                        int i = 0;
                        while (i < pos_exact)
                        {
                            rb(stack_b);
                            i++;
                        }
                    }
                    else
                    {
                      /////printf("------1.2------\n");
                        int i = 0;
                        while (i < b_counter - pos_exact)
                        {
                            rrb(stack_b);
                            i++;
                        }
                    }
                }
                else
                {
                  /////printf("------ 2 ------\n");
                    if ((*stack_a)->num < (*stack_b)->num)
                    {
                      /////printf("------2.1------\n");
                        int max_b_pos = sort_stack_top_greater_n_pos(*stack_b, (*stack_a)->num);
                      /////printf("b top > position: %d, counter / 2: %d\n", max_b_pos, b_counter / 2);
                        if (max_b_pos < (b_counter / 2) || (b_counter % 2 != 0 && (b_counter / 2) == max_b_pos))
                        {
                          /////printf("------2.1.1------\n");
                            int i = 0;
                            while (i < max_b_pos)
                            {
                                rb(stack_b);
                                i++;
                            }
                        }
                        else
                        {
                         /////printf("------2.1.2------\n");
                            int i = 0;
                            while (i < b_counter - max_b_pos)
                            {
                                rrb(stack_b);
                                i++;
                            }
                        }
                    }
                    else
                    {
                      /////printf("------2.2------\n");
                        int min_pos = sort_stack_btm_greater_n_pos(*stack_b, (*stack_a)->num, b_counter);
                      /////printf("b btm > position: %d, counter / 2: %d\n", min_pos, b_counter / 2);
                        if (min_pos < b_counter / 2 || (b_counter % 2 != 0 && b_counter / 2 == min_pos))
                        {
                          /////printf("------2.2.1------\n");
                            int i = 0;
                            while (i < min_pos)
                            {
                                rb(stack_b);
                                i++;
                            }
                        }
                        else
                        {
                          /////printf("------2.2.2------\n");
                            t_stack *l = stack_last(*stack_b);
                            if (l)
                            {
                              /////printf("------2.2.2.1------\n");
                              /////printf("stack_last num: %d\n", l->num);
                                if (l->num < (*stack_a)->num)
                                {
                                  /////printf("------2.2.2.1.1 !!!!!!!! ------\n");
                                    int s = b_counter - min_pos;
                                    int i = 0;
                                    while (i < s)
                                    {
                                        rrb(stack_b);
                                        i++;
                                    }
                                }
                                else
                                {
                                    /////printf("------2.2.2.1.2.0 |Error|------\n");
                                }
                            }
                            else
                            {
                                /////printf("------2.2.2.2.0 |Error|------\n");
                            }
                        }
                    }
                }
            
            }

            // ///printf("\n--- stack_a after ---\n");
            // print_stack(*stack_a);
            /////printf("--- stack_b after ---\n");
            //print_stack(*stack_b);
        }
        else
        {
            /////printf("\n====== LAST 3 in stack a =====\n");

            /////printf("------ 0 ------\n");
            int pos_exact = stack_n_pos(*stack_b, max_b);
            /////printf("max_b position: %d, counter / 2: %d\n", pos_exact, b_counter / 2);
            if (pos_exact < (b_counter / 2) || (b_counter % 2 != 0 && (b_counter / 2) == pos_exact))
            {
                /////printf("------0.1------\n");
                int i = 0;
                while (i < pos_exact)
                {
                    rb(stack_b);
                    i++;
                }
            }
            else
            {
                /////printf("------0.2------\n");
                int i = 0;
                while (i < b_counter - pos_exact)
                {
                    rrb(stack_b);
                    i++;
                }
            }
        }
        time++; // TODO delete
    }

    /////printf("\n=========== SORT LAST 3 in stack a ==========\n");
    /////printf("\n------ sort 3 a ------\n");
    sort_3(stack_a, 'a');
    /////printf("\n--- stack_a after ---\n");
    //print_stack(*stack_a);

    int count_3 = 0;

    /////printf("\n============== SORT 3 in A if last in A > first in B ==============\n");

    /////printf("------ sort 3.1 ------\n");
    while (b_counter > 0)
    {
        t_stack *last = stack_last(*stack_a);
        if (last)
        {
            if (last->num > (*stack_b)->num && count_3 < 3)
            {
                rra(stack_a);
                count_3++;
            }
            else
            {
                pa(stack_a, stack_b);
                b_counter--;
            }
        }
    }
    
    /////printf("\n--- stack_a after ---\n");
    //print_stack(*stack_a);
    /////printf("--- stack_b after ---\n");
    //print_stack(*stack_b);

    /////printf("\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=//=/=/=/\n");
    /////printf("------ sort 3.2 ------\n");
    t_stack *last_a = stack_last(*stack_a);
    while (last_a->num < (*stack_a)->num)
    {
        rra(stack_a);
        last_a = stack_last(*stack_a);
    }
    
    /////printf("\n--- stack_a after ---\n");
    //print_stack(*stack_a);
    /////printf("--- stack_b after ---\n");
    //print_stack(*stack_b);
    /////printf("\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=//=/=/=/\n");
}

/*

27 20 6 21 23 7 11 4 1 10 24 30 8 5 2 19 22 18 3 17 28 26 15 9 29 14 13 16 25 12

169
139

19 11 3 16 12 8 13 14 6 2 1 4 15 7 5 9 17 20 18 10

75
79
67

10 3 6 14 13 20 16 8 18 1 2 17 9 4 15 11 19 7 5 12

78
73

16 8 2 4 3 19 15 13 9 6 5 20 17 14 18 11 12 10 7 1

78
73

6 8 3 11 18 19 1 9 5 2 16 14 17 20 12 13 4 7 15 10

74
72


63 80 40 34 87 90 56 42 30 73 9 13 47 45 79 59 69 67 2 58 18 24 51 28 36 98 14 33 83 8 72 100 68 85 37 1 57 94 7 49 66 82 31 23 25 70 16 46 61 93 22 50 35 41 19 26 20 99 43 52 76 84 86 6 54 27 29 53 4 38 17 12 5 60 95 74 64 55 48 75 71 89 81 91 62 77 21 97 44 65 3 11 92 32 88 96 10 78 39 15

1270
1243
1268

1188
1056

*/
int moves_in_b(t_stack **stack_a, t_stack **stack_b, int min_b, int max_b, int b_counter)
{
    int i = 0;
    /////printf("========= moves_in_b ==========\n");
    if ((*stack_a)->num < min_b || (*stack_a)->num > max_b)
    {
        /////printf("---- 1 -----\n");
        int pos_exact = stack_n_pos(*stack_b, max_b);
        if (pos_exact < b_counter / 2 || (b_counter % 2 != 0 && (b_counter / 2) == pos_exact))
        {
            /////printf("---- 1.1 -----\n");
            while (i < pos_exact)
                i++;
        }
        else
        {
            /////printf("---- 1.2 -----\n");
            while (i < b_counter - pos_exact)
                i++;
        }
    }
    else
    {
        /////printf("---- 2 -----\n");

        if ((*stack_a)->num < (*stack_b)->num)
        {
            /////printf("---- 2.1 -----\n");

            int max_b_pos = sort_stack_top_greater_n_pos(*stack_b, (*stack_a)->num);
            /////printf("max_b_pos: %d\n", max_b_pos);

            if (max_b_pos < (b_counter / 2) || (b_counter % 2 != 0 && (b_counter / 2) == max_b_pos))
            {
                /////printf("---- 2.1.1 -----\n");

                while (i < max_b_pos)
                {
                    i++;
                    /////printf("i++: %d\n", i);
                }
            }
            else
            {
                /////printf("---- 2.1.2 -----\n");
                /////printf("b_counter(%d) -  max_b_pos(%d) = %d\n", b_counter, max_b_pos, b_counter - max_b_pos);

                while (i < b_counter - max_b_pos)
                {
                    i++;
                    /////printf("i++: %d\n", i);
                }
            }
        }
        else
        {
            /////printf("---- 2.2 -----\n");

            int min_pos = sort_stack_btm_greater_n_pos(*stack_b, (*stack_a)->num, b_counter);
            /////printf("min_pos: %d\n", min_pos);
            if (min_pos < b_counter / 2 || (b_counter % 2 != 0 && b_counter / 2 == min_pos))
            {
                /////printf("---- 2.2.1 -----\n");
                while (i < min_pos)
                {
                    i++;
                    /////printf("i++: %d\n", i);
                }
            }
            else
            {
                t_stack *l = stack_last(*stack_b);
                if (l)
                {
                    /////printf("---- 2.2.2 -----\n");

                    if (l->num < (*stack_a)->num)
                    {
                        /////printf("---- 2.2.2.1 -----\n");

                        int s = b_counter - min_pos;
                        /////printf("s(%d) = b_counter(%d) - min_pos(%d)\n", s, b_counter, min_pos);
                        while (i < s)
                        {
                            i++;
                            /////printf("i++: %d\n", i);
                        }
                    }
                    else
                    {
                        /////printf("------ |Error| moves in b 2.2.2.2------\n");
                    }
                }
                else
                {
                    /////printf("------|Error| moves in b 2.2.2.0 ------\n");
                }
            }
        }
    }
    /////printf("========= moves %d ==========\n", i);

    return i;
}

int moves_in_a(t_stack **stack_a, t_stack **stack_b, int max_b, int a_counter)
{
	//int max_in_a = max_num(*stack_a);
    /////printf("========= moves_in_a ==========\n");
    if ((*stack_b)->num == max_b)
    {
        /////printf("---- 1 ----\n");
        int top_pos = unsort_stack_top_greater_n_pos(*stack_a, max_b);
        int btm_pos = unsort_stack_btm_greater_n_pos(*stack_a, max_b, a_counter);
        /////printf("top_pos: %d, btm_pos: %d | a_counter - btm_pos: %d\n", top_pos, btm_pos, a_counter - btm_pos);
        if (btm_pos == 0 || top_pos == a_counter)
        {
          /////printf("NOT FOUND moves_in_a\n");
            return -1;
        }
        if (top_pos <= a_counter - btm_pos)
            return top_pos;
        if (top_pos > a_counter - btm_pos)
            return a_counter - btm_pos;
    }
	//else if ((*stack_b)->num == max_b && max_b > max_in_a)
	//{
		//int top_pos = position_from top_unsorted_stack(*stack_a, (*stack_b)->next->num);
       // int btm_pos = btm_unsort_stack_sort_stack_btm_greater_n_pos_test(*stack_a, (*stack_b)->next->num, a_counter);
        /////printf("top: %d, btm: %d\n", top_pos, a_counter - btm_pos);
        // if (btm_pos == 0 || top_pos == -1)
        // {
        // //  ///printf("NOT FOUND moves_in_a\n");
        //     return -1;
        // }
        // if (top_pos <= a_counter - btm_pos)
        //     return top_pos + 1;
        // if (top_pos > a_counter - btm_pos)
        //     return a_counter - btm_pos + 1;
	//}
    else
    {
        /////printf("---- 2 ----\n");
        t_stack *last = stack_last(*stack_b);
        if (!last)
            return -1;

        int top_pos = unsort_stack_top_pos_between(*stack_a, (*stack_b)->num, last->num);
        int btm_pos = unsort_stack_btm_pos_between(*stack_a, (*stack_b)->num, last->num, a_counter);

        /////printf("top_pos: %d, btm_pos: %d | btm moves: %d\n", top_pos, btm_pos, a_counter - btm_pos);

        if (btm_pos == 0 || top_pos == -1)
        {
            /////printf("NOT FOUND moves_in_a\n");
            return -1;
        }
        if (top_pos <= a_counter - btm_pos)
            return top_pos;
        if (top_pos > a_counter - btm_pos)
            return a_counter - btm_pos;
    }
    return (-1);
}