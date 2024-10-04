/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:57:16 by dzasenko          #+#    #+#             */
/*   Updated: 2024/10/04 12:11:07 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	factor;

	if (!str)
		return (-1);
	va_start(factor, str);
	len = ft_print_variadic(str, factor);
	va_end(factor);
	return (len);
}
/*
int	main(void)
{
	int		lenOrig;
	int		lenMy;
	
	int number = 54;
	int *p = NULL;
	
	printf("\n");
	
	lenOrig = printf("Hello, World!");
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("Integer: %d", 42);
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("Unsigned: %u", 15985353);
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("Hexadecimal (lower): %x", 42424242);
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("Hexadecimal (upper): %X", 42424242);
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("Character: %c", 'A');
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("String: %s", "Test string");
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("Percentage: %%");
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("Zero: %d", 0);
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("Smallest int: %d", -2147483648);
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("Empty string: %s", "");
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("NULL string: %s", NULL);
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("Multiple arguments: %d, %c, %s, %x", 42, \
	'B', "Test", 255);
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("This is a number: %d and this is a char: %c!", 123, 'Z');
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("Pointer: %p", &number);
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf("NULL Pointer: %p", p);
	printf(" | size: %d\n", lenOrig);
	lenOrig = printf(NULL);
	printf(" | size: %d\n", lenOrig);
	
	printf("\n------------------\n\n");

	lenMy = ft_printf("Hello, World!");
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("Integer: %d", 42);
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("Unsigned: %u", 15985353);
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("Hexadecimal (lower): %x", 42424242);
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("Hexadecimal (upper): %X", 42424242);
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("Character: %c", 'A');
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("String: %s", "Test string");
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("Percentage: %%");
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("Zero: %d", 0);
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("Smallest int: %d", -2147483648);
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("Empty string: %s", "");
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("NULL string: %s", NULL);
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("Multiple arguments: %d, %c, %s, %x", 42, \
	'B', "Test", 255);
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("This is a number: %d and this is a char: %c!", 123, 'A');
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("Pointer: %p", &number);
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf("NULL Pointer: %p", p);
	printf(" | size: %d\n", lenMy);
	lenMy = ft_printf(NULL);
	printf(" | size: %d\n", lenMy);
	
	printf("\n---------ALL FLAGS---------\n\n");
	
	char	arr[] = "%c | %% | %u | %x | %X | %s | %i | %d";

	lenOrig = printf(arr, 'A', 252525, 252525, 252525, "Dimitry", -100, -100);
	printf(" | size: %d\n", lenOrig);
	
	lenMy = ft_printf(arr, 'A', 252525, 252525, 252525, "Dimitry", -100, -100);
	printf(" | size: %d\n", lenMy);
	
	return (0);
}*/
