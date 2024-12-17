/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:58:52 by dzasenko          #+#    #+#             */
/*   Updated: 2024/12/12 13:32:31 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_int_len(long num, int *len);
static int	ft_int_to_str(long num, char *str, int len);
static int	ft_set_str(char *str, int n_len, int sign, long num);

char	*ft_itoa(int n)
{
	long	num;
	int		sign;
	int		n_len;
	char	*str;

	sign = 0;
	n_len = 0;
	num = (long)n;
	if (n < 0)
	{
		sign = 1;
		n_len = 1;
		num = -num;
	}
	if (!ft_int_len(num, &n_len))
		return (NULL);
	str = (char *)malloc((n_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[n_len] = '\0';
	if (!ft_set_str(str, n_len, sign, num))
		return (free_str(&str), NULL);
	return (str);
}

static int	ft_int_len(long num, int *len)
{
	if (!len)
		return (0);
	if (num < 10)
		*len += 1;
	else
	{
		*len += 1;
		if (!ft_int_len(num / 10, len))
			return (0);
	}
	return (1);
}

static int	ft_int_to_str(long num, char *str, int len)
{
	if (!str)
		return (0);
	if (len > 0)
	{
		if (num < 10)
			str[len - 1] = num + '0';
		else
		{
			str[len - 1] = num % 10 + '0';
			if (!ft_int_to_str(num / 10, str, len - 1))
				return (0);
		}
	}
	return (1);
}

static int	ft_set_str(char *str, int n_len, int sign, long num)
{
	if (!str)
		return (0);
	if (sign == 1)
	{
		str[0] = '-';
		if (!ft_int_to_str(num, &str[1], n_len - 1))
			return (0);
	}
	else
	{
		if (!ft_int_to_str(num, str, n_len))
			return (0);
	}
	return (1);
}
