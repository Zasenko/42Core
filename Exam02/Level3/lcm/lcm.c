unsigned int    lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return 0;
	
	unsigned int c = (a > b) ? a : b;

	while (1)
	{
		if (c % a == 0 && c % b == 0)
			return c;
		c++;
	}
}