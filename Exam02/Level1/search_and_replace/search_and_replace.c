#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int ft_strcount(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putchar('\n');
		return 0;
	}

	char *str = argv[1];
	char *c1 = argv[2];
	char *c2 = argv[3];

	if (ft_strcount(c1) != 1 && ft_strcount(c2) != 1)
	{
		ft_putchar('\n');
		return 0;
	}

	int f = 0;
	int i = 0;
	while (str[i])
	{
		if (str[i] == c1[0])
		{
			f = 1;
			break;
		}
		i++;
	}
	if (f == 0)
	{
		ft_putstr(str);
		ft_putchar('\n');
		return 0;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == c1[0])
		{
			str[i] = c2[0];
		}
		i++;
	}
	ft_putstr(str);
	ft_putchar('\n');
}