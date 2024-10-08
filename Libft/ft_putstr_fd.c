/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:41:28 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 13:01:45 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
/*
//cc -Wall -Wextra -Werror libft.h ft_putstr_fd.c ft_putchar_fd.c
int	main(void)
{
	char *s = "hello!";
	ft_putstr_fd(s, 1);
}*/