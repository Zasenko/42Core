/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:56:45 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 13:20:17 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
/*
//cc -Wall -Wextra -Werror libft.h ft_lstnew.c

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
	char *val1 = "hello";
	t_list *node1 = ft_lstnew(val1);

	if (node1 == NULL)
	{
		printf("Test failed: Node creation failed\n");
		return (1);
	}
	else
	{
		printf("Test 1 - Node creation success:\n");
		printf("Content: %s\n", (char *)node1->content); // hello
		if (node1->next == NULL)
			printf("Node next pointer: NULL (as expected)\n");
		else
			printf("Test failed: Node next is not NULL\n");
	}

	char *val2 = "Dimitri!";
	t_list *node2 = ft_lstnew(val2);
	if (node2 == NULL)
	{
		printf("Test failed: Node creation failed\n");
		return (1);
	}
	else
	{
		printf("Test 2 - Node creation success:\n");
		printf("Node content: %s\n", (char *)node2->content); // Dimitri!
		if (node2->next == NULL)
			printf("Node next pointer: NULL (as expected)\n");
		else
			printf("Test failed: Node next is not NULL\n");
	}

	// Free memory
	free(node1);
	free(node2);

	return (0);
}*/