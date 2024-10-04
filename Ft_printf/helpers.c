/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:34:38 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/03 11:23:37 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num_flag(const char *str, va_list factor, int *len)
{
	int				result;
	unsigned int	result_u;

	if (*str == 'd' || *str == 'i')
	{
		result = va_arg(factor, int);
		ft_putnbr(result, len);
	}
	else if (*str == 'u')
	{
		result_u = va_arg(factor, int);
		ft_put_base_num(result_u, "0123456789", 10, len);
	}
	else if (*str == 'x')
	{
		result_u = va_arg(factor, int);
		ft_put_base_num(result_u, "0123456789abcdef", 16, len);
	}
	else if (*str == 'X')
	{
		result_u = va_arg(factor, int);
		ft_put_base_num(result_u, "0123456789ABCDEF", 16, len);
	}
}

void	ft_print_text_flag(const char *str, va_list factor, int *len)
{
	char	*res_str;
	int		res_ch;

	if (*str == 'c')
	{
		res_ch = va_arg(factor, int);
		ft_putchar(res_ch, len);
	}
	else if (*str == 's')
	{
		res_str = va_arg(factor, char *);
		if (res_str == NULL)
			ft_putstr("(null)", len);
		else
			ft_putstr(res_str, len);
	}
	else if (*str == '%')
		ft_putchar('%', len);
}

void	ft_print_flag(const char *s, va_list factor, int *len)
{
	if (*s == 'c' || *s == 's' || *s == '%')
		ft_print_text_flag(s, factor, len);
	else if (*s == 'p')
		ft_print_poiner(factor, len);
	else if (*s == 'd' || *s == 'i' || *s == 'u' || *s == 'x' || *s == 'X')
		ft_print_num_flag(s, factor, len);
}

int	ft_chech_flag(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'c'
		|| c == 's' || c == 'p' || c == '%')
		return (1);
	else
		return (0);
}

int	ft_print_variadic(const char *str, va_list factor)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_chech_flag(*str) == 1)
				ft_print_flag(str, factor, &len);
			else
				return (-1);
		}
		else
			ft_putchar(*str, &len);
		str++;
	}
	return (len);
}
