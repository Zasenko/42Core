/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:09:48 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 13:18:17 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
//cc -Wall -Wextra -Werror libft.h ft_lstsize.c ft_lstnew.c
void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

t_list	*ft_lstnew(void *content);

int	main(void)
{
	char *val1 = "hello";
	t_list *node1 = ft_lstnew(val1);

	char *val2 = "Dimitri!";
	t_list *node2 = ft_lstnew(val2);

	char *val3 = "42";
	t_list *node3 = ft_lstnew(val3);

	node3->next = node2;
	node2->next = node1;

	printf("List contents:\n");
	print_list(node3); // 42 -> Dimitri! -> hello -> NULL

	int size = ft_lstsize(node3);
	printf("List size: %d\n", size); // 3

	// Free memory
	free(node1);
	free(node2);
	free(node3);

	return (0);
}*/