#include "push_swap.h"

// TODO: delete counter
extern int counter;

int moves_in_b(t_stack **stack_a, t_stack **stack_b, int min_b, int max_b, int b_counter);
int moves_in_a(t_stack **stack_a, t_stack **stack_b, int max_b, int a_counter);
void moves_finder(t_stack **stack_a, t_stack **stack_b, int max_b, int min_b, int a_counter, int b_counter);

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
	// printf("-:- pos min -:- num: %d, len: %d\n", num, len);

	t_stack *last = stack_last(stack);
	if (!last)
		return (0);
	if (last->num < num)
	{
		while (len && last->num < num)
		{
			// printf("len: %d, last->num: %d | \n", len, last->num);
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
	//	//printf("----- top_position_between ------\n");
	//	//printf("min: %d, max: %d\n", min, max);
	t_stack *tmp = stack;

	if (!tmp)
		return -1;
	int i = 0;
	while (tmp)
	{
		if (tmp->num > min && tmp->num < max)
		{
			//		//printf("last->num: %d, i: %d\n", tmp->num, i);
			return i;
		}
		tmp = tmp->next;
		i++;
	}
	return -1;
}

int btm_position_between(t_stack *stack, int min, int max, int len)
{
	// //printf("----- btm_position_between ------\n");
	// //printf("min: %d, max: %d, len: %d\n", min, max, len);

	t_stack *last = stack_last(stack);

	if (!last)
	{
		return (0);
	}

	while (len && last)
	{
		if (last->num > min && last->num < max)
		{
			//	//printf("last->num: %d, len: %d\n", last->num, len);
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
		// printf("len: %d, last->num: %d | \n", len, last->num);

		len--;
		// printf("len--: %d\n", len);
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
		// printf("------ sort 0.1 ------\n");
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
		// printf("------ sort 0.2 ------\n");
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
		// printf("------ sort 0.3 ------\n");
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
		// printf("------ sort 0.4 ------\n");
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
		// printf("------ sort 0.5 ------\n");
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
		// printf("------ sort 0.0 ------\n");

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

	int max = max_num(*stack_a);

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

	while (a_counter > 3)
	{
		// printf("\n============== %d ==============\n", time);

		pb(stack_a, stack_b);
		a_counter--;
		b_counter++;

		// printf("\n--- stack_a ---\n");
		////print_stack(*stack_a);

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
			// //printf("\n--- stack_a after ---\n");
			// //print_stack(*stack_a);
			// //printf("--- stack_b after ---\n");
			// //print_stack(*stack_b);
		}

		// printf("\n-stack_b-\n");
		////print_stack(*stack_b);

		// printf("max_b = %d, min_b = %d\n", max_b, min_b);

		if (a_counter > 3)
		{

			if ((*stack_a)->num > (*stack_a)->next->num) // проверить >
			{
				//sa(*stack_a);
				if ((*stack_b)->num == max)
				{
					rr(stack_a, stack_b);
				}
				else
					ra(stack_a);
			}
			else if ((*stack_b)->num == max)
			{
				if ((*stack_a)->num > (*stack_a)->next->num) // проверить <
				{
					rr(stack_a, stack_b);
				}
				else
					rb(stack_b);//проверить rrb
			}

			moves_finder(stack_a, stack_b, max_b, min_b, a_counter, b_counter);
		}
		else
		{
			// printf("\n====== LAST 3 in stack a =====\n");

			// printf("------ 0 ------\n");
			int pos_exact = position_exact(*stack_b, max_b);
			// printf("max_b position: %d, counter / 2: %d\n", pos_exact, b_counter / 2);
			if (pos_exact < (b_counter / 2) || (b_counter % 2 != 0 && (b_counter / 2) == pos_exact))
			{
				// printf("------0.1------\n");
				int i = 0;
				while (i < pos_exact)
				{
					rb(stack_b);
					i++;
				}
			}
			else
			{
				// printf("------0.2------\n");
				int i = 0;
				while (i < b_counter - pos_exact)
				{
					rrb(stack_b);
					i++;
				}
			}
		}
	}

	// printf("\n=========== SORT LAST 3 in stack a ==========\n");
	// printf("\n------ sort 3 a ------\n");
	sort_3(stack_a, 'a');
	// printf("\n--- stack_a after ---\n");
	////print_stack(*stack_a);

	int count_3 = 0;

	// printf("\n============== SORT 3 in A if last in A > first in B ==============\n");

	// printf("------ sort 3.1 ------\n");
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

	// printf("\n--- stack_a after ---\n");
	//print_stack(*stack_a);
	// printf("--- stack_b after ---\n");
	//print_stack(*stack_b);

	// printf("\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=//=/=/=/\n");
	// printf("------ sort 3.2 ------\n");
	t_stack *last_a = stack_last(*stack_a);
	while (last_a->num < (*stack_a)->num)
	{
		rra(stack_a);
		last_a = stack_last(*stack_a);
	}

	// printf("\n--- stack_a after ---\n");
	// print_stack(*stack_a);
	// printf("--- stack_b after ---\n");
	// print_stack(*stack_b);
	// printf("--- COUNTER: %d ---\n", counter);
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
	// printf("========= moves_in_b ==========\n");
	if ((*stack_a)->num < min_b || (*stack_a)->num > max_b)
	{
		// printf("---- 1 -----\n");
		int pos_exact = position_exact(*stack_b, max_b);
		if (pos_exact < b_counter / 2 || (b_counter % 2 != 0 && (b_counter / 2) == pos_exact))
		{
			// printf("---- 1.1 -----\n");
			while (i < pos_exact)
				i++;
		}
		else
		{
			// printf("---- 1.2 -----\n");
			while (i < b_counter - pos_exact)
				i++;
		}
	}
	else
	{
		// printf("---- 2 -----\n");

		if ((*stack_a)->num < (*stack_b)->num)
		{
			// printf("---- 2.1 -----\n");

			int max_b_pos = position_max_b(*stack_b, (*stack_a)->num);
			// printf("max_b_pos: %d\n", max_b_pos);

			if (max_b_pos < (b_counter / 2) || (b_counter % 2 != 0 && (b_counter / 2) == max_b_pos))
			{
				// printf("---- 2.1.1 -----\n");

				while (i < max_b_pos)
				{
					i++;
					// //printf("i++: %d\n", i);
				}
			}
			else
			{
				// printf("---- 2.1.2 -----\n");
				// printf("b_counter(%d) -  max_b_pos(%d) = %d\n", b_counter, max_b_pos, b_counter - max_b_pos);

				while (i < b_counter - max_b_pos)
				{
					i++;
					// //printf("i++: %d\n", i);
				}
			}
		}
		else
		{
			// printf("---- 2.2 -----\n");

			int min_pos = position_min(*stack_b, (*stack_a)->num, b_counter);
			// printf("min_pos: %d\n", min_pos);
			if (min_pos < b_counter / 2 || (b_counter % 2 != 0 && b_counter / 2 == min_pos))
			{
				// printf("---- 2.2.1 -----\n");
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
					// printf("---- 2.2.2 -----\n");

					if (l->num < (*stack_a)->num)
					{
						// printf("---- 2.2.2.1 -----\n");

						int s = b_counter - min_pos;
						// printf("s(%d) = b_counter(%d) - min_pos(%d)\n", s, b_counter, min_pos);
						while (i < s)
						{
							i++;
						}
					}
					else
					{
						// printf("------ |Error| moves in b 2.2.2.2------\n");
					}
				}
				else
				{
					// printf("------|Error| moves in b 2.2.2.0 ------\n");
				}
			}
		}
	}
	return i;
}

int moves_in_a(t_stack **stack_a, t_stack **stack_b, int max_b, int a_counter)
{
	// printf("========= moves_in_a ==========\n");
	if ((*stack_b)->num == max_b)
	{
		// printf("---- 1 ----\n");
		int top_pos = position_max_max_text(*stack_a, max_b);
		int btm_pos = position_min_test(*stack_a, max_b, a_counter);
		// printf("top_pos: %d, btm_pos: %d | top moves: %d, btm moves: %d\n", top_pos, btm_pos, top_pos, a_counter - btm_pos);
		if (btm_pos == 0 || top_pos == a_counter)
		{
			// printf("NOT FOUND moves_in_a\n");
			return -1;
		}
		if (top_pos <= a_counter - btm_pos)
			return top_pos;
		if (top_pos > a_counter - btm_pos)
			return a_counter - btm_pos;
	}
	else
	{
		// printf("---- 2 ----\n");
		t_stack *last = stack_last(*stack_b);
		if (!last)
			return -1;

		int top_pos = top_position_between(*stack_a, (*stack_b)->num, last->num);
		int btm_pos = btm_position_between(*stack_a, (*stack_b)->num, last->num, a_counter);

		// printf("top_pos: %d, btm_pos: %d | top moves: %d, btm moves: %d\n", top_pos, btm_pos, top_pos, a_counter - btm_pos);

		if (btm_pos == 0 || top_pos == -1)
		{
			// printf("NOT FOUND moves_in_a\n");
			return -1;
		}
		if (top_pos <= a_counter - btm_pos)
			return top_pos;
		if (top_pos > a_counter - btm_pos)
			return a_counter - btm_pos;
	}
	return (-1);
}

void moves_finder(t_stack **stack_a, t_stack **stack_b, int max_b, int min_b, int a_counter, int b_counter)
{
	// MOVES COUNTING
	int m_in_a = moves_in_a(stack_a, stack_b, max_b, a_counter);
	int m_in_b = moves_in_b(stack_a, stack_b, min_b, max_b, b_counter);

	// printf("--------- MOVE IN A: %d\n--------- MOVE IN B: %d\n", m_in_a, m_in_b);

	if (m_in_a >= 0 && m_in_a < m_in_b)
	{
		// printf("========= ROTATE A ==========\n");
		if ((*stack_b)->num == max_b)
		{
			// //printf("---- 1 ----\n");
			int top_pos = position_max_max_text(*stack_a, max_b);
			int btm_pos = position_min_test(*stack_a, max_b, a_counter);
			// printf("top_pos: %d, btm_pos: %d | a_counter - btm_pos: %d\n", top_pos, btm_pos, a_counter - btm_pos);
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
						//	//printf("---- 00.2 ----\n");
						rra(stack_a);
						btm_pos++;
					}
				}
			}
		}
		else
		{
			// printf("---- 2 ----\n");
			t_stack *last = stack_last(*stack_b);
			if (last)
			{
				int top_pos = top_position_between(*stack_a, (*stack_b)->num, last->num);
				int btm_pos = btm_position_between(*stack_a, (*stack_b)->num, last->num, a_counter);

				// printf("top_pos: %d, btm_pos: %d | btm moves: %d\n", top_pos, btm_pos, a_counter - btm_pos);

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
							// //printf("---- 00.1 ----\n");
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
		// printf("========= ROTATE B ==========\n");
		if ((*stack_a)->num < min_b || (*stack_a)->num > max_b)
		{
			//	//printf("------ 1 ------\n");
			int pos_exact = position_exact(*stack_b, max_b);
			//	//printf("max_b position: %d, counter / 2: %d\n", pos_exact, b_counter / 2);

			if (pos_exact < b_counter / 2 || (b_counter % 2 != 0 && (b_counter / 2) == pos_exact))
			{
				//		//printf("------1.1------\n");
				int i = 0;
				while (i < pos_exact)
				{
					rb(stack_b);
					i++;
				}
			}
			else
			{
				//		//printf("------1.2------\n");
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
			//	//printf("------ 2 ------\n");
			if ((*stack_a)->num < (*stack_b)->num)
			{
				//		//printf("------2.1------\n");
				int max_b_pos = position_max_b(*stack_b, (*stack_a)->num);
				//	//printf("b top > position: %d, counter / 2: %d\n", max_b_pos, b_counter / 2);
				if (max_b_pos < (b_counter / 2) || (b_counter % 2 != 0 && (b_counter / 2) == max_b_pos))
				{
					//		//printf("------2.1.1------\n");
					int i = 0;
					while (i < max_b_pos)
					{
						rb(stack_b);
						i++;
					}
				}
				else
				{
					//		//printf("------2.1.2------\n");
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
				//	//printf("------2.2------\n");
				int min_pos = position_min(*stack_b, (*stack_a)->num, b_counter);
				//	//printf("b btm > position: %d, counter / 2: %d\n", min_pos, b_counter / 2);
				if (min_pos < b_counter / 2 || (b_counter % 2 != 0 && b_counter / 2 == min_pos))
				{
					//		//printf("------2.2.1------\n");
					int i = 0;
					while (i < min_pos)
					{
						rb(stack_b);
						i++;
					}
				}
				else
				{
					//		//printf("------2.2.2------\n");
					t_stack *l = stack_last(*stack_b);
					if (l)
					{
						//			//printf("------2.2.2.1------\n");
						//			//printf("stack_last num: %d\n", l->num);
						if (l->num < (*stack_a)->num)
						{
							//				//printf("------2.2.2.1.1 !!!!!!!! ------\n");
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
							// printf("------2.2.2.1.2.0 |Error|------\n");
						}
					}
					else
					{
						// printf("------2.2.2.2.0 |Error|------\n");
					}
				}
			}
		}
	}

	// printf("\n--- stack_a after ---\n");
	////print_stack(*stack_a);
	// printf("--- stack_b after ---\n");
	////print_stack(*stack_b);
}

// 193 57 127 90 183 178 36 94 170 107 149 137 43 33 163 71 22 130 125 104 139 148 97 45 167 9 195 64 28 27 122 166 19 93 55 173 185 108 147 18 175 190 168 112 67 24 126 46 58 138 74 135 194 121 113 42 77 192 41 102 116 50 62 80 34 87 196 14 98 180 7 154 59 153 177 72 162 49 115 159 184 60 111 164 134 3 38 187 174 132 12 95 39 32 199 70 63 182 69 54 131 16 35 52 118 109 31 21 101 89 133 10 13 5 4 176 141 120 186 99 96 26 51 188 144 56 157 8 119 117 171 2 169 197 145 84 61 124 105 161 140 189 85 66 156 44 37 79 23 128 30 65 76 181 106 155 142 53 110 114 100 88 158 103 15 1 91 200 152 165 129 123 81 86 40 172 92 198 136 150 78 20 17 25 11 68 75 73 83 143 82 160 191 47 146 179 48 29 151 6

// 159 272 256 31 380 291 361 297 418 230 190 151 440 459 411 268 158 178 357 246 299 62 115 320 422 381 465 129 406 74 24 192 149 286 85 486 180 407 231 4 150 394 34 183 278 133 163 51 317 86 164 77 483 305 95 106 379 352 20 5 339 395 203 399 355 341 464 161 356 322 488 195 121 247 228 444 498 36 288 332 461 210 457 475 410 257 48 335 265 358 223 309 412 298 393 333 403 144 206 373 124 479 30 200 42 172 186 125 282 92 227 364 311 441 353 35 433 171 455 29 391 99 351 415 23 97 220 429 262 442 176 64 156 349 38 14 251 300 185 238 53 388 472 181 191 491 409 10 267 196 108 136 321 245 170 258 367 107 89 221 19 169 449 110 287 496 8 215 327 141 248 328 276 405 60 224 487 402 329 80 469 90 446 9 421 96 25 73 385 368 225 470 435 39 226 370 310 443 426 343 301 57 280 88 242 118 471 273 154 12 67 324 28 157 116 209 235 340 83 165 342 350 396 436 229 430 254 375 270 81 37 32 304 428 484 316 44 372 109 212 137 336 26 345 179 397 202 261 43 271 497 315 239 63 241 217 155 398 45 207 347 240 199 252 269 148 363 383 334 213 189 325 490 59 143 331 98 303 404 13 201 473 18 194 33 318 188 312 295 123 389 307 371 354 79 447 292 302 413 126 27 494 460 376 275 366 167 249 160 417 250 138 7 476 293 266 386 41 290 182 58 135 264 338 420 204 284 75 147 424 84 467 453 168 323 113 237 17 46 499 434 233 11 214 184 72 69 454 197 21 50 111 346 94 390 463 52 198 132 47 236 232 78 100 400 211 283 91 445 458 259 285 326 131 128 127 173 15 222 431 480 337 61 277 482 68 448 134 374 71 244 468 439 478 177 359 369 492 344 117 462 174 500 438 485 387 401 22 49 140 489 255 319 93 142 456 308 289 82 152 65 6 216 243 477 362 153 279 263 427 419 348 16 281 66 234 55 104 2 296 493 105 253 495 274 1 219 452 3 70 119 54 146 314 162 208 360 218 392 114 166 122 466 120 432 175 423 425 306 130 330 408 103 145 187 101 260 102 414 382 377 378 87 76 205 294 437 474 365 56 481 450 139 193 40 313 384 416 112 451

// 427 276 69 412 45 138 128 63 313 255 472 268 167 247 379 373 418 73 207 272 224 387 107 111 498 256 421 358 249 20 93 121 481 484 493 149 346 257 473 166 389 56 127 102 37 70 54 489 405 205 308 234 327 363 5 50 432 497 423 495 460 275 10 394 101 449 112 49 1 362 223 143 179 189 90 318 461 231 376 83 222 239 91 34 97 260 341 283 203 150 85 400 469 440 422 464 233 110 71 225 364 15 445 467 328 267 385 444 137 6 135 300 456 129 19 181 365 424 359 240 413 115 79 62 67 122 269 433 120 173 357 414 329 220 61 453 350 156 463 457 21 25 286 178 480 246 124 227 330 301 186 72 80 458 312 297 251 448 175 109 299 380 474 155 273 22 325 48 33 119 274 289 57 4 345 284 254 36 165 434 148 58 430 226 245 77 163 410 441 29 200 411 168 60 158 171 140 281 211 86 425 210 38 104 262 454 248 487 304 466 353 141 470 355 311 253 402 41 236 118 18 399 388 331 192 123 35 237 279 12 114 315 78 98 75 133 307 360 435 108 390 409 292 202 317 488 228 324 258 486 11 96 428 170 479 151 452 31 177 367 419 229 416 216 55 196 326 64 218 9 145 392 88 366 361 374 447 294 347 320 291 99 27 375 436 53 408 397 485 221 319 130 154 81 370 198 95 306 295 89 8 451 183 309 437 287 450 100 478 215 335 139 442 28 446 261 46 44 201 348 352 92 182 483 82 52 59 264 103 500 84 393 468 65 462 14 351 332 290 26 282 32 406 420 74 232 494 277 383 113 439 455 191 212 206 243 338 382 157 340 106 369 310 30 431 7 160 492 471 378 40 477 214 372 302 159 176 429 142 105 94 43 169 238 209 162 270 403 66 280 187 195 293 266 17 496 395 134 136 153 343 39 3 146 213 377 190 459 438 354 334 131 16 235 401 490 180 250 443 197 407 51 208 265 321 174 217 76 288 13 476 244 404 314 336 144 152 391 322 426 193 23 356 241 316 344 126 116 386 296 252 271 194 132 398 368 417 219 475 263 349 68 342 230 117 323 125 381 185 305 242 337 259 204 465 42 384 199 371 172 164 188 303 339 491 482 2 147 298 415 499 184 333 24 47 161 396 278 285 87
