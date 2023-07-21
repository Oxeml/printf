/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:26:55 by oemelyan          #+#    #+#             */
/*   Updated: 2023/07/21 15:24:56 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
// # include"libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_determination (char variable, int *printed, va_list arg_list);
void	ft_putstr_fd(char *s, int fd, int *printed);
void	ft_void_pointer (unsigned long ptr, int fd, int *printed);
void	ft_hexa_upper (unsigned int a, int *printed);
void	ft_hexa_lower (unsigned int a, int *printed);
void	ft_hexa_lower2(unsigned long a, int *printed);
void	ft_putnbr_fd(int n, int fd, int *printed);
void	ft_unsigned_decimal(unsigned int n, int fd, int *printed);
void	ft_putchar2_fd(char c, int fd, int	*printed);
void	ft_putchar_fd(char c, int fd);
#endif