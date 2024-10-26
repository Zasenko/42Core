#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

int sepcount(char *str)
{
	int count = 0;

	int i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			count++;
		i++;
	}
	return count;
}

int counttillsepornull(char *str)
{
	int i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		i++;
	}
	return i;
}

void freearr(char **arr)
{
	if (arr)
	{
		int i = 0;
		while(arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void printrew(char *str)
{
	int wcount = sepcount(str) + 1;

	char **arr = (char **)malloc(sizeof(char *) * (wcount + 1));
    if (!arr)
        return;
	arr[wcount] = NULL;
	int i = 0;
	char *temp = str;
	while(i < wcount)
	{
		int newcount = counttillsepornull(temp);
		char *newstr = (char *)malloc(sizeof(char) * (newcount + 1));
		if (!newstr)
		{
			freearr(arr);
            return;
		}
		int ni = 0;
		while(ni < newcount)
		{
			newstr[ni] = *temp;
			temp++;
			ni++;
		}
		newstr[ni] = '\0';
		temp++;
		arr[i] = newstr;
		i++;
	}
	i = wcount - 1;
	while (i > 0)
	{
		ft_putstr(arr[i]);
		ft_putchar(' ');
		i--;
	}
	ft_putstr(arr[i]);
	ft_putchar('\n');
	freearr(arr);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putchar('\n');
		return 0;
	}
	printrew(argv[1]);
	return 0;
}
