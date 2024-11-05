int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

int index_in_base(char c, int base)
{
	char *str1 = "0123456789ABCDEF";
	char *str2 = "0123456789abcdef";

	int i = 0;
	while (str1[i])
	{
		if (str1[i] == c || str2[i] == c)
			return i;
		i++;
	}
	return -1;
}

int	ft_atoi_base(const char *str, int str_base)
{
	if (str_base < 2 || str_base > 16 || !str || ft_strlen(str) < 1)
		return 0;

	int sign = 1;
	int num = 0;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	int index = index_in_base(str[i], str_base);
	while (str[i] && index >= 0)
	{
		num = num * str_base + index;
		i++;
		index = index_in_base(str[i], str_base);
	}
	return (num * sign);
}