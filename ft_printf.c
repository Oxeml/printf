/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:08:52 by oemelyan          #+#    #+#             */
/*   Updated: 2023/07/05 18:37:11 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

static void ft_determination (char variable, int *printed, va_list arg_list)
{
	if (variable == 'c')
		ft_single_char(va_arg (arg_list, char) &printed);
	if (variable == 's')
		ft_string (va_arg (arg_list, char), &printed);
	if (variable == 'p')
		ft_void_pointer (va_arg (arg_list, char), &printed);
	if (variable == 'd' || variable == 'i')
		ft_integer (va_arg (arg_list, int), &printed);
	if (variable == 'u')
		ft_unsigned_decimal (va_arg (arg_list, char), &printed);
	if (variable == 'x')
		ft_hexa_lower (va_arg (arg_list, char), &printed);
	if (variable == 'X')
		ft_hexa_upper (va_arg (arg_list, char), &printed);
	if (variable == '%')
	{
		write (1, '%', 1)
		(*printed)++;
	}
}

int	ft_printf(const char *format, ...)
{
	int			printed;
	int			i;
	va_list		args;

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
			ft_determination(format[i], &printed);
			i++;
		}
		else
			write(1, &format[i], 1);
			i++;
	}
	return (printed);
	va_end (args);
}
