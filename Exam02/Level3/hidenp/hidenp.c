#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int check(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return 0;
		i++;
	}
	if (s2[i] == '\0')
		return 1;
	else
		return 0;
}


int main (int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putchar('\n');
		return 0;
	}

	char *s1 = argv[1];
	char *s2 = argv[2];

	while (*s2)
	{
		if (*s1 == *s2)
		{
				s1++;
		}
		s2++;
	}
	if (*s1 == '\0')
	{
	ft_putchar('1');
	ft_putchar('\n');
	}
	else {
	ft_putchar('0');
	ft_putchar('\n');
	}

	return 0;
}
