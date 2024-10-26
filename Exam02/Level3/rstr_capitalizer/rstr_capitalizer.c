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

void test(char *s)
{

	int count = ft_strcount(s);

	int i = count - 1;
	int f = 1;
	while(i >= 0)
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			f = 1;
		} else {
			if (f == 1)
			{
				if (s[i] >= 'a' && s[i] <= 'z')
						s[i] = s[i]- 32;
			}
			else {
				if (s[i] >= 'A' && s[i] <= 'Z')
					s[i] = s[i] + 32;
			}
			f = 0;
		}
		i--;
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putchar('\n');
		return 0;
	}

	int i = 1;
	while (i < argc)
	{
		test(argv[i]);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return 0;
}