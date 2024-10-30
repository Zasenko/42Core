#include "push_swap.h"

extern int counter;

static void	rotate(t_stack **stack)
{
	int		count;
	t_stack	*last;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	count = stack_count(stack);
	if (count < 2)
		return ;
	last = stack_last(*stack);
	if (!last)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	last->next = temp;
}

void	ra(t_stack **stack_a)
{
	printf("ra | ");
	rotate(stack_a);
	counter++;
}

void	rb(t_stack **stack_b)
{
	printf("rb | ");
	rotate(stack_b);
	counter++;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	printf("rr | ");
	rotate(stack_a);
	rotate(stack_b);
	counter++;
}