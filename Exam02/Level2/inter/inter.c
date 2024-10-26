#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int check(char *s, int n)
{
	int i = 0;
	while (i < n)
	{
		if (s[i] == s[n])
			return (0);
		i++;
	}
	return (1);
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

	int i = 0;

	while (s1[i])
	{
		if (check(s1, i))
		{
			int j = 0;
			while (s2[j])
			{
				if (s1[i] == s2[j])
				{
					ft_putchar(s1[i]);
					break;
				}
				j++;
			}
		}
		i++;
	}
	ft_putchar('\n');
	return 0;
}
