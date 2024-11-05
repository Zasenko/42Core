
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("\n");
		return 0;
	}

	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[3]);

	if (argv[2][0] == '+')
	{
		printf("%d\n", num1 + num2);
	}
	else if (argv[2][0] == '-')
	{
		printf("%d\n", num1 - num2);
	}
	else if (argv[2][0] == '*')
	{
		printf("%d\n", num1 * num2);
	}
	else if (argv[2][0] == '/')
	{
		printf("%d\n", num1 / num2);
	}
	else if (argv[2][0] == '%')
	{
		printf("%d\n", num1 % num2);

	}
	else
	{
		printf("\n");
	}

}