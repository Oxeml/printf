/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:32:41 by oemelyan          #+#    #+#             */
/*   Updated: 2023/07/21 23:37:11 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int *printed)
{
	(void)fd;
	if (!s)
	{
		ft_putstr_fd("(null)", 1, printed);
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s, 1);
		s++;
		(*printed)++;
	}
}

void	ft_determination(char variable, int *printed, va_list arg_list)
{
	if (variable == 'c')
	{
		ft_putchar_fd((char)va_arg (arg_list, int), 1);
		(*printed)++;
	}
	if (variable == 's')
		ft_putstr_fd (va_arg (arg_list, char *), 1, printed);
	if (variable == 'p')
		ft_void_pointer (va_arg (arg_list, unsigned long), 1, printed);
	if (variable == 'd' || variable == 'i')
		ft_putnbr_fd(va_arg (arg_list, int), 1, printed);
	if (variable == 'u')
		ft_unsigned_decimal (va_arg (arg_list, unsigned int), 1, printed);
	if (variable == 'x')
		ft_hexa_lower (va_arg (arg_list, unsigned int), printed);
	if (variable == 'X')
		ft_hexa_upper (va_arg (arg_list, unsigned int), printed);
	if (variable == '%')
	{
		write (1, "%", 1);
		(*printed)++;
	}
}

int	ft_printf(const char *format, ...)
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
		if (format[i] == '%' && !format[i + 1])
			break ;
		if (format[i] == '%')
			ft_determination(format[++i], &printed, args);
		else
		{
			write (1, &format[i], 1);
			printed++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}

// int	main(void)
// {
// 	ft_printf("Test 1: %x\n", -9223372036854775808);
// 	printf("Test 1: %x\n", -9223372036854775808);
// 	return (0);
// }