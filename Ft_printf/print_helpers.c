/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:38:11 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/02 13:45:32 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putnbr(int n, int *len)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar('-', len);
		num = -num;
	}
	if (num < 10)
		ft_putchar(num + '0', len);
	else
	{
		ft_putnbr(num / 10, len);
		ft_putchar((num % 10) + '0', len);
	}
}

void	ft_putstr(char *s, int *len)
{
	if (!s || !len)
		return ;
	while (*s)
	{
		ft_putchar(*s, len);
		s++;
	}
}

void	ft_put_base_num(size_t num, char *base, size_t base_len, int *len)
{
	if (num < base_len)
		ft_putchar(base[num], len);
	else
	{
		ft_put_base_num(num / base_len, base, base_len, len);
		ft_putchar(base[num % base_len], len);
	}
}

void	ft_print_poiner(va_list factor, int *len)
{
	void	*result;

	result = va_arg(factor, void *);
	if (result == NULL)
		ft_putstr("(nil)", len);
	else
	{
		write(1, "0x", 2);
		*len += 2;
		ft_put_base_num((uintptr_t)result, "0123456789abcdef", 16, len);
	}
}
