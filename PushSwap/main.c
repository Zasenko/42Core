#include "libft.h"
#include "push_swap.h"

int	*check_arg(const char *ar)
{
	int	*num;
	int	i;
	int	len;

	if (!ar)
		return (NULL);
	len = ft_strlen(ar);
	if (len < 1)
		return (NULL);
    i = 0;
	while (ar[i])
	{
		if (ft_isdigit(ar[i]) == 1 || 
        (i == 0 && (ar[i] == '-' || ar[i] == '+') && len > 1))
			i++;
		else
			return (NULL);
	}
	num = (int *)malloc(sizeof(int));
	if (!num)
		return (NULL);
	*num = ft_atoi(ar);
	return (num);
}

int	main(int argv, char **argc)
{
    t_list *stack1;
    t_list *stack2;

	if (argv < 2)
    {
        printf("ERROR\n");
        return (-1);
    }
	// malloc 2 arrays.

	int i = 1;
	while (i < argv)
	{
		int *num = check_arg(argc[i]);
		if (num)
		{
            if (!stack1)
            {
                stack1 = ft_lstnew(num);
            }
            else
            {
                t_list *l_new = t_lstnew(num);
                ft_lstadd_back(&stack1, l_new);
            }
		}
		else
		{
			printf("ERROR\n");
            ft_ls
		}
		i++;
	}
	return (0);
}