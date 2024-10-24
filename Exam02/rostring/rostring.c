#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

int words_count(char *s)
{

	int i = 0;
	int flag = 1;
	int c = 0;

	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			flag = 1;
		}
		else
		{
			if (flag == 1)
			{
				c++;
			}
			flag = 0;
		}
		i++;
	}
	return c;
}

int count_till_sep(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			return i;
		}
		i++;
	}
	return i;
}

void free_arr(char **arr)
{
	if (arr)
	{
		int i = 0;
		while (arr[i])
		{
			if (arr[i])
			{
				free(arr[i]);
				arr[i] = NULL;
			}
			i++;
		}
		free(arr);
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("\n");
		return 0;
	}
	int wc = words_count(argv[1]);
	if (wc < 0)
	{
		ft_putstr("\n");
		return 0;
	}
	char **arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
	{
		ft_putstr("\n");
		return 0;
	}
	int i = 0;
	while (i <= wc)
	{
		arr[i] = NULL;
		i++;
	}
	char *str = argv[1];
    i = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
		{
			str++;
		}
		else
		{
			int c = count_till_sep(str);
			if (c > 0)
			{
				char *new_w = (char *)malloc(sizeof(char) * (c + 1));
				if (!new_w)
				{
					free_arr(arr);
					return 0;
				}
				int j = 0;
				while (j < c)
				{
					new_w[j] = *str;
					str++;
					j++;
				}
				new_w[j] = '\0';
                arr[i] = new_w;
                i++;
			}
			else {
				str++;
			}
		}
	}

	if (wc > 1)
	{
		int a = 1;
		while (arr[a])
		{
			ft_putstr(arr[a]);
			ft_putchar(' ');
			a++;
		}
		ft_putstr(arr[0]);
	}
	else
	{
		ft_putstr(arr[0]);
	}
	ft_putchar('\n');
	free_arr(arr);
}
