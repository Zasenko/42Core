/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:07:38 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/24 12:54:27 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = create_stacks(argc, argv);
	if (!stack_a)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	sort(&stack_a, &stack_b);
	free_stack(&stack_b);
	free_stack(&stack_a);
	return (0);
}
