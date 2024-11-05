#include <stdlib.h>

int ft_count(int start, int end)
{
	int count = 0;
	while (start <= end)
	{
		start++;
		count++;
	}
	return count;
}

int     *ft_rrange(int start, int end)
{
	if (start > end)
		return NULL;
	int count = ft_count(start, end);
	int *arr = (int *)malloc(sizeof(int) * count);
	if (!arr)
		return NULL;
	int i = count - 1; 
	while (i >= 0)
	{
		arr[i] = start++;
		i--;
	}
	return arr;
}