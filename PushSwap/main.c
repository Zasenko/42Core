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
void print_stack(t_stack *stack);

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int a_count = stack_count(stack_a);
	int b_count = 0;

	// a_count == 3 - 4 operation

	int min = 0;
	int max = 0;
	if (a_count > 0)
	{
		pb(stack_a, stack_b);
		a_count--;
		b_count++;
	}
	if (a_count > 0)
	{
		pb(stack_a, stack_b);
		a_count--;
		b_count++;
	}
	if (*((*stack_b)->num) < *((*stack_b)->next->num))
	{
		min = *((*stack_b)->num);
		max = *((*stack_b)->next->num);
		sb(*stack_b);
	}
	else
	{
		max = *((*stack_b)->num);
		min = *((*stack_b)->next->num);
	}

	int sss = 3;
	while (a_count > 1)
	{
		printf("------------%d--------------\n", sss);

		int move_count = 0;

		if (*((*stack_a)->num) < max && *((*stack_a)->num) > min)
		{
			while (*((*stack_b)->num) > *((*stack_a)->num))
			{
				rb(stack_b);
				move_count++;
			}
		}

		pb(stack_a, stack_b);
		a_count--;
		b_count++;

		if (*((*stack_b)->num) > max)
		{
			max = *((*stack_b)->num);
		}
		else if (*((*stack_b)->num) < min)
		{
			min = *((*stack_b)->num);
			rb(stack_b);
		}
		else
		{
			while (move_count)
			{
				rrb(stack_b);
				move_count--;
			}
			while ((*((*stack_a)->num) > *((*stack_b)->next->num)) && move_count)
			{
				rrb(stack_b);
				move_count--;
			}
		}

		printf("--- stack_a ---\n");
		print_stack(*stack_a);
		printf("--- stack_b ---\n");
		print_stack(*stack_b);

		sss++;
	}

	printf("--- a_count: %d ---\n", a_count);
	printf("--- b_count: %d ---\n", b_count);
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
			print_stack(stack_a);
			printf("--- stack_b before---\n");
			print_stack(stack_b);

			sort_stack(&stack_a, &stack_b);

			printf("--- stack_a after---\n");
			print_stack(stack_a);
			printf("--- stack_b after---\n");
			print_stack(stack_b);

			free_stack(&stack_a);
			free_stack(&stack_b);
			return (0);
		}

		void print_stack(t_stack *stack)
		{
			int ss = 0;
			t_stack *temp = stack;
			while (temp != NULL)
			{
				printf("%d stack: %d\n", ss, *temp->num);
				temp = temp->next;
				ss++;
			}
			printf("---%d---\n", ss);
		}

		int return_error(void)
		{
			printf("Error\n"); /// TODO ft_printf !!!!!
			return (-1);
		}