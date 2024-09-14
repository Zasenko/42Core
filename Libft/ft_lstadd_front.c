/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:34:32 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 13:50:44 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = lst[0];
		lst[0] = new;
	}
}
/*
//cc -Wall -Wextra -Werror libft.h ft_lstnew.c ft_lstadd_front.c

void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d -> ", *(int *)lst->content);  // Cast !!!
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list *head = NULL;

	printf("Test 1 - Adding to empty list:\n");
	int val1 = 42;
	t_list *new_node1 = ft_lstnew(&val1);
	ft_lstadd_front(&head, new_node1);
	print_list(head);  // 42 -> NULL

	printf("Test 2 - Adding new node to the front:\n");
	int val2 = 84;
	t_list *new_node2 = ft_lstnew(&val2);
	ft_lstadd_front(&head, new_node2);
	print_list(head);  // 84 -> 42 -> NULL

	printf("Test 3 - Adding another node to the front:\n");
	int val3 = 21;
	t_list *new_node3 = ft_lstnew(&val3);
	ft_lstadd_front(&head, new_node3);
	print_list(head);  // 21 -> 84 -> 42 -> NULL

	// Free memory
	t_list *tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
}*/