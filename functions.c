/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:26:37 by oemelyan          #+#    #+#             */
/*   Updated: 2023/07/21 23:38:42 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putchar2_fd(char c, int fd, int	*printed)
{
	write (fd, &c, 1);
	(*printed)++;
}

void	ft_unsigned_decimal(unsigned int n, int fd, int *printed)
{	
	unsigned int	num;

	num = n;
	if (num >= 10)
		ft_unsigned_decimal(num / 10, fd, printed);
	ft_putchar_fd(num % 10 + '0', fd);
	(*printed)++;
}

void	ft_putnbr_fd(int n, int fd, int *printed)
{	
	long	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
		(*printed)++;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd, printed);
	ft_putchar_fd(num % 10 + '0', fd);
	(*printed)++;
}

void	ft_hexa_lower(unsigned int a, int *printed)
{
	const char	*heks = "0123456789abcdef";

	if (a >= 16)
		ft_hexa_lower(a / 16, printed);
	ft_putchar2_fd(heks[a % 16], 1, printed);
}
