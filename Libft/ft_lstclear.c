/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:36:37 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 13:56:14 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		buf = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buf;
	}
	free(*lst);
	*lst = NULL;
}
/*
//cc -Wall -Wextra -Werror libft.h ft_lstclear.c ft_lstnew.c ft_lstdelone.c

void	del_func(void *content)
{
	free(content);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list *node1 = ft_lstnew(strdup("First"));
	t_list *node2 = ft_lstnew(strdup("Second"));
	t_list *node3 = ft_lstnew(strdup("Third"));

	node1->next = node2;
	node2->next = node3;

	printf("List before clearing:\n");
	print_list(node1);

	ft_lstclear(&node1, del_func);

	if (node1 == NULL)
		printf("\nList cleared successfully.\n");
	else
		printf("\nList clearing failed.\n");

	return 0;
}*/