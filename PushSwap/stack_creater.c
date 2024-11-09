/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:08:09 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/24 12:29:04 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strjoin_sep(char const *s1, char const *s2, char const sep)
{
	size_t l;
	char *s_new;
	size_t i;
	size_t f;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	s_new = (char *)malloc((l + 2) * sizeof(char));
	if (s_new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_new[i] = s1[i];
		i++;
	}
	s_new[i++] = sep;
	f = 0;
	while (s2[f])
	{
		s_new[i++] = s2[f++];
	}
	s_new[i] = '\0';
	return (s_new);
}

void free_str(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

char *args_to_str(char **argv)
{
	char *str;
	char *new_str;
	int i;

	str = (char *)malloc(sizeof(char));
	if (!str || !argv || !*argv)
		return (NULL);
	str[0] = '\0';
	i = 1;
	while (argv[i])
	{
		new_str = ft_strjoin_sep(str, argv[i++], ' ');
		free_str(&str);
		if (!new_str)
			return (NULL);
		str = new_str;
	}
	return (str);
}

void free_int_arr(int **arr)
{
    int i = 0;
        
    if (arr)
    {
        while (arr[i])
        {
			if (arr[i])
			{
				free(arr[i]);
				arr[i] = NULL;
			}
			i++;
        }
        free(arr);
        arr = NULL;
    }
}

void free_str_arr(char **arr)
{
	int i = 0;

	if (arr)
	{
		while (arr[i])
		{
			if (arr[i])
			{
				free(arr[i]);
				arr[i] = NULL;	
			}
			i++;
		}
		free(arr);
	}
}

void free_stack(t_stack **stack)
{
	t_stack *temp;

	if (stack != NULL)
	{
		while (*stack != NULL)
		{
			temp = (*stack)->next;
			(*stack)->next = NULL;
			free(*stack);
			*stack = temp;
		}
		*stack = NULL;
	}
}

int *ft_atoi(const char *nptr)
{
    int i;
    long sing;
    long result;
    int *num;

    i = 0;
    sing = +1;
    result = 0;
	if (!nptr)
		return (NULL);
    while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
        i++;
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i++] == '-')
            sing *= -1;
    }
    while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
        result = result * 10 + (nptr[i++] - '0');
    result *= sing;
    num = (int *)malloc(sizeof(int));
    if (num == NULL || (result < -2147483648 || result > 2147483647))
        return (NULL);
    *num = (int)result;
    return (num);
}

int **arr_str_to_arr_int(char **arr_str)
{
	int **arr_i;
	int i;
	int count;

	if (!arr_str)
		return (NULL);
	i = 0;
	count = 0;
	while (arr_str[i++])
		count++;
	arr_i = (int **)malloc(sizeof(int *) * (count + 1));
	if (!arr_i)
		return (NULL);
	i = 0;
	while ( i <= count)
		arr_i[i++] = NULL;
	i = 0;
	while (arr_str[i] != NULL)
	{
		int *n = ft_atoi(arr_str[i]);
		if (!n)
			return (free_int_arr(arr_i), NULL);   
		arr_i[i++] = n;
	}
	return (arr_i);
}

void stack_add_front(t_stack **stack, t_stack *new)
{
	if (new)
	{
		new->next = stack[0];
		stack[0] = new;
	}
}

int stack_count(t_stack *stack)
{
    t_stack *temp;
    int count;

    count = 0;
	if (!stack)
		return (count);
    temp = stack;
	while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
	return (count);
}

t_stack	*stack_last(t_stack *stack)
{
    t_stack *temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void stack_add_back(t_stack **stack, t_stack *new)
{
    t_stack *last;
    
	if (new)
	{
        last = stack_last(stack[0]);
        if (last)
            last->next = new;
        else
			*stack = new;
	}
}

t_stack *new_stack(int i)
{
	t_stack *stack;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = i;
	stack->next = NULL;
	return (stack);
}

t_stack *arr_int_to_stack(int **arr)
{
	t_stack *stack;
	t_stack *new;
	int i;

	stack = NULL;
	i = 0;
	while (arr[i])
	{
		new = new_stack(*(arr[i]));
		if (!new)
			return (free_stack(&stack), NULL);
		stack_add_back(&stack, new);
		i++;
	}
	return (stack);
}

int check_int_arr(int **arr)
{
	int c;
	int i;
	int j;

	c = 0;
	while (arr[c])
		c++;
	if (c < 2)
		return (0);
	i = 0;
	while (i < c - 1 && arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (*(arr[i]) == *(arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack *create_stacks(int argc, char **argv)
{
	char *str;
	char **arr_str;
	int **arr_i;
	t_stack *stack;

	if (argc < 2)
		return (NULL);
	str = args_to_str(argv);
	if (!str)
		return (NULL);
	arr_str = ft_split(str, ' ');
	free_str(&str);
	if (!arr_str)
		return (NULL);
	arr_i = arr_str_to_arr_int(arr_str);
	free_str_arr(arr_str);
	if (!arr_i)
		return (NULL);
	if (check_int_arr(arr_i) == 0)
		return (free_int_arr(arr_i), NULL);
	stack = arr_int_to_stack(arr_i);
	free_int_arr(arr_i);
	return (stack);
}
