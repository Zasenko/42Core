/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:49 by dzasenko          #+#    #+#             */
/*   Updated: 2024/11/12 14:29:14 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 350 143 182 457 383 66 316 480 223 16 224 482 391 115 108 221 439 2 400 416 386 169 313 371 486 403 314 345 425 275 426 26 152 201 389 205 359 41 233 472 229 419 375 369 410 406 456 210 105 362 45 244 495 411 304 360 231 268 36 395 96 299 435 78 86 294 431 75 247 500 255 189 173 453 38 19 390 351 174 364 53 397 373 180 498 12 449 63 103 82 196 50 442 387 18 459 354 476 485 477 46 111 20 491 438 122 176 421 207 10 263 417 13 429 48 33 14 300 42 251 138 319 469 324 1 408 499 237 188 312 344 372 194 376 160 423 141 281 484 236 23 461 490 168 479 492 333 260 40 382 11 130 307 270 325 402 443 73 292 219 150 340 279 380 177 116 280 446 413 4 385 44 284 332 424 326 305 195 216 83 401 330 455 256 489 112 278 74 5 35 348 321 30 209 55 56 311 43 342 187 474 353 47 388 225 493 148 110 245 200 466 172 145 134 377 451 136 213 15 91 88 323 481 59 93 146 123 159 331 128 240 405 165 346 49 242 398 17 98 367 79 248 54 104 185 8 31 441 306 70 336 338 62 181 84 99 277 113 25 303 249 285 29 392 370 487 488 222 437 432 448 39 384 291 475 7 162 357 381 287 226 374 478 81 368 34 22 64 90 496 352 463 147 6 365 94 407 158 106 186 132 114 366 396 462 65 283 460 293 37 212 430 153 95 21 271 378 197 298 483 206 288 208 257 310 290 266 409 274 458 154 445 220 473 87 494 355 214 415 296 125 358 24 356 142 427 422 252 3 227 433 9 297 418 276 243 61 202 464 259 379 230 273 166 239 347 269 71 118 167 175 497 183 272 241 343 102 309 414 52 363 434 267 97 467 149 215 361 51 468 452 250 444 32 254 68 131 412 264 137 339 262 349 440 89 129 124 450 184 327 203 465 335 328 404 211 261 100 193 204 156 109 337 282 28 428 322 60 140 190 178 394 119 258 341 191 164 198 127 218 161 286 295 334 265 67 27 246 139 117 235 436 120 76 107 163 234 399 179 289 420 85 155 253 144 57 318 151 232 69 199 58 238 308 217 135 171 320 80 471 121 317 447 192 329 101 170 228 302 157 393 133 315 301 454 92 126 470 77 72

#include "push_swap.h"

// TODO: delete counter
extern int counter;

int pos_for_n_in_sort_stack(t_stack *stack, int num, int min, int max, int count);
void sort_back(t_stack **stack_a, t_stack **stack_b);

int moves_in_b(t_stack **stack_a, t_stack **stack_b, int min_b, int max_b, int b_counter);

int moves_in_a(t_stack **stack_a, t_stack **stack_b, int max_b, int a_counter);

int stack_max_n(t_stack *stack)
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

int stack_min_n(t_stack *stack)
{
    t_stack *tmp = stack;
    int min = 2147483647;
    while (tmp)
    {
        if (tmp->num < min)
            min = tmp->num;
        tmp = tmp->next;
    }
    return min;
}

int unsort_stack_top_greater_n_pos(t_stack *stack, int num)
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

int unsort_stack_btm_greater_n_pos(t_stack *stack, int num, int len)
{
    t_stack *last = stack_last(stack);
    if (!last)
        return (0);
    if (last->num < num)
    {
        while (len && last->num < num)
        {
            last = stack_last_n(stack, (len--) - 1);
        }
        return (len);
    }
    else
    {
        return (len - 1);
    }
}

int unsort_stack_top_pos_between(t_stack *stack, int min, int max)
{
 /////printf("----- unsort_stack_top_pos_between ------\n");
 /////printf("min: %d, max: %d\n", min, max);
    t_stack *tmp = stack;

    if (!tmp)
        return -1;
    int i = 0;  
    while (tmp)
    {
        if (tmp->num >= min && tmp->num <= max)
        {
            /////printf("last->num: %d, i: %d\n", tmp->num, i);
            return i;
        }
        tmp = tmp->next;
        i++;
    }
    return -1;
}

int unsort_stack_btm_pos_between(t_stack *stack, int min, int max, int len)
{
    ///////printf("----- unsort_stack_btm_pos_between ------\n");
    ///////printf("min: %d, max: %d, len: %d\n", min, max, len);

    t_stack *last = stack_last(stack);

    if (!last)
    {
    //  /////printf("Error !last\n");
        return (0);
    }

    while (len && last)
    {
        if (last->num >= min && last->num <= max)
        {
        //  /////printf("last->num: %d, len: %d\n", last->num, len);
            return --len;
        }
        len--;
        last = stack_last_n(stack, len - 1);
    }
    return (len);
}

int stack_n_pos(t_stack *stack, int num)
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

int num_in_stack_by_pos(t_stack *stack, int pos)
{
    t_stack *tmp = stack;
    if (!tmp)
        return -1;
    int i = 0;
    ////printf("-i: %d, pos: %d\n", i, pos);
    while (i < pos)
    {
        ////printf("--i: %d, pos: %d\n", i, pos);
        tmp = tmp->next;
        i++;
    }
    return tmp->num;
}

int sort_stack_top_greater_n_pos(t_stack *stack, int num)
{
    t_stack *tmp = stack;
    int i = 0;

    if (!tmp)
        return (-1);
    while (tmp && num > tmp->num)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

int sort_stack_top_less_n_pos(t_stack *stack, int num)
{
    t_stack *tmp = stack;
    int i = 0;

    if (!tmp)
        return (-1);
    while (tmp && num < tmp->num)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

int sort_stack_btm_greater_n_pos(t_stack *stack, int num, int len)
{
    t_stack *last = stack_last(stack);
    if (!last)
        return (-1);
    while (len && last->num > num)
    {
        len--;
        last = stack_last_n(stack, len - 1);
    }
    return (len);//+ // return 0 - ERROR????
}

int sort_stack_btm_greater_n_pos222(t_stack *stack, int num, int len)
{
    t_stack *last = stack_last(stack);
    if (!last)
        return (-1);
    //printf("num: %d, len: %d\n", num, len);
    if (last->num < num)
    {
        while (len && last->num > num)
        {
            //printf("--num: %d, len: %d\n", num, len);
            len--;
            last = stack_last_n(stack, len - 1);
        }
    }
    else
    {
        return (len - 1);
    }
    return (len); //+ // return 0 - ERROR????
}

int sort_stack_btm_greater_n_pos333(t_stack *stack, int num, int len)
{
    t_stack *last = stack_last(stack);
    if (!last)
        return (-1);
    //printf("num: %d, len: %d, last num: %d\n", num, len, last->num);
    if (last->num < num)
    {
        while (len && last->num > num)
        {
            //printf("--num: %d, len: %d\n", num, len);
            len--;
            last = stack_last_n(stack, len - 1);
        }
    }
    return (len); //+ // return 0 - ERROR????
}

int sort_stack_btm_less_n_pos333(t_stack *stack, int num, int len)
{
    t_stack *last = stack_last(stack);
    if (!last)
        return (-1);
    //printf("num: %d, len: %d, last num: %d\n", num, len, last->num);
    if (last->num < num)
    {
        while (len && last->num < num)
        {
            //printf("--num: %d, len: %d\n", num, len);
            len--;
            last = stack_last_n(stack, len - 1);
        }
    }
    return (len); //+ // return 0 - ERROR????
}

void sort_3(t_stack **stack, char c)
{
    int n1;
    int n2;
    int n3;

    if (!stack || !*stack || stack_count(*stack) != 3)
        return; 
    n1 = (*stack)->num;
    n2 = (*stack)->next->num;
    n3 = (*stack)->next->next->num;

    if (n1 < n2 && n2 > n3 && n1 < n3)
    {
        //  1
        //  3
        //  2
        ///////printf("------ sort 0.1 ------\n");
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
        //  2
        //  3
        //  1
        ///////printf("------ sort 0.2 ------\n");
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
        //  2
        //  1
        //  3
        ///////printf("------ sort 0.3 ------\n");
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
        //  3
        //  1
        //  2
        ///////printf("------ sort 0.4 ------\n");
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
        //  3
        //  2
        //  1
        ///////printf("------ sort 0.5 ------\n");
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
        //  1
        //  2
        //  3
        ///////printf("------ sort 0.0 ------\n");

        if (c == 'a')
            return;
        else
        {
            rb(stack);
            sb(*stack);
        }
    }
}

void sort_2(t_stack **stack_a)
{
    if ((*stack_a)->num > (*stack_a)->next->num)
        sa(*stack_a);
}

int stack_range(int min, int max)
{
    int i = 0;

    while(min <= max)
    {
        i++;
        min++;
    }
    return i;
}

int count_n_in_range_in_stask(t_stack *stack, int min, int max)
{
    int i = 0;
    t_stack *temp = stack;

    if (!temp)
        return (0);
    while(temp)
    {
        if (temp->num >= min && temp->num <= max)
            i++;
        temp = temp->next;
    }
    return i;
}

void set_min_max(t_stack *stack, int *min, int *max)
{
    if (!stack || !min || !max)
        return ;
    if (stack->num < *min)
        *min = stack->num;
    if (stack->num > *max)
        *max = stack->num;
}

void push_b(t_stack **stack_a, t_stack **stack_b, int *a_count, int *b_count)
{
    if (!stack_a || !stack_b || !a_count || !b_count)
        return;
    pb(stack_a, stack_b);
    *a_count -= 1;
    *b_count += 1;
}

int moves_top_top(int top_a, int top_b)
{
    if (top_a >= top_b)
        return top_a;
    return top_b;
}

int moves_btm_btm(int btm_a, int btm_b)
{
    if (btm_a >= btm_b)
        return btm_a;
    return btm_b;
}
int moves_top_btm(int top_a, int btm_b)
{
    return top_a + btm_b;
}
int moves_btm_top(int btm_a, int top_b)
{
    return btm_a + top_b;
}

void set_minimum_moves(t_stack *temp, int top_moves_a, int btm_moves_a, int top_moves_b, int btm_moves_b)
{
    //printf("-- set minimum moves --\n");
    //printf("for NUMBER: %d\n", temp->num);
    //printf("top_moves_a: %d, btm_moves_a: %d, top_moves_b: %d, btm_moves_b: %d\n", top_moves_a, btm_moves_a, top_moves_b, btm_moves_b);
    int min_move = 0;
    
    min_move = moves_top_top(top_moves_a, top_moves_b);
    //printf("moves_top_top: %d\n", min_move);

    temp->is_top_a = 1;
    temp->is_top_b = 1;
        
    int min_btm_btm = moves_btm_btm(btm_moves_a, btm_moves_b);
    //printf("moves_btm_btm: %d\n", min_btm_btm);
    if (min_move > min_btm_btm)
    {
        
        min_move = min_btm_btm;
        temp->is_top_a = 0;
        temp->is_top_b = 0;
    }
    
    int min_top_btm = moves_top_btm(top_moves_a, btm_moves_b);
    //printf("moves_top_btm: %d\n", min_top_btm);
    if (min_move > min_top_btm)
    {
        min_move = min_top_btm;
        temp->is_top_a = 1;
        temp->is_top_b = 0;
    }
    
    int min_btm_top = moves_btm_top(btm_moves_a, top_moves_b);
    //printf("moves_btm_top: %d\n", min_btm_top);
    if (min_move > min_btm_top)
    {
        min_move = min_btm_top;
        temp->is_top_a = 0;
        temp->is_top_b = 1;
    }
    
    //printf("min_move: %d\n", min_move);
    temp->moves = min_move;
}

void set_cheapest_position(t_stack *stack_a, t_stack *stack_b, int a_count, int b_count, int b_min, int b_max)
{
    //printf("-- set cheapest position --\n");
    
    t_stack *temp;
    int top_moves_a;
    int btm_moves_a;
    int top_moves_b;
    int btm_moves_b;

    top_moves_a = 0;
    temp = stack_a;
    while (temp)
    {
        btm_moves_a = a_count - top_moves_a;
        if (btm_moves_a == a_count)
            btm_moves_a = 0;
        top_moves_b = pos_for_n_in_sort_stack(stack_b, temp->num, b_min, b_max, b_count);
        btm_moves_b = b_count - top_moves_b;
        if (btm_moves_b == b_count)
            btm_moves_b = 0;
        set_minimum_moves(temp, top_moves_a, btm_moves_a, top_moves_b, btm_moves_b);
        temp = temp->next;
        top_moves_a++;
    }
}

int find_cheapest_position(t_stack *stack_a, t_stack *stack_b, int a_count, int b_count, int b_min, int b_max)
{
    //printf("-- find cheapest position --\n");
    set_cheapest_position(stack_a, stack_b, a_count, b_count, b_min, b_max);

    int i = 0;
    t_stack *temp = stack_a;
    int min = temp->moves;
    int min_i = 0;
    
    while (temp)
    {
        if (temp->moves < min)
        {
            min = temp->moves;
            min_i = i;
        }
        i++;
        temp = temp->next;
    }
    return min_i;
}

t_stack *item_in_stack_by_pos(t_stack *stack, int pos)
{
    t_stack *tmp = stack;
    if (!tmp)
        return NULL;
    int i = 0;
    ////printf("-i: %d, pos: %d\n", i, pos);
    while (i < pos)
    {
        ////printf("--i: %d, pos: %d\n", i, pos);
        tmp = tmp->next;
        i++;
    }
    return tmp;
}

void rotate_stacks(t_stack push_item, int position, t_stack **stack_a, t_stack **stack_b, int a_count, int b_count, int b_min, int b_max)
{
    int top_moves_a;
    int btm_moves_a;
    int top_moves_b;
    int btm_moves_b;

    top_moves_a = position;
    btm_moves_a = a_count - position;
    if (btm_moves_a == a_count)
            btm_moves_a = 0;

    top_moves_b = pos_for_n_in_sort_stack(*stack_b, push_item.num, b_min, b_max, b_count);
    btm_moves_b = b_count - top_moves_b;
    if (btm_moves_b == b_count)
        btm_moves_b = 0;
    
    if (push_item.is_top_a && push_item.is_top_b)
    {
        if (top_moves_a >= top_moves_b)
        {
            while (top_moves_a-- > 0)
            {
                if (top_moves_b-- > 0)
                    rr(stack_a, stack_b);
                else
                    ra(stack_a);
            }
        }
        else
        {
            while (top_moves_b-- > 0)
            {
                if (top_moves_a-- > 0)
                    rr(stack_a, stack_b);
                else
                    rb(stack_b);
            }
        }
    }
    else if (!push_item.is_top_a && !push_item.is_top_b)
    {
        if (btm_moves_a >= btm_moves_b)
        {
            while (btm_moves_a-- > 0)
            {
                if (btm_moves_b-- > 0)
                    rrr(stack_a, stack_b);
                else
                    rra(stack_a);
            }
        }
        else
        {
            while (btm_moves_b-- > 0)
            {
                if (btm_moves_a-- > 0)
                    rrr(stack_a, stack_b);
                else
                    rrb(stack_b);
            }
        }
    }
    else if (push_item.is_top_a && !push_item.is_top_b)
    {
        while (top_moves_a-- > 0)
            ra(stack_a);
        while (btm_moves_b-- > 0)
            rrb(stack_b); 
    }
    else if (!push_item.is_top_a && push_item.is_top_b)
    {
        while (top_moves_b-- > 0)
            rb(stack_b);
        while (btm_moves_a-- > 0)
            rra(stack_a); 
    }
}

void test(t_stack **stack_a, t_stack **stack_b)
{
    int a_count;
    int b_count;
    int b_min;
    int b_max;

    a_count = stack_count(*stack_a);
    b_count = 0;
    b_min = 2147483647;
    b_max = -2147483648;
    while (a_count > 3)
    {
        //printf("======================================\n");
        //printf("a_count: %d, b_count: %d, b_min: %d, b_max: %d\n", a_count, b_count, b_min, b_max);

        if (b_count > 1)
        {
            //printf("- b_count > 1 -\n");
            int position = find_cheapest_position(*stack_a, *stack_b, a_count, b_count, b_min, b_max);
            t_stack *push_item = item_in_stack_by_pos(*stack_a, position);
            //printf("CHEAPEST POSITION: %d\n", position);
            if(push_item)
            {
                rotate_stacks(*push_item, position, stack_a, stack_b, a_count, b_count, b_min, b_max);
                //printf("--- stack_a after ROTATE ---\n");
	            //print_stack(*stack_a);
	            //printf("--- stack_b after ROTATE ---\n");
	            //print_stack(*stack_b);
            }
        }
        push_b(stack_a, stack_b, &a_count, &b_count);
        set_min_max(*stack_b, &b_min, &b_max);
        //printf("--- stack_a after PUSH ---\n");
        //print_stack(*stack_a);
	    //printf("--- stack_b after PUSH ---\n");
	    //print_stack(*stack_b);
    }
    sort_back(stack_a, stack_b);
}

void sort_back(t_stack **stack_a, t_stack **stack_b)
{
    ////printf("\n----- SORT BACK -----\n");
    sort_3(stack_a, 'a');

   // //printf("\n-- stack_a after SORT 3 --\n");
   // //print_stack(*stack_a);

    int min_a = stack_min_n(*stack_a);
    int max_a = stack_max_n(*stack_a);
    int a_count = stack_count(*stack_a);
  //  int b_count = stack_count(*stack_b);

    while (*stack_b)
    {
       // //printf("--- for NUM %d ---\n", (*stack_b)->num);
        if ((*stack_b)->num < min_a || (*stack_b)->num > max_a)
        {
            ////printf("--- 1 ---\n");
            int position = stack_n_pos(*stack_a, min_a); //+
         //   //printf("position: %d, counter / 2: %d\n", position, a_count / 2);
            if (position < a_count / 2 || (a_count % 2 != 0 && (a_count / 2) == position))
            {
               // //printf("--- + ! 1.1.1 ---\n");
                int i = 0;
                while (i < position)
                {
                    ra(stack_a);
                    i++;
                }
            }
            else
            {
            //    //printf("--- ! 1.1.2 ---\n");
                int i = 0;
                while (i < a_count - position)
                {
                    rra(stack_a);
                    i++;
                }
            }
        }
        else
        {
            ////printf("--- 2 ---\n");
            if ((*stack_b)->num < (*stack_a)->num)
            {
               // //printf("--- 2.1 ---\n");

                t_stack *last = stack_last(*stack_a);
                if (last)
                {
                    if (last->num > (*stack_b)->num)
                    {
                        ////printf("--- 2.1.1 ---\n");
                        int position = sort_stack_btm_greater_n_pos(*stack_a, (*stack_b)->num, a_count); // TODO ПРОВЕРИТЬ С sort_stack_btm_greater_n_pos222

                        // //printf("position: %d, count: %d, counter / 2: %d\n", position, a_count, a_count / 2);

                        if (position < a_count / 2 || (a_count % 2 != 0 && (a_count / 2) == position))
                        {
                           // //printf("--- + 2.1.1.11 ---\n");
                            int i = 0;
                            while (i < position)
                            {
                                ra(stack_a);
                                i++;
                            }
                        }
                        else
                        {
                           // //printf("--- + 2.1.1.22 ---\n");
                            int i = 0;
                            while (i < a_count - position)
                            {
                                rra(stack_a);
                                i++;
                            }
                        }
                    }
                    else
                    {
                       // //printf("--- ! 2.1.2 no move needed ---\n");
                    }
                }
            }
            else
            {
                int position = sort_stack_top_greater_n_pos(*stack_a, (*stack_b)->num);
                ////printf("position: %d, counter / 2: %d\n", position, a_count / 2);
                if (position < a_count / 2 || (a_count % 2 != 0 && a_count / 2 == position))
                {
                    ////printf("--- ! 2.2.1 ---\n");
                    int i = 0;
                    while (i < position)
                    {
                        ra(stack_a);
                        i++;
                    }
                }
                else
                {
                    t_stack *stack_a_last = stack_last(*stack_a);
                    if (stack_a_last)
                    {
                        if (stack_a_last->num < (*stack_b)->num)
                        {
                        //    //printf("--- ! 2.2.2.1 ---\n");
                            int s = a_count - position;
                            int i = 0;
                            while (i < s)
                            {
                                rra(stack_a);
                                i++;
                            }
                        }
                        else
                        {
                           // //printf("--- + 2.2.2.2 ---\n");
                            int s = a_count - position;
                            int i = 0;
                            while (i < s)
                            {
                                rra(stack_a);
                                i++;
                            }
                        }
                    }
                }
            }
        }
        pa(stack_a, stack_b);
        a_count++;
        
        // NEW MIN MAX
        if ((*stack_a)->num < min_a)
        {
            min_a = (*stack_a)->num;
        }
        else if ((*stack_a)->num > max_a)
        {
            max_a = (*stack_a)->num;
        }

        ////printf("\n-- stack_a after sort --\n");
        ////print_stack(*stack_a);
        //printf("\n-- stack_b after sort --\n");
        //print_stack(*stack_b);
    }

    ////printf("--- 0000 last ---\n");

    //TODO!!!!! doublicate
    int position = stack_n_pos(*stack_a, min_a); //+
    ////printf("position: %d, counter / 2: %d\n", position, a_count / 2);
    if (position < a_count / 2 || (a_count % 2 != 0 && (a_count / 2) == position))
    {
        int i = 0;
        while (i < position)
        {
            ra(stack_a);
            i++;
        }
    }
    else
    {
        int i = 0;
        while (i < a_count - position)
        {
            rra(stack_a);
            i++;
        }
    }
}

int pos_for_n_in_sort_stack(t_stack *stack, int num, int min, int max, int count)
{
    int position = 0;
    ////printf("-- position for %d in sort_stack --\n", num);
    ////printf("stack: min: %d, max: %d | count: %d\n", min, max, count);

    if (num < min || num > max)
    {
        ////printf("--- 1 ---\n");
        position = stack_n_pos(stack, max);
    }
    else
    {
        if (num < stack->num)
        {
            ////printf("--- 2 ---\n");
            //printf("000000\n");

            t_stack *l = stack_last(stack);
            if (l)
            {
                if (num > l->num)
                {
                    //printf("1\n");

                    
                    position = sort_stack_top_less_n_pos(stack, num);
                }
                else
                {
                    //printf("+2\n");
                    position = sort_stack_top_less_n_pos(stack, num);
                }
            }

            // if (position < (count / 2) || (count % 2 != 0 && (count / 2) == position))
            // {
            //     while (i < position)
            //     {
            //         //rb
            //         i++;
            //     }
            // }
            // else
            // {
            //     while (i < count - position)
            //     {
            //         //rrb
            //         i++;
            //     }
            // }
        }
        else
        {
            //printf("--- 222222222 ---\n");

                t_stack *l = stack_last(stack);
                if (l)
                {
                    if (num > l->num )
                    {
                        //printf("+ 1\n");

                        position = sort_stack_btm_less_n_pos333(stack, num, count);
                    }
                    else
                    {
                        //printf("2\n");

                        if (num < l->num && num < l->num)
                        {
                            //printf("3\n");
                            return 0;
                        }
                        else {
                            //printf("4\n");
                            position = sort_stack_btm_greater_n_pos333(stack, num, count);
                        }
                        
                    }
                }
        }
    }
    return position;
}

void sort(t_stack **stack_a, t_stack **stack_b)
{
    int a_count;

    a_count = stack_count(*stack_a);
    if (a_count == 1)
        return ;
    else if (a_count == 2)
        sort_2(stack_a);
    else if (a_count == 3)
        sort_3(stack_a, 'a');
    else
        test(stack_a, stack_b);
    return ;
}