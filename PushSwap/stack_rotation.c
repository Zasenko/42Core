#include "push_swap.h"

static void rotate_top_top(t_stack **stack_a, t_stack **stack_b, int top_moves_a, int top_moves_b)
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

static void rotate_top_btm(t_stack **stack_a, t_stack **stack_b, int top_moves_a, int btm_moves_b)
{
    while (top_moves_a-- > 0)
            ra(stack_a);
    while (btm_moves_b-- > 0)
        rrb(stack_b);
}

static void rotate_btm_btm(t_stack **stack_a, t_stack **stack_b, int btm_moves_a, int btm_moves_b)
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

static void rotate_btm_top(t_stack **stack_a, t_stack **stack_b, int btm_moves_a, int top_moves_b)
{
    while (top_moves_b-- > 0)
        rb(stack_b);
    while (btm_moves_a-- > 0)
        rra(stack_a); 
}

void rotate_stacks(t_stack push_item, t_stack **stack_a, t_stack **stack_b, t_prop prop)
{
    int top_moves_a;
    int btm_moves_a;
    int top_moves_b;
    int btm_moves_b;

    top_moves_a = push_item.index;
    btm_moves_a = prop.a_count - push_item.index;
    if (btm_moves_a == prop.a_count)
            btm_moves_a = 0;

    top_moves_b = pos_for_n_in_stack_b(*stack_b, push_item.num, prop);
    btm_moves_b = prop.b_count - top_moves_b;
    if (btm_moves_b == prop.b_count)
        btm_moves_b = 0;
    
    if (push_item.is_top_a && push_item.is_top_b)
        rotate_top_top(stack_a, stack_b, top_moves_a, top_moves_b);
    else if (!push_item.is_top_a && !push_item.is_top_b)
        rotate_btm_btm(stack_a, stack_b, btm_moves_a, btm_moves_b);
    else if (push_item.is_top_a && !push_item.is_top_b)
        rotate_top_btm(stack_a, stack_b, top_moves_a, btm_moves_b);
    else if (!push_item.is_top_a && push_item.is_top_b)
        rotate_btm_top(stack_a, stack_b, btm_moves_a, top_moves_b);
}