/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:11:05 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 13:24:33 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
t_list	*ft_lstnew(void *content);
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}
/*
//cc -Wall -Wextra -Werror libft.h ft_lstnew.c ft_lstdelone.c

void	del(void *content)
{
	free(content);
}

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
	char *content1 = strdup("first");
	char *content2 = strdup("second");
	char *content3 = strdup("third");

	t_list *node1 = ft_lstnew(content1);
	t_list *node2 = ft_lstnew(content2);
	t_list *node3 = ft_lstnew(content3);

	node1->next = node2;
	node2->next = node3;

	printf("List contents before deletion:\n");
	print_list(node1);  // Expected: first -> second -> third -> NULL

	ft_lstdelone(node2, del);
	node1->next = node3;

	printf("List contents after deleting the second node:\n");
	print_list(node1);  // Expected: first -> third -> NULL

	// Clean up remaining nodes
	ft_lstdelone(node1, del);  // Delete node1
	ft_lstdelone(node3, del);  // Delete node3

	return (0);
}*/