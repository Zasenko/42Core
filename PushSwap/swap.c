#include "push_swap.h"

extern int counter;

static void	swap(t_stack *stack)
{
	int	temp;
	int	c;

	if (!stack)
		return ;
	c = stack_count(&stack);
	if (c < 2)
		return ;
	temp = *(stack)->num;
	*(stack)->num = *(stack)->next->num;
	*(stack)->next->num = temp;
	return ;
}

void	sa(t_stack *stack_a)
{
	printf("sa | ");
	swap(stack_a);
	counter++;
}

void	sb(t_stack *stack_b)
{
	printf("sa | ");
	swap(stack_b);
	counter++;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	printf("ss | ");
	swap(stack_a);
	swap(stack_b);
	counter++;
}