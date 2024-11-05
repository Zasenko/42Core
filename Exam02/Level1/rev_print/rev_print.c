
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}


void ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return 0;
	}
	int len = ft_strlen(argv[1]);
	while ((len - 1) >= 0)
	{
		ft_putchar(argv[1][len - 1]);
		len--;
	}
	ft_putchar('\n');
}