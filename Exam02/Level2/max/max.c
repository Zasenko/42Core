int		max(int* tab, unsigned int len)
{
	int i = 0;
	if (!tab || len < 1)
		return i;
	int max = tab[i];
	while(i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return max;
}