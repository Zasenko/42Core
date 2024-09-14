/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:43:28 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 13:21:10 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
//cc -Wall -Wextra -Werror libft.h ft_lstnew.c ft_lstlast.c

void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	// Test for ft_lstnew with strings
	t_list *node1 = ft_lstnew("first");
	t_list *node2 = ft_lstnew("second");
	t_list *node3 = ft_lstnew("third");
	t_list *node4 = ft_lstnew("fourth");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	printf("List contents:\n");
	print_list(node1);  // first -> second -> third -> fourth -> NULL
	t_list *last_node = ft_lstlast(node1);
	if (last_node)
		printf("Last node content: %s\n", (char *)last_node->content); 
			// fourth
	else
		printf("Test failed: No last node found\n");

	// Free memory
	free(node1);
	free(node2);
	free(node3);
	free(node4);

	return (0);
}*/