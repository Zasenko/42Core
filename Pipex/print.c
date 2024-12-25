/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:30:23 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/24 13:00:07 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	print_err_exit(t_prog *prog, char *error)
{
	free_prog(prog);
	if (error)
		ft_putstr(error);
	exit(EXIT_FAILURE);
}

void	print_perr_exit(t_prog *prog, char *error)
{
	free_prog(prog);
	if (error)
		perror(error);
	exit(EXIT_FAILURE);
}
