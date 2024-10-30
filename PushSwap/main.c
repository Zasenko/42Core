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

int counter = 0;

int position_max(t_stack *stack, int num)
{
	t_stack *tmp = stack;
	int i = 1;
	while (tmp && num < *(tmp->num))
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}

int position_exact(t_stack *stack, int num)
{
	t_stack *tmp = stack;
	int i = 0;
	while (tmp)
	{
		if (num == *(tmp->num))
			return ++i;
		tmp = tmp->next;
		i++;
	}
	return i;
}
// 16//11
int position_min(t_stack *stack, int num, int len)
{
	// printf("---\n");
	// printf("num: %d\n", num);
	// printf("len: %d\n", len);

	t_stack *last = stack_last(stack);
	if (!last)
		return (0);
	// printf("last: %d\n", *(last->num));
	// printf("---\n");

	while (len && *(last->num) < num)
	{
		len--;
		//printf("len: %d\n", len);
		last = stack_last_n(stack, len - 1);
		// printf("last: %d\n", *(last->num));
		// printf("---\n");

	}
	// printf("return len: %d\n", len);
	// printf("---\n");
	return (len);
}

//	 1	2	2	3	3
//	 3	3	1	1	2
//	 2	1	3	2	1

void sort_3(t_stack **stack, char c)
{
	int n1;
	int n2;
	int n3;

	if (!stack || !*stack || stack_count(stack) != 3)
		return;	
	n1 = *((*stack)->num);
	n2 = *((*stack)->next->num);
	n3 = *((*stack)->next->next->num);

	if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		//	1
		//	3
		//	2
		printf("------ sort 0.1 ------\n");
		if (c == 'a')
		{
			rra(stack);
			sa(*stack);
		}
		else
		{
			rb(stack);
		}
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
	{
		//	2
		//	3
		//	1
		printf("------ sort 0.2 ------\n");
		if (c == 'a')
		{
			rra(stack);
		}
		else
		{
			sb(*stack);
		}
	}
	else if (n1 > n2 && n2 < n3 && n1 < n3)
	{
		//	2
		//	1
		//	3
		printf("------ sort 0.3 ------\n");
		if (c == 'a')
		{
			sa(*stack);
		}
		else
		{
			rrb(stack);
		}
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
	{
		//	3
		//	1
		//	2
		printf("------ sort 0.4 ------\n");
		if (c == 'a')
		{
			ra(stack);
		}
		else
		{
			sb(*stack);
			rb(stack);
		}
	}
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		//	3
		//	2
		//	1
		printf("------ sort 0.5 ------\n");
		if (c == 'a')
		{
			ra(stack);
			sa(*stack);
		}
		else
			return;
	}
	else
	{
		//	1
		//	2
		//	3
		printf("------ sort 0.0 ------\n");

		if (c == 'a')
			return;
		else
		{
			rb(stack);
			rb(stack);
		}
	}
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int a_counter;
	int b_counter;
	int min;
	int max;

	a_counter = stack_count(stack_a);
	b_counter = 0;
	min = 0;
	max = 0;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	a_counter = a_counter - 2;
	b_counter = 2;

	if (*((*stack_b)->num) < *((*stack_b)->next->num))
	{
		max = *((*stack_b)->next->num);
		min = *((*stack_b)->num);
	}
	else
	{
		max = *((*stack_b)->num);
		min = *((*stack_b)->next->num);
	}


	while (a_counter > 3)
	{
		printf("\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=//=/=/=/\n");

		pb(stack_a, stack_b);
		a_counter--;
		b_counter++;

		// MIN MAX FROM TOP A
		if (*((*stack_b)->num) < min)
		{
			// printf("------20.1------\n");
			min = *((*stack_b)->num);
			// rb(stack_b);
			// if (*((*stack_a)->num) < *((*stack_a)->next->num))
			// {
			//  ss(*stack_a, *stack_b);
			// }
			// else
			//  sb(*stack_b);
		}
		else if (*((*stack_b)->num) > max)
		{
			// printf("------20.2------\n");
			max = *((*stack_b)->num);
		}

		if (b_counter == 3)
			sort_3(stack_b, 'b');

		printf("\n-stack_b-\n");
		print_stack(*stack_b);

		printf("max = %d, min = %d\n", max, min);
		printf("a 1 = %d\n", *((*stack_a)->num));

		if (a_counter > 3)
		{
			// ROTATE B
			if (*((*stack_a)->num) < min || *((*stack_a)->num) > max)
			{
				printf("------ 1 ------\n");
				int pos_exact = position_exact(*stack_b, max);
				printf("max position: %d, counter / 2: %d\n", pos_exact, b_counter / 2);

				if (b_counter / 2 <= pos_exact)
				{
					printf("------1.1------\n");
					if (b_counter % 2 != 0 && (b_counter / 2) + 1 == pos_exact)
					{
						printf("------1.1.1------\n");
						int i = 1;
						while (i < pos_exact)
						{
							// printf("------6.1------\n");
							rb(stack_b);
							i++;
						}
					}
					else
					{
						printf("------1.1.2------\n");
						int i = 0;
						while (i <= b_counter - pos_exact)
						{
							// printf("------6.1------\n");
							rrb(stack_b);
							i++;
						}
					}
				}
				else
				{
					printf("------1.2------\n");
					int i = 1;
					while (i < pos_exact)
					{
						// printf("------6.1------\n");
						rb(stack_b);
						i++;
					}
				}
			}
			else
			{
				printf("------ 2 ------\n");

				if (*((*stack_a)->num) < *((*stack_b)->num))
				{
					printf("------2.1------\n");
					int max_pos = position_max(*stack_b, *((*stack_a)->num));

					printf("top > position max: %d, counter / 2: %d\n", max_pos, b_counter / 2);

					if ((b_counter / 2) <= max_pos)
					{
						printf("------2.1.1------\n");

						if (b_counter % 2 != 0 && (b_counter / 2) + 1 == max_pos)
						{
							printf("------2.1.1.1------\n");
							int i = 1;
							while (i < max_pos)
							{
								rb(stack_b);
								i++;
							}
						}
						else
						{
							printf("------2.1.1.2------\n");
							int i = 0;
							while (i <= b_counter - max_pos)
							{
								// printf("------6.1------\n");
								rrb(stack_b);
								i++;
							}
						}
					}
					else
					{
						printf("------2.1.2------\n");

						int i = 1;
						while (i < max_pos)
						{
							rb(stack_b);
							i++;
						}
					}
				}
				else
				{
					printf("------2.2------\n");
					int min_pos = position_min(*stack_b, *((*stack_a)->num), b_counter);
					printf("btm > position min: %d, counter / 2: %d\n", min_pos, b_counter / 2);

					if (b_counter / 2 <= min_pos)
					{
						printf("------2.2.1------\n");

						if (b_counter % 2 != 0 && (b_counter / 2) + 1 == min_pos)
						{
							printf("------2.2.1.1------\n");
							int i = 1;
							while (i < min_pos)
							{
								// printf("------6.1------\n");
								rb(stack_b);
								i++;
							}
						}
						else
						{
							printf("------2.2.1.2------\n");
							int i = 0;
							while (i < b_counter - min_pos)
							{
								// printf("------6.1------\n");
								rrb(stack_b);
								i++;
							}
						}
					}
					else
					{
						printf("------2.2.2------\n");
						t_stack *l = stack_last(*stack_b);
						if (l)
						{
							printf("------2.2.2.1------\n");
							printf("stack_last num: %d\n", *(l->num));
							if (*(l->num) < *((*stack_a)->num))
							{
								printf("------2.2.2.1.1------\n");
								// printf("------30.7------\n");

								int s = b_counter - min_pos;
								int i = 0;
								//  printf("------7------\n");
								while (i < s)
								{
									// printf("------9.1------\n");

									rrb(stack_b);
									i++;
								}
							}
							else
							{
								printf("------2.2.2.1.2------\n");
								printf("------|Error|------\n");
							}
						}
						else
						{
							printf("------2.2.2.2------\n");
						}
						// printf("-7- while times: %d\n", s);
					}
				}
			}
		printf("\n--- stack_a after ---\n");
		print_stack(*stack_a);
		printf("--- stack_b after ---\n");
		print_stack(*stack_b);
		}
		else
		{
			printf("------ 0 ------\n");
			int pos_exact = position_exact(*stack_b, max);
			printf("max position: %d, counter / 2: %d\n", pos_exact, b_counter / 2);
			if ((b_counter / 2) <= pos_exact)
			{
				printf("------0.1------\n");
				if (b_counter % 2 != 0 && (b_counter / 2) + 1 == pos_exact)
				{
					printf("------0.1.1------\n");
					int i = 1;
					while (i < pos_exact)
					{
						// printf("------6.1------\n");
						rb(stack_b);
						i++;
					}
				}
				else
				{
					printf("------0.1.2------\n");
					int i = 1;
					while (i < pos_exact)
					{
						// printf("------6.1------\n");
						rb(stack_b);
						i++;
					}
				}
			}
			else
			{
				printf("------0.2------\n");
				int i = 1;
				while (i < pos_exact)
				{
					// printf("------6.1------\n");
					rb(stack_b);
					i++;
				}
			}
		}
	}

	printf("\n------ sort 3 a ------\n");
	sort_3(stack_a, 'a');
	printf("\n--- stack_a after ---\n");
	print_stack(*stack_a);

	int count_3 = 0;

	printf("\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=//=/=/=/\n");
	printf("------ sort 3.1 ------\n");
	while (b_counter > 0)
	{
		t_stack *last = stack_last(*stack_a);
		if (*(last->num) > *((*stack_b)->num) && count_3 < 3)
		{
			rra(stack_a);
			count_3++;
		}
		else
		{
			pa(stack_a, stack_b);
			b_counter--;
		}
	}
	
	printf("\n--- stack_a after ---\n");
	print_stack(*stack_a);
	printf("--- stack_b after ---\n");
	print_stack(*stack_b);

	printf("\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=//=/=/=/\n");
	printf("------ sort 3.2 ------\n");
	t_stack *last_a = stack_last(*stack_a);
	while (*(last_a->num) < *((*stack_a)->num))
	{
		rra(stack_a);
		last_a = stack_last(*stack_a);
	}

	
	printf("\n--- stack_a after ---\n");
	print_stack(*stack_a);
	printf("--- stack_b after ---\n");
	print_stack(*stack_b);
	printf("\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=//=/=/=/\n");
}
// 5 4 9 6 11 7 8 1 2 14 3 13 12 15 10
//  80 main copy
// 76
// 61
// 64
// 52

