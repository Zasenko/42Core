/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:07:38 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/24 12:54:27 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	sa(stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ra(&stack_a);
	rb(&stack_b);
	rrr(&stack_a, &stack_b);
	sa(stack_a);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	
	printf("--- stack_a after---\n");
	ss = 0;
	temp = stack_a;
	while (temp != NULL)
	{
		printf("%d stack_a: %d\n", ss, *temp->num);
		temp = temp->next;
		ss++;
	}
	printf("---%d---\n", ss);


	printf("--- stack_b after---\n");
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