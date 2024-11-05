#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return 0;
	}

	char *s = argv[1];
	while (*s)
	{
		if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
		{
			if (*s == 'z')
				ft_putchar('a');
			else if (*s == 'Z')
				ft_putchar('A');
			else
				ft_putchar(*s + 1);
		}
		else
			ft_putchar(*s);
		s++;
	}
	ft_putchar('\n');
	return 0;
}