// 4 19 13 15 17 2 3 6 8 14 7 1 18 12 9 20 10 5 16 11
// 75

// 10 14 17 3 5 11 6 2 20 13 16 15 7 4 8 12 19 9 1 18
// 92

// 7 19 2 8 20 5 15 10 18 17 13 16 11 3 4 14 12 6 9 1
// 74

// 19 68 98 49 85 52 40 63 97 11 24 9 42 65 70 15 84 86 56 80 38 73 10 78 14 45 26 67 66 3 57 96 59 76 22 41 17 79 91 30 54 82 99 88 92 95 16 71 48 2 93 27 8 20 4 5 13 55 47 1 90 75 23 25 28 89 61 72 12 21 29 60 32 100 46 83 33 50 87 64 58 51 6 43 74 81 39 53 31 18 69 37 36 62 7 44 77 35 34 94
//
//
//
// 46 44 48 76 71 34 75 26 10 95 3 60 22 18 45 59 23 74 58 53 72 16 14 38 79 12 73 6 92 66 90 85 11 68 77 25 87 52 100 40 82 62 21 69 86 24 8 42 54 99 9 70 81 67 29 27 84 65 15 41 33 63 39 55 61 32 30 96 7 51 57 1 80 4 5 94 83 47 35 43 78 20 36 91 50 28 31 37 49 56 2 88 89 97 93 98 19 64 13 17
//
//
//
// 70 44 56 13 61 28 47 55 11 66 15 82 64 65 4 81 22 67 31 68 33 45 21 78 89 69 20 73 38 29 8 1 58 6 41 40 53 57 48 95 74 71 2 42 72 17 23 80 62 26 94 51 77 27 60 50 85 75 87 12 86 63 16 97 90 46 79 43 76 7 32 24 36 100 30 35 25 5 84 49 88 59 9 3 99 83 96 37 14 98 19 39 34 10 54 18 93 91 92 52
//
//
//

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = create_stacks(argc, argv);
	if (!stack_a)
		return (return_error());
	// printf("--- stack_a before ---\n");
	// print_stack(stack_a);
	// printf("--- stack_b before---\n");
	// print_stack(stack_b);
	sort_stack(&stack_a, &stack_b);
	printf("--- stack_a after---\n");
	print_stack(stack_a);
	printf("--- stack_b after---\n");
	print_stack(stack_b);
	printf("--- COUNTER: %d ---\n", counter);
	free_stack(&stack_b);
	free_stack(&stack_a);
	return (0);
}

void print_stack(t_stack *stack)
{
	int ss;
	t_stack *temp;

	ss = 1;
	temp = stack;
	while (temp != NULL)
	{
		printf("%d: %d\n", ss, *temp->num);
		temp = temp->next;
		ss++;
	}
	//printf("---%d---\n", ss);
}

int return_error(void)
{
	printf("Error\n"); /// TODO ft_printf !!!!!
	return (-1);
}