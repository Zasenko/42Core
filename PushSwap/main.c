/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:07:38 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/23 13:47:30 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.

//int swap(t_stack *stack)
void swap(t_stack *stack)
{
	int temp;

	if (!stack)
		//return (0);
		return;
	int c = stack_count(&stack);
	if (c < 2)
		//return (0);
		return;
	temp = *(stack)->num;
	*(stack)->num = *(stack)->next->num;
	*(stack)->next->num = temp;
	//return (1);
	return;
}

void sa(t_stack *stack_a)
{
	swap(stack_a);
	printf("sa\n");	
}

void sb(t_stack *stack_b)
{
	swap(stack_b);
	printf("sa\n");	
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");	
}

//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.

//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.

void push(t_stack **stack_1, t_stack **stack_2)
{
	if (!stack_1)
		return;
	int c = stack_count(stack_1);
	if (c < 1)
		return;
	t_stack *temp1;
	temp1 = stack_1[0];
	stack_1[0] = (stack_1[0])->next;
	stack_add_front(stack_2, temp1);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	printf("pa\n");	
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	printf("pb\n");	
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	
	stack_b = NULL;
	
	stack_a = create_stacks(argc, argv);
	if (!stack_a)
		return (return_error());

	printf("--- stack_a before ---\n");
	int ss = 0;
	t_stack *temp = stack_a;
	while (temp != NULL)
	{
		printf("%d stack: %d\n", ss, *temp->num);
		temp = temp->next;
		ss++;
	}
	printf("---%d---\n", ss);

	printf("--- stack_b before---\n");
	ss = 0;
	temp = stack_b;
	while (temp != NULL)
	{
		printf("%d stack_b: %d\n", ss, *temp->num);
		temp = temp->next;
		ss++;
	}
	printf("---%d---\n", ss);

	//sa(stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	sb(stack_b);
	
	printf("--- stack_a after ---\n");
	ss = 0;
	temp = stack_a;
	while (temp != NULL)
	{
		printf("%d stack_a: %d\n", ss, *temp->num);
		temp = temp->next;
		ss++;
	}
	printf("---%d---\n", ss);


	printf("--- stack_b after ---\n");
	ss = 0;
	temp = stack_b;
	while (temp != NULL)
	{
		printf("%d stack_b: %d\n", ss, *temp->num);
		temp = temp->next;
		ss++;
	}
	printf("---%d---\n", ss);

	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int return_error(void)
{
	printf("Error\n"); /// TODO ft_printf !!!!!
	return (-1);
}

// void ra(void)
// {
	
// }

// void rb(void)
// {
	
// }

// void rr(void)
// {
	
// }

// void rra(void)
// {
	
// }

// void rrb(void)
// {
	
// }

// void rrr(void)
// {
	
// }