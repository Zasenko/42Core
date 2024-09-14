/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:51:21 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 11:27:44 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
// cc -Wall -Wextra -Werror libft.h ft_lstiter.c ft_lstnew.c
void	print_func(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list *node1 = ft_lstnew("Hello");
	t_list *node2 = ft_lstnew("World");
	t_list *node3 = ft_lstnew("!");
	
	node1->next = node2;
	node2->next = node3;
	
	ft_lstiter(node1, print_func);
	
	free(node1);
	free(node2);
	free(node3);
	
	return (0);
}*/