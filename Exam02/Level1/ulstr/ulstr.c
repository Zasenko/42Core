#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *str = av[1];
		while(*str)
		{
			if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
			else if (*str >= 'A' && *str <= 'Z')
				*str = *str + 32;
			write(1, str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return 0;
}