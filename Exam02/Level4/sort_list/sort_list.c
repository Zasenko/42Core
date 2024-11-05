#include "list.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *temp = lst;

	while (lst && lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			int t = lst->data;
			lst->data = lst->next->data;
			lst->next->data = t;
			lst = temp;
		}
		else
		{
			lst = lst->next;
		}
	}
	return temp;
}

