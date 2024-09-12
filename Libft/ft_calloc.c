/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:49:59 by dzasenko          #+#    #+#             */
/*   Updated: 2024/09/11 17:10:51 by dzasenko         ###   ########.fr       */
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
int	main(void)
{
	int n = 5;
	int *array;
	int *array2;

	printf("--------------\n");
	array = (int *)calloc(n, sizeof(int));
	if (array == NULL)
	{
		fprintf(stderr, "Memory allocation failed!\n");
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
		fprintf(stderr, "Memory allocation failed!\n");
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
	if (number != NULL)
		printf("Allocated 10 long integers.\n");
	else
		printf("Can't allocate memory.\n");
	number = (long *)calloc(10, sizeof(long));
	if (number != NULL)
		printf("Allocated 10 long integers.\n");
	else
		printf("\nCan't allocate memory.\n");
	free(number);

	long *number2;
	number2 = NULL;
	if (number2 != NULL)
		printf("Allocated 10 long integers.\n");
	else
		printf("Can't allocate memory.\n");
	number2 = (long *)ft_calloc(10, sizeof(long));
	if (number2 != NULL)
		printf("Allocated 10 long integers.\n");
	else
		printf("\nCan't allocate memory.\n");
	free(number2);

	printf("--------------\n");

	int *pointer = (int *)calloc(0, 0);
   if (pointer == NULL) {
		printf("Null pointer \n");
   } else {
		printf("Address = %p\n", (void*)pointer);
   }
   free(pointer);

   int *pointer2 = (int *)ft_calloc(0, 0);
   if (pointer2 == NULL) {
		printf("Null pointer2 \n");
   } else {
		printf("Address = %p\n", (void*)pointer2);
   }
   free(pointer2);
}*/