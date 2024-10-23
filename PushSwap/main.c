/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:07:38 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/23 11:19:55 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
int swap(t_stack *stack)
{
	int temp;
	int temp2;
	int c = stack_count(stack);
	if (c < 2)
		return (0);
	
	temp = *(int *)(stack)->num;

	temp2 = *(int *)(stack)->next->num;
	*(int *)(stack)->num = temp2;
	*(int *)(stack)->next->num = temp;
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *stack1;
	stack1 = create_stacks(argc, argv);
	if (!stack1)
		return (return_error());

	int ss = 0;
	t_stack *temp = stack1;
	while (temp != NULL)
	{
		printf("%d stack: %d\n", ss, *(int *)temp->num);
		temp = temp->next;
		ss++;
	}
	printf("---%d---\n", ss);


	// if(swap(stack1) == 0)
	// {
	// 		free_stack(&stack1);
	// 		return (-1);
	// }

	// ss = 0;
	// temp = stack1;
	// while (temp != NULL)
	// {
	// 	printf("%d stack: %d\n", ss, *(int *)temp->num);
	// 	temp = temp->next;
	// 	ss++;
	// }
	// printf("---%d---\n", ss);
	free_stack(&stack1);
	return (0);
}

int return_error(void)
{
	printf("Error\n"); /// TODO ft_printf !!!!!
	return (-1);
}


// void sa(t_stack **stack1)
// {
	
// }

// void sb(void)
// {
	
// }

// void ss(void)
// {
	
// }

// void pa(void)
// {
	
// }

// void pb(void)
// {
	
// }

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