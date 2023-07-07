#include <stdio.c>
#include <stdarg.h>

static int	string_size(int n)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	if (n < 0)
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void ft_integer (int n, *printed)
{
	char	*str;
	int		size;
	size_t	number;

	size = string_size(n);
	number = n;
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (number == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	size--;
	while (number != 0)
	{
		*(str + size--) = number % 10 + '0';
		number /= 10;
	}
	return (str);
}