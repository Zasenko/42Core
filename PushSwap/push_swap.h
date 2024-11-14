/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/10/18 10:07:57 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/24 12:57:56 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int num;
	struct s_stack *next;
	int index;
	int moves;
	int is_top_a;
	int is_top_b;
} t_stack;

typedef struct s_prop
{
	int a_count;
	int b_count;
	int min;
	int b_min;
	int b_max;
} t_prop;

typedef struct s_moves
{
	int top_moves_a;
    int btm_moves_a;
    int top_moves_b;
    int btm_moves_b;
} t_moves;

void	print_stack(t_stack *stack); // TODO: Delete

size_t	ft_strlen(const char *s);
void	free_str(char **str);
void	free_stack(t_stack **stack);
char	*ft_strjoin_sep(char const *s1, char const *s2, char const sep);
char	*args_to_str(char **argv);
char	**ft_split(char const *s, char c);
void	free_int_arr(int **arr);
void	free_str_arr(char **arr);
int	*ft_atoi(const char *nptr);
int	**arr_str_to_arr_int(char **arr_str);
int	stack_count(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_last_n(t_stack *stack, int count);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
t_stack	*new_stack(int i);
t_stack	*arr_int_to_stack(int **arr);
int	check_int_arr(int **arr);
t_stack	*create_stacks(int argc, char **argv);

int pos_for_n_in_stack_b(t_stack *stack, int num, t_prop prop);
void rotate_stacks(t_stack push_item, t_stack **stack_a, t_stack **stack_b, t_prop prop);
void find_minimum_moves(t_stack *temp, t_moves moves);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	sort(t_stack **stack_a, t_stack **stack_b);

#endif