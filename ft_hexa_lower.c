#include <stdio.h>
void ft_putchar (char a, *printed)
{
	write (1, &a, 1);
	*printed++;
}

void ft_hexa_lower (unsigned int a, int *printed)
{
		const char *heks = "0123456789abcdef";
		if (n >= 16)
			ft_hexa_lower (n/16, printed);
		ft_putchar(heks[a % 16], printed);
}

void ft_hexa_upper (unsigned int a, int *printed)
{
		const char *heks = "0123456789ABCDEF";
		if (n >= 16)
			ft_hexa_lower (n/16, printed);
		ft_putchar(heks[a % 16], printed);
}
