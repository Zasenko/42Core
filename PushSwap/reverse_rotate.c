#include "push_swap.h"

t_stack	*stack_last_n(t_stack *stack, int count)
{
	t_stack	*temp;

	temp = stack;
	if (!temp)
		return (NULL);
	while (temp->next != NULL && count--)
		temp = temp->next;
	return (temp);
}

static void	reverse_rotate(t_stack **stack)
{
	int		count;
	t_stack	*last;
	t_stack	*last2;

	if (!stack || !*stack)
		return ;
	count = stack_count(stack);
	if (count < 2)
		return ;
	last = stack_last(*stack);
	last2 = stack_last_n(*stack, count - 2);
	if (!last || !last2)
		return ;
	last->next = stack[0];
	*stack = last;
	last2->next = NULL;
}

void	rra(t_stack **stack_a)
{
	printf("rra\n");
	reverse_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	printf("rrb\n");
	reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	printf("rrr\n");
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}