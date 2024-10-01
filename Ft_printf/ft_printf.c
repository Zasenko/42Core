/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:57:16 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/30 13:36:54 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_base_num(size_t num, char *base, size_t base_len,
		int *len)
{
	if (num < base_len)
	{
		write(1, &(base[num]), 1);
		*len += 1;
	}
	else
	{
		print_base_num(num / base_len, base, base_len, len);
		write(1, &(base[num % base_len]), 1);
		*len += 1;
	}
}

void	print_x(int num, char *base, int *len)
{
	print_base_num((unsigned int)num, base, 16, len);
}

void	print_u(unsigned int num, int *len)
{
	print_base_num(num, "0123456789", 10, len);
}

void	print_p(void *p, int *len)
{
	write(1, "0x", 2);
	*len += 2;
	print_base_num((uintptr_t)p, "0123456789abcdef", 16, len);
}

int	ft_printf(const char *str, ...)
{
	int				len;
	va_list			factor;
	int				res_ch;
	char			*res_str;
	void			*res_p;
	int				result;
	unsigned int	result_u;

	len = 0;
	if (!str)
		return (len);
	va_start(factor, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				res_ch = va_arg(factor, int);
				ft_putchar_fd(res_ch, 1, &len);
			}
			else if (*str == 's')
			{
				res_str = va_arg(factor, char *);
				if (res_str == NULL)
					ft_putstr_fd("(null)", 1, &len);
				else
				{
					ft_putstr_fd(res_str, 1, &len);
				}
			}
			else if (*str == 'p')
			{
				res_p = va_arg(factor, void *);
				if (res_p == NULL)
					ft_putstr_fd("(nil)", 1, &len);
				else
				{
					print_p(res_p, &len);
				}
			}
			else if (*str == 'd' || *str == 'i')
			{
				result = va_arg(factor, int);
				ft_putnbr_fd(result, 1, &len);
			}
			else if (*str == 'u')
			{
				result_u = va_arg(factor, int);
				print_u(result_u, &len);
			}
			else if (*str == 'x')
			{
				result = va_arg(factor, int);
				print_x(result, "0123456789abcdef", &len); // len++;
			}
			else if (*str == 'X')
			{
				result = va_arg(factor, int);
				print_x(result, "0123456789ABCDEF", &len); // len++;
			}
			else if (*str == '%')
			{
				ft_putchar_fd('%', 1, &len);
			}
			else
			{
				ft_putstr_fd("-1", 1, &len);
				return (len);
			}
		}
		else
		{
			ft_putchar_fd(*str, 1, &len);
		}
		str++;
	}
	va_end(factor);
	return (len);
}

// int	main(void)
// {
// 	int		i0;
// 	int		i1;
// 	//char	arr[] = "%c\n%%\n%u\n%x\n%X\n%s\n%i\n%d\n--------------\n";

// 	int i = 145;
// 	char	arr[] = "%";
// 	// char	arr[] = "% d";
// 	// 	i1 = printf("%");
// 	// 	printf("OR size: %d\n--------------\n", i1);
// 	// i1 = printf("% ");
// 	// 	printf("OR size: %d\n--------------\n", i1);
// 	// 	i1 = printf("% d");
// 	//	printf("OR size: %d\n--------------\n", i1);
// 	//	i1 = printf("%a");
// 	//	printf("OR size: %d\n--------------\n", i1);

// 	//i1 = printf(arr, 'D', 3147483648, 555, -555, "Hello", -555, 1);
// 	i1 = printf(arr, &i);
// 	printf("OR size: %d\n--------------\n\n", i1);

// 	//i0 = ft_printf(arr, 'D', 3147483648, 555, -555, "Hello", -555, 1);
// 	i0 = ft_printf(arr, &i);
// 	printf("MY size: %d\n--------------\n", i0);
// 	return (0);
// }

void	ft_putchar_fd(char c, int fd, int *len)
{
	write(fd, &c, 1);
	*len += 1;
}

void	ft_putnbr_fd(int n, int fd, int *len)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd, len);
		num = -num;
	}
	if (num < 10)
	{
		ft_putchar_fd(num + '0', fd, len);
	}
	else
	{
		ft_putnbr_fd(num / 10, fd, len);
		ft_putchar_fd((num % 10) + '0', fd, len);
	}
}

void	ft_putstr_fd(char *s, int fd, int *len)
{
	if (!s || !len)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd, len);
		s++;
	}
}