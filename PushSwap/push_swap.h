/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:07:57 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/23 13:20:37 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    int *num;
    struct s_stack *next;
} t_stack;

int return_error(void);
size_t ft_strlen(const char *s);
void free_str(char **str);
void free_stack(t_stack **stack);
char *ft_strjoin_sep(char const *s1, char const *s2, char const sep);
char *args_to_str(char **argv);
char **ft_split(char const *s, char c);
void free_int_arr(int **arr);
void free_str_arr(char **arr);
int *ft_atoi(const char *nptr);
int **arr_str_to_arr_int(char **arr_str);
int stack_count(t_stack **stack);
t_stack	*stack_last(t_stack *stack);
void stack_add_back(t_stack **stack, t_stack *new);
void stack_add_front(t_stack **stack, t_stack *new);
t_stack *new_stack(int i);
t_stack *arr_int_to_stack(int **arr);
int chech_int_arr(int **arr);
t_stack *create_stacks(int argc, char **argv);

#endif