#include "push_swap.h"

// void free_char_arr(char **arr)
// {
// 	int i = 0;
// 	if (*arr)
// 	{
// 		while (arr[i])
// 		{
// 			free(arr[i]);
// 			arr[i] = NULL;
// 			i++;
// 		}
// 		*arr = NULL;
// 	}
// }

// int *ft_arg_2_int(char *arg)
// {
// 	int *num;
// 	int i;
// 	int len;

// 	if (!arg)
// 		return (NULL);
// 	len = ft_strlen(arg);
// 	if (len < 1)
// 		return (NULL);
// 	i = 0;
// 	while (arg[i])
// 	{
// 		if (ft_isdigit(arg[i]) == 1 || (i == 0 && (arg[i] == '-' || arg[i] == '+') && len > 1))
// 			i++;
// 		else
// 			return (NULL);
// 	}
// 	num = (int *)malloc(sizeof(int));
// 	if (!num)
// 		return (NULL);
// 	*num = ft_atoi(arg);
// 	return (num);
// }

// // {
// //  char **arr;
// //  arr = ft_split(arg, ' ');
// //  if (!arr)
// //  {
// //      //!!!!!!!!!!!!!!!!!!!!!!! free
// //      printf("Error\n");
// //      return (-1);
// //  }
// //  return (0);
// // }
// void del_func(void *content)
// {
// 	free(content);
// }

// int **str_to_nums_arr(char *str)
// {
// 	char **arr;

// 	char **arr = ft_split(str, ' ');
// 	if (!arr)
// 	{
// 	}
// }

// int fill_stack_from_str(char *str, t_list **stack1)
// {
// 	char **arr = ft_split(str, ' ');
// 	free(str);
// 	if (!arr)
// 		return (return_error());

// 	for (int t = 0; arr[t]; t++)
// 	{
// 		int *num = ft_arg_2_int(arr[t]);
// 		free(arr[t]);
// 		if (!num)
// 		{
// 			ft_lstclear(stack1, del_func);
// 			free(arr);
// 			return (return_error());
// 		}
// 		t_list *new = ft_lstnew(num);
// 		if (!new)
// 		{
// 			ft_lstclear(stack1, del_func);
// 			free(arr);
// 			return (return_error());
// 		}
// 		ft_lstadd_front(stack1, new);
// 	}
// 	free(arr);
// 	return (0);
// }
// // int  create_stacks(int argv, char **argc, t_list **stack1)
// // {
// //  int i;
// //  char *str;

// //  i = 1;
// //  if (argv < 2)
// //      return (return_error());
// //  else
// //  {
// //      str = (char *)malloc(sizeof(char));
// //      if (!str)
// //          return (return_error());
// //      str[0] = '\0';
// //      while (argc[i])
// //      {
// //          char *new_str = ft_strjoin_sep(str, argc[i], ' ');
// //          if (str)
// //          {
// //              free(str);
// //              str = NULL;
// //          }
// //          if (!new_str)
// //              return (return_error());
// //          str = new_str;
// //          i++;
// //      }
// //      char **arr = ft_split(str, ' ');
// //      if (str)
// //      {
// //          free(str);
// //          str = NULL;
// //      }
// //      //----------
// //      if (!arr)
// //          return (return_error());

// //      int t = 0;
// //      while (arr[t])
// //      {
// //          int *num = ft_arg_2_int(arr[t]);
// //          free(arr[t]);
// //          arr[t] = NULL;
// //          if (!num)
// //          {
// //              printf("ERROR 11111");
// //              ft_lstclear(stack1, del_func);
// //              if (arr)
// //              {
// //                  int s = 0;
// //                  while (arr[s])
// //                  {
// //                      free(arr[s]);
// //                      arr[s] = NULL;
// //                      s++;
// //                  }
// //                  free(arr);
// //                  arr = NULL;
// //              }
// //              return (-1);
// //          }
// //          t_list *new = ft_lstnew(num);
// //          if (!new)
// //          {
// //              printf("ERROR 2222222");
// //              if (arr)
// //              {
// //                  int s = 0;
// //                  while (arr[s])
// //                  {
// //                      free(arr[s]);
// //                      arr[s] = NULL;
// //                      s++;
// //                  }
// //                  free(arr);
// //                  arr = NULL;
// //              }
// //              return (-1);
// //              ft_lstclear(stack1, del_func);
// //              return (-1);
// //          }
// //          ft_lstadd_front(stack1, new);
// //          t++;
// //      }
// //      if (arr)
// //      {
// //          int s = 0;
// //          while (arr[s])
// //          {
// //              free(arr[s]);  // Освобождаем каждый элемент
// //              arr[s] = NULL;
// //              s++;
// //          }
// //          free(arr);  // Освобождаем сам массив
// //          arr = NULL;
// //      }

