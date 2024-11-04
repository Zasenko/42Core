#include <stdlib.h>
#include <stdio.h>

void fprime(unsigned int n)
{
	if (n == 1)
		printf("1");
	else
	{
		unsigned int prime = 2;
		while (n > 1)
		{
			if (n % prime == 0)
			{
				printf("%d", prime);
				n /= prime;
				if (n > 1)
					printf("*");
				prime--;
			}
			prime++;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 2 && *argv[1])
	{
		int n = atoi(argv[1]);
		if (n > 0)
			fprime((unsigned int)n);
	}
	printf("\n");
	return 0;
} 