#include "push_swap.h"

static void	push(t_stack **stack_1, t_stack **stack_2)
{
	int		c;
	t_stack	*temp1;

	if (!stack_1)
		return ;
	c = stack_count(stack_1);
	if (c < 1)
		return ;
	temp1 = stack_1[0];
	stack_1[0] = (stack_1[0])->next;
	stack_add_front(stack_2, temp1);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	printf("pa\n");
	push(stack_b, stack_a);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	printf("pb\n");
	push(stack_a, stack_b);
}