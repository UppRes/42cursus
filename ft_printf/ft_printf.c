/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:01:49 by ykuru             #+#    #+#             */
/*   Updated: 2022/07/03 00:34:49 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putchar(int x, int *index)
{
	(*index)++;
	write(1, &x, 1);
}

static void	type_convert(va_list va, char type, int *byte)
{
	if (type == 'c')
		ft_putchar(va_arg(va, int), byte);
	else if (type == 's')
		ft_putstr(va_arg(va, char *), byte);
	else if (type == 'd' || type == 'i')
		ft_putnumber(va_arg(va, int), byte);
	else if (type == 'p')
	{
		ft_putstr("0x", byte);
		ft_putaddress(va_arg(va, unsigned long long), byte);
	}
	if (type == 'u')
		ft_putunsigned(va_arg(va, unsigned int), byte);
	if (type == 'x' || type == 'X')
		ft_puthex(va_arg(va, unsigned int), type, byte);
	if (type == '%')
		ft_putchar('%', byte);
}

int	ft_printf(const char *new, ...)
{
	int		index;
	int		toplam_byte;
	va_list	va;

	va_start(va, new);
	index = 0;
	toplam_byte = 0;
	while (new[index])
	{
		if (new[index] == '%')
		{
			index++;
			type_convert(va, new[index], &toplam_byte);
		}
		else
			ft_putchar(new[index], &toplam_byte);
		index++;
	}
	va_end(va);
	return (toplam_byte);
}
