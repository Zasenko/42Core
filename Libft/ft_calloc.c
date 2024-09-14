/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:49:59 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/13 12:25:26 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;

	if (nmemb == 0 || size == 0)
	{
		temp = malloc(0);
		if (temp == NULL)
			return (NULL);
		ft_bzero(temp, 0);
		return (temp);
	}
	else
	{
		temp = malloc(nmemb * size);
		if (temp == NULL)
			return (NULL);
		ft_bzero(temp, nmemb * size);
		return (temp);
	}
}
/*
//cc -Wall -Wextra -Werror libft.h ft_calloc.c ft_bzero.c ft_memset.c
int	main(void)
{
	int n = 5;
	int *array;
	int *array2;

	printf("--------------\n");

	array = (int *)calloc(n, sizeof(int));
	if (array == NULL)
	{
		printf("Memory allocation failed!\n");
		return (1);
	}
	printf("Array elements after calloc: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	free(array);

	array2 = (int *)ft_calloc(n, sizeof(int));
	if (array2 == NULL)
	{
		printf("Memory allocation failed!\n");
		return (1);
	}
	printf("Array elements after calloc: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array2[i]);
	}
	printf("\n");
	free(array2);

	printf("--------------\n");

	long *number;
	number = NULL;
	number = (long *)calloc(10, sizeof(long));
	if (number != NULL)
		printf("Allocated.\n");
	else
		printf("\nCan't allocate memory.\n");
	free(number);

	long *number2;
	number2 = NULL;

	number2 = (long *)ft_calloc(10, sizeof(long));
	if (number2 != NULL)
		printf("Allocated.\n");
	else
		printf("\nCan't allocate memory.\n");
	free(number2);

	printf("--------------\n");

	int *pointer = (int *)calloc(0, 0);
	if (pointer == NULL)
		printf("Null pointer \n");
	else
		printf("Address = %p\n", (void *)pointer);
	free(pointer);

	int *pointer2 = (int *)ft_calloc(0, 0);
	if (pointer2 == NULL)
		printf("Null pointer2 \n");
	else
		printf("Address = %p\n", (void *)pointer2);
	free(pointer2);
}*/