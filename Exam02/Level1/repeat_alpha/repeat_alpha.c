#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int get_i(char c)
{
	char *a = "abcdefghijklmnopqrstuvwxyz";
	char *a2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;
	while(a[i])
	{
		if (a[i] == c || a2[i] == c)
		{
			return i;
		}
		i++;
	}
	i = 0;
	return -1;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return 0;
	}
	
	char *str = argv[1];	
	while (*str)
	{
		int i = get_i(*str);
		if (i == -1)
		{
			ft_putchar(*str);
		}
		else
		{
			while (i-- >= 0)
			{
				ft_putchar(*str);
			}
		}
		str++;
	}
	ft_putchar('\n');
	return 0;
}