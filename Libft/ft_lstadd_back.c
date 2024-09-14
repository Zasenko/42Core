/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:52:56 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 13:48:30 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new)
	{
		last = ft_lstlast(*lst);
		if (last)
			last->next = new;
		else
		{
			*lst = new;
		}
	}
}
/*
//cc -Wall -Wextra -Werror libft.h ft_lstnew.c ft_lstadd_back.c ft_lstlast.c 

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
	t_list *node1 = ft_lstnew("first");
	t_list *node2 = ft_lstnew("second");

	node1->next = node2;

	printf("List contents before ft_lstadd_back:\n");
	print_list(node1);  // Expected: first -> second -> NULL

	t_list *node3 = ft_lstnew("third");
	ft_lstadd_back(&node1, node3);

	printf("List contents after ft_lstadd_back:\n");
	print_list(node1);  // Expected: first -> second -> third -> NULL

	t_list *node4 = ft_lstnew("fourth");
	ft_lstadd_back(&node1, node4);

	printf("List contents after adding fourth node:\n");
	print_list(node1);  // Expected: first -> second -> third -> fourth -> NULL

	// Free
	free(node1);
	free(node2);
	free(node3);
	free(node4);

	return (0);
}*/