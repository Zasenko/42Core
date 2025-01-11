
//s,d and x.
//malloc, free, write, va_start, va_arg, va_copy, va_end

#include <stdarg.h>
//#include <stdio.h>
#include <unistd.h>

void ft_put_char(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void ft_put_str(char *str, int *len)
{
	int i = 0;
	while(str[i])
	{
		ft_put_char(str[i], len);
		i++;
	}
}

void ft_put_number(int i, int *len)
{
	if (i == -2147483648)
	{
			ft_put_str("-2147483648", len);
			return;
	}
	int num;
	num = i;
	if (i < 0)
	{
		ft_put_char('-', len);
		num *= -1;
	}
	if (num < 10)
	{
		ft_put_char(num + '0', len);
	}
	else
	{
		ft_put_number(num / 10, len);
		ft_put_char((num % 10) + '0', len);
	}
}

void ft_put_x_number(unsigned int num, int *len)
{
	char *s = "0123456789abcdef";
	if (num < 16)
	{
		ft_put_char(s[num], len);
	}
	else
	{
		ft_put_x_number(num / 16, len);
		ft_put_char(s[num % 16], len);
	}
}

int ft_printf(const char *str, ...)
{
	int len = 0;
	va_list ap;

	va_start(ap, str);

	while(*str)
	{
		if (*str != '%')
		{
			ft_put_char(*str, &len);
			str++;
		}
		else
		{
			str++;

			if (*str == 's')
			{
				char *s = va_arg(ap, char *);
				if (!s)
				{
					ft_put_str("(null)", &len);
				}
				else {
					while (*s)
					{
						ft_put_char(*s, &len);
						s++;
					}
				}
			}
			else if (*str == 'd')
			{
				int i = va_arg(ap, int);
				ft_put_number(i , &len);

			}
			else if (*str == 'x')
			{
				unsigned int x = va_arg(ap, unsigned int);
				ft_put_x_number(x, &len);

			}
			else
				return -1;
			str++;
		}
	}


	va_end(ap);
	return len;
}

// int main(void)
// {
// 	char *s = NULL;
// 	//printf("hello %s world %d", s, 125);

// 	int i = ft_printf("hello %s world\n%d\n%x\n", s, -125, 15);
// 	ft_printf("%d\n", i);
// }