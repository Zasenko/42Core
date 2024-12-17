/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:04:37 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 13:32:11 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_str(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		put_char(s[i++]);
}

void	print_error(char *text)
{
	put_str("Error\n");
	if (text)
	{
		put_str(text);
		put_char('\n');
	}
}

void	print_moves(int num)
{
	char	*num_str;

	num_str = ft_itoa(num);
	if (!num_str)
		return ;
	put_str("Moves: ");
	put_str(num_str);
	put_str("\n");
	free(num_str);
}
