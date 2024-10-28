#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_atoi(char *s)
{
	int num = 0;
	int sign = 1;

	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) + (*s - '0');
		s++;
	}
	return (num * sign);
}

void ft_print_hex(int num)
{
	char *hex = "0123456789abcdef";
	if (num < 16)
	{
		char c = hex[num];
		ft_putchar(c);
	}
	else
	{
		ft_print_hex(num / 16);
		char c = hex[num % 16];
		ft_putchar(c);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return 0;
	}
	int num = ft_atoi(argv[1]);
	if (num < 0)
	{
		ft_putchar('\n');
		return 0;
	}
	ft_print_hex(num);
	ft_putchar('\n');
	return 0;
}