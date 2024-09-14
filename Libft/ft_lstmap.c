/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:39:27 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 12:08:45 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*buf;

	new_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		buf = (t_list *)malloc(sizeof(t_list));
		if (!buf)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		buf->content = f(lst->content);
		buf->next = NULL;
		ft_lstadd_back(&new_lst, buf);
		lst = lst->next;
	}
	return (new_lst);
}

/*
cc -Wall -Wextra -Werror
libft.h ft_lstmap.c ft_lstclear.c ft_lstadd_back.c ft_lstiter.c
ft_lstdelone.c ft_lstlast.c

void	*plus_one(void *content)
{
	int	*new_value;

	new_value = malloc(sizeof(int));
	if (!new_value)
		return (NULL);
	*new_value = *(int *)content + 1;
	return (new_value);
}

void	del_func(void *content)
{
	free(content);
}

void	print_func(void *content)
{
	printf("%d\n", *(int *)content);
}

int	main(void)
{
	t_list l1;
	t_list l2;
	t_list l3;

	int val1 = 1;
	int val2 = 2;
	int val3 = 3;

	l1.content = &val1;
	l2.content = &val2;
	l3.content = &val3;

	l1.next = &l2;
	l2.next = &l3;
	l3.next = NULL;

	t_list *new_list = ft_lstmap(&l1, plus_one, del_func);

	printf("Original list:\n");
	print_func(l1.content);
	print_func(l2.content);
	print_func(l3.content);

	printf("\nMapped list (plus_one):\n");
	ft_lstiter(new_list, print_func);

	// Clean up
	ft_lstclear(&new_list, del_func);

	return (0);
}*/