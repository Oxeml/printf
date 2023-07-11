/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_trial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:32:41 by oemelyan          #+#    #+#             */
/*   Updated: 2023/07/11 19:32:49 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

//to check limits for unsigned int and unsigned long here

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

void ft_hexa_lower (size_t a, int *printed)
{
		const char *heks = "0123456789abcdef";
		if (a >= 16)
			ft_hexa_lower (a/16, printed);
		ft_putchar2_fd(heks[a % 16], 1, printed);
}

void ft_hexa_upper (size_t a, int *printed)
{
		const char *heks = "0123456789ABCDEF";
		if (a >= 16)
			ft_hexa_lower (a/16, printed);
		ft_putchar2_fd(heks[a % 16], 1, printed);
}

void	ft_void_pointer (void *ptr, int fd, int *printed)
{
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	(*printed) += 2;
	ft_hexa_lower ((size_t)ptr, printed);
}

static void ft_determination (char variable, int *printed, va_list arg_list)
{
	// if (variable == 'c')
	// 	ft_single_char((char)va_arg (arg_list, int) printed);
	// if (variable == 's')
	// 	ft_string (va_arg (arg_list, char *), printed);
	if (variable == 'p')
		ft_void_pointer (va_arg (arg_list, void *), 1, printed);
	if (variable == 'd' || variable == 'i')
		ft_putnbr_fd(va_arg (arg_list, int), 1, printed);
	if (variable == 'u')
		ft_unsigned_decimal (va_arg (arg_list, unsigned int), 1, printed);
	// if (variable == 'x')
	// 	ft_hexa_lower (va_arg (arg_list, void *), printed);
	// if (variable == 'X')
	// 	ft_hexa_upper (va_arg (arg_list, void *), printed);
	if (variable == '%')
	{
		write (1, "%", 1);
		(*printed)++;
	}
}

int ft_printf (const char *format, ...)
{
	int		printed;
	int		i;
	va_list	args;

	va_start (args, format);
	printed = 0;
	i = 0;
	if (!format)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_determination(format[i], &printed, args);
			i++;		
		}
		else
		{
			write (1, &format[i], 1);
			i++;
			printed++;	
		}
	}
	return (printed);
	va_end (args);
}

int main ()
{
	int	a;
	int	b = 0;
	int	*c;

	c = &a;
	a = ft_printf("I have %d friends, and %p enemies\n", 1000, c);
	// '\n' is counted
	b = printf("I have %d friends, and %p enemies\n", 1000, c);
	if ( a == b)
		printf("\nFt_printf works as expected\na = %d\nb = %d\n", a, b);
	else
		printf("\nFix an error\na = %d\nb = %d\n", a, b);
	return (0);
}
