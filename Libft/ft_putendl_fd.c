/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:50:31 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 13:04:10 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
//cc -Wall -Wextra -Werror libft.h ft_putstr_fd.c
ft_putchar_fd.c ft_putendl_fd.c
int	main(void)
{
	// char *s = NULL;
	char *s = "Hello!";
	ft_putendl_fd(s, 1);
}*/