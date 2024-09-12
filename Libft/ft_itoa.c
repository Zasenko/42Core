/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:58:52 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/11 15:22:45 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_int_len(long num, int *len)
{
	if (num < 10)
		*len += 1;
	else
	{
		*len += 1;
		ft_int_len(num / 10, len);
	}
}

static void	ft_int_to_str(long num, char *str, int len)
{
	if (len > 0)
	{
		if (num < 10)
			str[len - 1] = num + '0';
		else
		{
			str[len - 1] = num % 10 + '0';
			ft_int_to_str(num / 10, str, len - 1);
		}
	}
}

static void	ft_set_str(char *str, int n_len, int sign, long num)
{
	if (sign == 1)
	{
		str[0] = '-';
		ft_int_to_str(num, &str[1], n_len - 1);
	}
	else
		ft_int_to_str(num, str, n_len);
}

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
	ft_int_len(num, &n_len);
	str = (char *)malloc((n_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[n_len] = '\0';
	ft_set_str(str, n_len, sign, num);
	return (str);
}
/*
int	main(void)
{
	int num1 = 12345;
	char *str1 = ft_itoa(num1);
	printf("Test 1: %s (Expected: 12345)\n", str1);
	free(str1);
	printf("----------------\n");
	// Test 2: Negative number
	int num2 = -54321;
	char *str2 = ft_itoa(num2);
	printf("Test 2: %s (Expected: -54321)\n", str2);
	free(str2);
	printf("----------------\n");

	// Test 3: Zero
	int num3 = 0;
	char *str3 = ft_itoa(num3);
	printf("Test 3: %s (Expected: 0)\n", str3);
	free(str3);
	printf("----------------\n");

	// Test 4: Smallest negative number (-9999)
	int num4 = -9999;
	char *str4 = ft_itoa(num4);
	printf("Test 4: %s (Expected: -9999)\n", str4);
	free(str4);
	printf("----------------\n");

	// Test 5: Largest positive number within reasonable bounds (99999)
	int num5 = 99999;
	char *str5 = ft_itoa(num5);
	printf("Test 5: %s (Expected: 99999)\n", str5);
	free(str5);
	printf("----------------\n");

	// Test 6: Single digit positive number
	int num6 = 7;
	char *str6 = ft_itoa(num6);
	printf("Test 6: %s (Expected: 7)\n", str6);
	free(str6);
	printf("----------------\n");

	// Test 7: Single digit negative number
	int num7 = -8;
	char *str7 = ft_itoa(num7);
	printf("Test 7: %s (Expected: -8)\n", str7);
	free(str7);
	printf("----------------\n");

	// Test 8: Negative number with zeroes (-1000)
	int num8 = -1000;
	char *str8 = ft_itoa(num8);
	printf("Test 8: %s (Expected: -1000)\n", str8);
	free(str8);
	printf("----------------\n");

	// Test 9: Large negative number (-123456789)
	int num9 = -123456789;
	char *str9 = ft_itoa(num9);
	printf("Test 9: %s (Expected: -123456789)\n", str9);
	free(str9);
	printf("----------------\n");

	int num10 = -2147483648;
	char *str10 = ft_itoa(num10);
	printf("Test 10: %s (Expected: -2147483648)\n", str10);
	free(str10);
	printf("----------------\n");

	int num11 = 2147483647;
	char *str11 = ft_itoa(num11);
	printf("Test 10: %s (Expected: 2147483647)\n", str11);
	free(str11);
}*/