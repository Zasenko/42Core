/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:49 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/06 14:40:58 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: delete counter
extern int counter;

int moves_in_b(t_stack **stack_a, t_stack **stack_b, int min_b, int max_b, int b_counter);

int moves_in_a(t_stack **stack_a, t_stack **stack_b, int max_b, int a_counter);

int max_num(t_stack *stack)
{
	t_stack *tmp = stack;
	int max = -2147483648;
	while (tmp)
	{
		if (tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	return max;
}

int position_max_b(t_stack *stack, int num)
{
	t_stack *tmp = stack;
	int i = 0;
	while (tmp && num < tmp->num)
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}

int position_max_max_text(t_stack *stack, int num)
{
	t_stack *tmp = stack;
	int i = 0;
	while (tmp && num > tmp->num)
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}

int position_min_test(t_stack *stack, int num, int len)
{
	printf("-:- pos min -:- num: %d, len: %d\n", num, len);

	t_stack *last = stack_last(stack);
	if (!last)
		return (0);
	if (last->num < num)
	{
		while (len && last->num < num)
		{
			printf("len: %d, last->num: %d | \n", len, last->num);
			last = stack_last_n(stack, (len--) - 1);
		}
	return (len);
	}
	else
	{
		return (len - 1);
	}
}

int top_position_between(t_stack *stack, int min, int max)
{
	//	printf("----- top_position_between ------\n");
	//	printf("min: %d, max: %d\n", min, max);
	t_stack *tmp = stack;

	if (!tmp)
		return -1;
	int i = 0;
	while (tmp)
	{
		if (tmp->num > min && tmp->num < max)
		{
			//		printf("last->num: %d, i: %d\n", tmp->num, i);
			return i;
		}
		tmp = tmp->next;
		i++;
	}
	return -1;
}

int btm_position_between(t_stack *stack, int min, int max, int len)
{
	// printf("----- btm_position_between ------\n");
	// printf("min: %d, max: %d, len: %d\n", min, max, len);

	t_stack *last = stack_last(stack);

	if (!last)
	{
		//	printf("Error !last\n");
		return (0);
	}

	while (len && last)
	{
		if (last->num > min && last->num < max)
		{
			//	printf("last->num: %d, len: %d\n", last->num, len);
			return --len;
		}
		len--;
		last = stack_last_n(stack, len - 1);
	}
	return (len);
}

int position_exact(t_stack *stack, int num)
{
	t_stack *tmp = stack;
	int i = 0;
	while (tmp)
	{
		if (num == tmp->num)
			return i;
		tmp = tmp->next;
		i++;
	}
	return i;
}

int position_min(t_stack *stack, int num, int len)
{
	t_stack *last = stack_last(stack);
	if (!last)
		return (0);
	while (len && last->num < num)
	{
		printf("len: %d, last->num: %d | \n", len, last->num);

		len--;
		printf("len--: %d\n", len);
		last = stack_last_n(stack, len - 1);
	}
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
	n1 = (*stack)->num;
	n2 = (*stack)->next->num;
	n3 = (*stack)->next->next->num;

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
			sb(*stack);
		}
	}
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int a_counter;
	int b_counter;
	int min_b;
	int max_b;

	a_counter = stack_count(stack_a);
	b_counter = 0;
	min_b = 0;
	max_b = 0;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	a_counter = a_counter - 2;
	b_counter = 2;

	if ((*stack_b)->num < (*stack_b)->next->num)
	{
		max_b = (*stack_b)->next->num;
		min_b = (*stack_b)->num;
	}
	else
	{
		max_b = (*stack_b)->num;
		min_b = (*stack_b)->next->num;
	}

	int time = 1;
	while (a_counter > 3)
	{
		printf("\n============== %d ==============\n", time);

		pb(stack_a, stack_b);
		a_counter--;
		b_counter++;

		printf("\n--- stack_a ---\n");
		print_stack(*stack_a);

		// MIN MAX_b FROM TOP A
		if ((*stack_b)->num < min_b)
		{
			min_b = (*stack_b)->num;
		}
		else if ((*stack_b)->num > max_b)
		{
			max_b = (*stack_b)->num;
		}

		if (b_counter == 3)
		{
			sort_3(stack_b, 'b');
			// printf("\n--- stack_a after ---\n");
			// print_stack(*stack_a);
			// printf("--- stack_b after ---\n");
			// print_stack(*stack_b);
		}

		printf("\n-stack_b-\n");
		print_stack(*stack_b);

		printf("max_b = %d, min_b = %d\n", max_b, min_b);

		if (a_counter > 3)
		{
			// MOVES COUNTING
			int m_in_a = moves_in_a(stack_a, stack_b, max_b, a_counter);
			int m_in_b = moves_in_b(stack_a, stack_b, min_b, max_b, b_counter);

			printf("--------- MOVE IN A: %d\n--------- MOVE IN B: %d\n", m_in_a, m_in_b);

			if (m_in_a >= 0 && m_in_a < m_in_b)
			{
				printf("========= ROTATE A ==========\n");
				if ((*stack_b)->num == max_b)
				{
					// printf("---- 1 ----\n");
					int top_pos = position_max_max_text(*stack_a, max_b);
					int btm_pos = position_min_test(*stack_a, max_b, a_counter);
					printf("top_pos: %d, btm_pos: %d | a_counter - btm_pos: %d\n", top_pos, btm_pos, a_counter - btm_pos);
					if (btm_pos > 0 && top_pos != a_counter)
					{
						if (top_pos <= a_counter - btm_pos)
						{
							while (top_pos-- > 0)
								ra(stack_a);
						}
						if (top_pos > a_counter - btm_pos)
						{
							while (a_counter - btm_pos > 0)
							{
								//	printf("---- 00.2 ----\n");
								rra(stack_a);
								btm_pos++;
							}
						}
					}
				}
				else
				{
					printf("---- 2 ----\n");
					t_stack *last = stack_last(*stack_b);
					if (last)
					{
						int top_pos = top_position_between(*stack_a, (*stack_b)->num, last->num);
						int btm_pos = btm_position_between(*stack_a, (*stack_b)->num, last->num, a_counter);

						printf("top_pos: %d, btm_pos: %d | btm moves: %d\n", top_pos, btm_pos, a_counter - btm_pos);

						if (btm_pos > 0 && top_pos != a_counter)
						{
							if (top_pos <= a_counter - btm_pos)
							{
								while (top_pos-- > 0)
									ra(stack_a);
							}
							if (top_pos > a_counter - btm_pos)
							{
								while ((a_counter - btm_pos) > 0)
								{
									// printf("---- 00.1 ----\n");
									rra(stack_a);
									btm_pos++;
								}
							}
						}
					}
				}
			}
			else
			{
				printf("========= ROTATE B ==========\n");
				if ((*stack_a)->num < min_b || (*stack_a)->num > max_b)
				{
					//	printf("------ 1 ------\n");
					int pos_exact = position_exact(*stack_b, max_b);
					//	printf("max_b position: %d, counter / 2: %d\n", pos_exact, b_counter / 2);

					if (pos_exact < b_counter / 2 || (b_counter % 2 != 0 && (b_counter / 2) == pos_exact))
					{
						//		printf("------1.1------\n");
						int i = 0;
						while (i < pos_exact)
						{
							rb(stack_b);
							i++;
						}
					}
					else
					{
						//		printf("------1.2------\n");
						int i = 0;
						while (i < b_counter - pos_exact)
						{
							rrb(stack_b);
							i++;
						}
					}
				}
				else
				{
					//	printf("------ 2 ------\n");
					if ((*stack_a)->num < (*stack_b)->num)
					{
						//		printf("------2.1------\n");
						int max_b_pos = position_max_b(*stack_b, (*stack_a)->num);
						//	printf("b top > position: %d, counter / 2: %d\n", max_b_pos, b_counter / 2);
						if (max_b_pos < (b_counter / 2) || (b_counter % 2 != 0 && (b_counter / 2) == max_b_pos))
						{
							//		printf("------2.1.1------\n");
							int i = 0;
							while (i < max_b_pos)
							{
								rb(stack_b);
								i++;
							}
						}
						else
						{
							//		printf("------2.1.2------\n");
							int i = 0;
							while (i < b_counter - max_b_pos)
							{
								rrb(stack_b);
								i++;
							}
						}
					}
					else
					{
						//	printf("------2.2------\n");
						int min_pos = position_min(*stack_b, (*stack_a)->num, b_counter);
						//	printf("b btm > position: %d, counter / 2: %d\n", min_pos, b_counter / 2);
						if (min_pos < b_counter / 2 || (b_counter % 2 != 0 && b_counter / 2 == min_pos))
						{
							//		printf("------2.2.1------\n");
							int i = 0;
							while (i < min_pos)
							{
								rb(stack_b);
								i++;
							}
						}
						else
						{
							//		printf("------2.2.2------\n");
							t_stack *l = stack_last(*stack_b);
							if (l)
							{
								//			printf("------2.2.2.1------\n");
								//			printf("stack_last num: %d\n", l->num);
								if (l->num < (*stack_a)->num)
								{
									//				printf("------2.2.2.1.1 !!!!!!!! ------\n");
									int s = b_counter - min_pos;
									int i = 0;
									while (i < s)
									{
										rrb(stack_b);
										i++;
									}
								}
								else
								{
									printf("------2.2.2.1.2.0 |Error|------\n");
								}
							}
							else
							{
								printf("------2.2.2.2.0 |Error|------\n");
							}
						}
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
			printf("\n====== LAST 3 in stack a =====\n");

			printf("------ 0 ------\n");
			int pos_exact = position_exact(*stack_b, max_b);
			printf("max_b position: %d, counter / 2: %d\n", pos_exact, b_counter / 2);
			if (pos_exact < (b_counter / 2) || (b_counter % 2 != 0 && (b_counter / 2) == pos_exact))
			{
				printf("------0.1------\n");
				int i = 0;
				while (i < pos_exact)
				{
					rb(stack_b);
					i++;
				}
			}
			else
			{
				printf("------0.2------\n");
				int i = 0;
				while (i < b_counter - pos_exact)
				{
					rrb(stack_b);
					i++;
				}
			}
		}
		time++; // TODO delete
	}

	printf("\n=========== SORT LAST 3 in stack a ==========\n");
	printf("\n------ sort 3 a ------\n");
	sort_3(stack_a, 'a');
	printf("\n--- stack_a after ---\n");
	print_stack(*stack_a);

	int count_3 = 0;

	printf("\n============== SORT 3 in A if last in A > first in B ==============\n");

	printf("------ sort 3.1 ------\n");
	while (b_counter > 0)
	{
		t_stack *last = stack_last(*stack_a);
		if (last)
		{
			if (last->num > (*stack_b)->num && count_3 < 3)
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
	}

	printf("\n--- stack_a after ---\n");
	print_stack(*stack_a);
	printf("--- stack_b after ---\n");
	print_stack(*stack_b);

	printf("\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=//=/=/=/\n");
	printf("------ sort 3.2 ------\n");
	t_stack *last_a = stack_last(*stack_a);
	while (last_a->num < (*stack_a)->num)
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

/*

27 20 6 21 23 7 11 4 1 10 24 30 8 5 2 19 22 18 3 17 28 26 15 9 29 14 13 16 25 12

169
139

19 11 3 16 12 8 13 14 6 2 1 4 15 7 5 9 17 20 18 10

75
79

10 3 6 14 13 20 16 8 18 1 2 17 9 4 15 11 19 7 5 12

78

16 8 2 4 3 19 15 13 9 6 5 20 17 14 18 11 12 10 7 1

78

6 8 3 11 18 19 1 9 5 2 16 14 17 20 12 13 4 7 15 10

74


63 80 40 34 87 90 56 42 30 73 9 13 47 45 79 59 69 67 2 58 18 24 51 28 36 98 14 33 83 8 72 100 68 85 37 1 57 94 7 49 66 82 31 23 25 70 16 46 61 93 22 50 35 41 19 26 20 99 43 52 76 84 86 6 54 27 29 53 4 38 17 12 5 60 95 74 64 55 48 75 71 89 81 91 62 77 21 97 44 65 3 11 92 32 88 96 10 78 39 15

1270
1243
1268

1188

*/
int moves_in_b(t_stack **stack_a, t_stack **stack_b, int min_b, int max_b, int b_counter)
{
	int i = 0;
	printf("========= moves_in_b ==========\n");
	if ((*stack_a)->num < min_b || (*stack_a)->num > max_b)
	{
		printf("---- 1 -----\n");
		int pos_exact = position_exact(*stack_b, max_b);
		if (pos_exact < b_counter / 2 || (b_counter % 2 != 0 && (b_counter / 2) == pos_exact))
		{
			printf("---- 1.1 -----\n");
			while (i < pos_exact)
				i++;
		}
		else
		{
			printf("---- 1.2 -----\n");
			while (i < b_counter - pos_exact)
				i++;
		}
	}
	else
	{
		printf("---- 2 -----\n");

		if ((*stack_a)->num < (*stack_b)->num)
		{
			printf("---- 2.1 -----\n");

			int max_b_pos = position_max_b(*stack_b, (*stack_a)->num);
			printf("max_b_pos: %d\n", max_b_pos);

			if (max_b_pos < (b_counter / 2) || (b_counter % 2 != 0 && (b_counter / 2) == max_b_pos))
			{
				printf("---- 2.1.1 -----\n");

				while (i < max_b_pos)
				{
					i++;
					// printf("i++: %d\n", i);
				}
			}
			else
			{
				printf("---- 2.1.2 -----\n");
				printf("b_counter(%d) -  max_b_pos(%d) = %d\n", b_counter, max_b_pos, b_counter - max_b_pos);

				while (i < b_counter - max_b_pos)
				{
					i++;
					// printf("i++: %d\n", i);
				}
			}
		}
		else
		{
			printf("---- 2.2 -----\n");

			int min_pos = position_min(*stack_b, (*stack_a)->num, b_counter);
			printf("min_pos: %d\n", min_pos);
			if (min_pos < b_counter / 2 || (b_counter % 2 != 0 && b_counter / 2 == min_pos))
			{
				printf("---- 2.2.1 -----\n");
				while (i < min_pos)
				{
					i++;
				}
			}
			else
			{
				t_stack *l = stack_last(*stack_b);
				if (l)
				{
					printf("---- 2.2.2 -----\n");

					if (l->num < (*stack_a)->num)
					{
						printf("---- 2.2.2.1 -----\n");

						int s = b_counter - min_pos;
						printf("s(%d) = b_counter(%d) - min_pos(%d)\n", s, b_counter, min_pos);
						while (i < s)
						{
							i++;
						}
					}
					else
					{
						printf("------ |Error| moves in b 2.2.2.2------\n");
					}
				}
				else
				{
					printf("------|Error| moves in b 2.2.2.0 ------\n");
				}
			}
		}
	}
	return i;
}

int moves_in_a(t_stack **stack_a, t_stack **stack_b, int max_b, int a_counter)
{
	printf("========= moves_in_a ==========\n");
	if ((*stack_b)->num == max_b)
	{
		printf("---- 1 ----\n");
		int top_pos = position_max_max_text(*stack_a, max_b);
		int btm_pos = position_min_test(*stack_a, max_b, a_counter);
		printf("top_pos: %d, btm_pos: %d | top moves: %d, btm moves: %d\n", top_pos, btm_pos, top_pos, a_counter - btm_pos);
		if (btm_pos == 0 || top_pos == a_counter)
		{
			printf("NOT FOUND moves_in_a\n");
			return -1;
		}
		if (top_pos <= a_counter - btm_pos)
			return top_pos;
		if (top_pos > a_counter - btm_pos)
			return a_counter - btm_pos;
	}
	else
	{
		printf("---- 2 ----\n");
		t_stack *last = stack_last(*stack_b);
		if (!last)
			return -1;

		int top_pos = top_position_between(*stack_a, (*stack_b)->num, last->num);
		int btm_pos = btm_position_between(*stack_a, (*stack_b)->num, last->num, a_counter);

		printf("top_pos: %d, btm_pos: %d | top moves: %d, btm moves: %d\n", top_pos, btm_pos, top_pos, a_counter - btm_pos);

		if (btm_pos == 0 || top_pos == -1)
		{
			printf("NOT FOUND moves_in_a\n");
			return -1;
		}
		if (top_pos <= a_counter - btm_pos)
			return top_pos;
		if (top_pos > a_counter - btm_pos)
			return a_counter - btm_pos;
	}
	return (-1);
}