// //      t_list *temp;
// //      while (*stack1 != NULL)
// //      {
// //          temp = (*stack1)->next;
// //          printf("test %d\n", *(int *)(*stack1)->content);
// //          free((*stack1)->content);
// //          (*stack1)->content = NULL;
// //          (*stack1)->next = NULL;
// //          free(*stack1);
// //          *stack1 = temp;
// //      }
// //      if (*stack1)
// //      {
// //          printf("4 free arr\n");
// //          free(*stack1);
// //          *stack1 = NULL;
// //      }
// //      stack1 = NULL;
// //  }
// //  // //TODO!!!! Check the numbers in stack > 1!
// //     // //TODO!!!! Check the numbers in stack is not the same!
// //  return (0);
// // }

// void free_stack(t_list **stack1)
// {
// 	t_list *temp;
// 	while (*stack1 != NULL)
// 	{
// 		temp = (*stack1)->next;
// 		free((*stack1)->content);
// 		free(*stack1);
// 		*stack1 = temp;
// 	}
// }

//-------------------------
//-------------------------
//-------------------------

void free_int_arr(int **arr)
{
	int i = 0;

	if (arr != NULL)
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
	}
}

void free_str_arr(char **arr)
{
	int i = 0;

	if (arr != NULL)
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
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
			if ((*stack)->num != NULL)
			{
				free((*stack)->num);
				(*stack)->num = NULL;
			}
			(*stack)->next = NULL;
			free(*stack);
			*stack = temp;
		}
		*stack = NULL;
	}
}

int **arr_str_to_arr_int(char **arr_str)
{
	int **arr_i;
	int i;
	int count;

	i = 0;
	count = 0;
	while (arr_str[i++])
		count++;
	arr_i = (int **)malloc(sizeof(int *) * (count + 1));
	if (!arr_i)
		return (NULL);
	i = 0;
	while (arr_str[i])
	{
		int *n = (int *)malloc(sizeof(int));
		if (!n)
			return (free_int_arr(arr_i), NULL);
		*n = i;
		arr_i[i] = n; // num //arr_str[i]
		// to num (check min max)
		i++;
	}
	arr_i[count] = NULL;
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

t_stack *new_stack(int i)
{
	t_stack *stack;
	int *num;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	num = (int *)malloc(sizeof(int));
	if (!num)
		return (free(stack), NULL);
	*num = i;
	stack->num = num;
	stack->next = NULL;
	//printf("NEW STASK: num: %d,next: %p\n", *(int *)(stack)->num , stack->next);
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
		//printf("arr st: %d\n", *(arr[i]));
		new = new_stack(*(arr[i]));
		if (!new)
		{
			//printf("NEW STASK ERROR\n");
			return (free_stack(&stack), NULL);
		}
		stack_add_front(&stack, new);
		i++;
	}
	return (stack);
}

int chech_int_arr(int **arr)
{
	int i = 0;

	while (arr[i])
	{
		if (*(arr[i]) < 0)
			return (0);
		i++;
	}
	// error - return (0);
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

	//printf("str: %s\n", str);

	arr_str = ft_split(str, ' ');
	free_str(&str);
	if (!arr_str)
		return (NULL);

	// int tr = 0;
	// while (arr_str[tr])
	// {
	// 	printf("%d arr_str: %s\n", tr, arr_str[tr]);
	// 	tr++;
	// }

	arr_i = arr_str_to_arr_int(arr_str);
	free_str_arr(arr_str);
	if (!arr_i)
		return (NULL);

	// int ta = 0;
	// while (arr_i[ta])
	// {
	// 	printf("%d arr_i: %d\n", ta, *(arr_i[ta]));
	// 	ta++;
	// }

	if (chech_int_arr(arr_i) == 0)
		return (free_int_arr(arr_i), NULL);
	stack = arr_int_to_stack(arr_i);
	free_int_arr(arr_i);
	return (stack);
}
int main(int argc, char **argv)
{
	t_stack *stack1;
//	t_stack *stack2;

	// stack2 = (t_stack *)malloc(sizeof(t_stack));
	// if (!stack2)
	// 	return (return_error());
	stack1 = create_stacks(argc, argv);
	if (!stack1)
		return (return_error());
		//return (free(stack2), return_error());

	printf("+++++++++++\n");
	int ss = 0;
	while (stack1 != NULL)
	{
		// t_stack *temp = stack1->next;

		printf("%d stack: %d\n", ss, *(int *)stack1->num);

		stack1 = stack1->next;
		ss++;
	}
	printf("ss: %d---\n", ss);
	//stack1 = temp;
	printf("---\n");

	free_stack(&stack1);
//	free(stack2);
	return (0);
}

int return_error(void)
{
	printf("Error\n"); /// TODO ft_printf !!!!!
	return (-1);
}

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
	i = 0;
	while (argv[i])
	{
		new_str = ft_strjoin_sep(str, argv[i++], ' ');
		free_str(&str);
		str = NULL;
		if (!new_str)
			return (NULL);
		str = new_str;
	}
	return (str);
}
