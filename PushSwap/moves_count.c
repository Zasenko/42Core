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

static int	moves_top_btm(int top_a, int btm_b)
{
	return (top_a + btm_b);
}

static int	moves_btm_top(int btm_a, int top_b)
{
	return (btm_a + top_b);
}

static void set_minimum_moves(t_stack *temp, int is_top_a, int is_top_b)
{
    if (temp)
    {
        temp->is_top_a = is_top_a;
        temp->is_top_b = is_top_b;   
    }
}

//-+
void find_minimum_moves(t_stack *temp, t_moves moves)
{
    int min_moves;
    int min_btm_btm;
    int min_top_btm;
    int min_btm_top;
     
    min_moves = moves_top_top(moves.top_moves_a, moves.top_moves_b);
    set_minimum_moves(temp, 1, 1);
    if (min_btm_btm = moves_btm_btm(moves.btm_moves_a, moves.btm_moves_b), min_moves > min_btm_btm)
    {
        min_moves = min_btm_btm;
        set_minimum_moves(temp, 0, 0);
    }
    if (min_top_btm = moves_top_btm(moves.top_moves_a, moves.btm_moves_b), min_moves > min_top_btm)
    {
        min_moves = min_top_btm;
        set_minimum_moves(temp, 1, 0);
    }
    if (min_btm_top = moves_btm_top(moves.btm_moves_a, moves.top_moves_b), min_moves > min_btm_top)
    {
        min_moves = min_btm_top;
        set_minimum_moves(temp, 0, 1);
    }
    temp->moves = min_moves;
}