/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:35:00 by oemelyan          #+#    #+#             */
/*   Updated: 2023/07/21 23:38:13 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_upper(unsigned int a, int *printed)
{
	const char	*heks = "0123456789ABCDEF";

	if (a >= 16)
		ft_hexa_upper(a / 16, printed);
	ft_putchar2_fd(heks[a % 16], 1, printed);
}

void	ft_hexa_lower2(unsigned long a, int *printed)
{
	const char	*heks = "0123456789abcdef";

	if (a >= 16)
		ft_hexa_lower2(a / 16, printed);
	ft_putchar2_fd(heks[a % 16], 1, printed);
}

void	ft_void_pointer(unsigned long ptr, int fd, int *printed)
{
	(void)fd;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	(*printed) += 2;
	ft_hexa_lower2 (ptr, printed);
}
