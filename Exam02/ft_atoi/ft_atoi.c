#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int num = 0;
	int s = 1;

	int l = 0;

	if (!str)
		return num;
	while(str[l] == ' ' || str[l] == '\t')
		l++;
	if (str[l] == '-')
	{
		s = -1;
		l++;
	}
	if (str[l] == '+')
	{
		l++;
	}
	while(str[l] && (str[l] >= '0' && str[l] <= '9'))
	{
		num = num * 10 + (str[l] - '0');
		l++;
	}
	if (s == -1)
	{
		num = -num;

	}
	return num;
}

// int main(void)
// {
// 	int	i = ft_atoi("-11");
// 	printf("%d\n", i);

// 	int	l = atoi("-11");
// 	printf("%d\n", l);

// 	i = ft_atoi("0");
// 	printf("%d\n", i);

// 	l = atoi("0");
// 	printf("%d\n", l);

// 	i = ft_atoi("+24");
// 	printf("%d\n", i);

// 	l = atoi("-24");
// 	printf("%d\n", l);

// 	i = ft_atoi(".  666");
// 	printf("%d\n", i);

// 	l = atoi(".  666");
// 	printf("%d\n", l);

// 	i = ft_atoi(" -424242");
// 	printf("%d\n", i);

// 	l = atoi(" -424242");
// 	printf("%d\n", l);

// 	i = ft_atoi(" +424242");
// 	printf("%d\n", i);

// 	l = atoi(" +424242");
// 	printf("%d\n", l);


// 	i = ft_atoi("2222222222222");
// 	printf("%d\n", i);

// 	l = atoi("2222222222222");
// 	printf("%d\n", l);
// 	return 0;
// }