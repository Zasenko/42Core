
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("\n");
		return 0;
	}

	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);

	if (n1 < 1 || n2 < 1)
		{
		printf("\n");
		return 0;
	}

	int i = 0;

	if (n1 > n2)
	{
		for ( t = 1; t < n2, t++)
		{
			if (n1 % t == 0 && n2 % t == 0)
				i = t;
		}

	}
	else if (n2 >= n1)
	{
		for ( t = 1; t < n1, t++)
		{
			if (n1 % t == 0 && n2 % t == 0)
				i = t;
		}
	}
	return i;
}