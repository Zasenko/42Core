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

// TODO: Delete
int counter = 0;
int return_error(void);

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = create_stacks(argc, argv);
	if (!stack_a)
		return (return_error());
	sort(&stack_a, &stack_b);

	// printf("========== stack_a ==========\n");
	// print_stack(stack_a);
	// printf("======== stack_b ========\n");
	// print_stack(stack_b);
	// printf("--- COUNTER: %d ---\n", counter);

	free_stack(&stack_b);
	free_stack(&stack_a);
	return (0);
}

void print_stack(t_stack *stack)
{
	int i;
	t_stack *temp;

	i = 0;
	temp = stack;
	while (temp != NULL)
	{
		printf("%d: %d\n", i, temp->num);
		temp = temp->next;
		i++;
	}
}

int return_error(void)
{
	printf("Error\n"); /// TODO ft_printf !!!!!
	return (-1);
}