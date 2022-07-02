/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:02:23 by ykuru             #+#    #+#             */
/*   Updated: 2022/07/03 00:34:03 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putstr(char *new, int *byte)
{
	int	i;

	i = 0;
	if (!new)
	{
		ft_putstr("(null)", byte);
		return ;
	}
	while (new[i])
		ft_putchar(new[i++], byte);
}

void	ft_putnumber(int x, int *byte)
{
	if (x < 0)
	{
		if (x == -2147483648)
		{
			ft_putstr("-2147483648", byte);
			return ;
		}
		ft_putchar('-', byte);
		x = -x;
	}
	if (x >= 10)
		ft_putnumber(x / 10, byte);
	ft_putchar((x % 10) + 48, byte);
}

void	ft_putunsigned(unsigned int x, int *byte)
{
	if (x >= 10)
		ft_putnumber(x / 10, byte);
	ft_putchar((x % 10) + 48, byte);
}

void	ft_puthex(unsigned int n, int type, int *byte)
{
	char	*a;

	if (type == 'X')
		a = ft_strdup("0123456789ABCDEF");
	else
		a = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ft_puthex(n / 16, type, byte);
		ft_puthex(n % 16, type, byte);
	}
	else
		ft_putchar(a[n], byte);
	free(a);
}

void	ft_putaddress(unsigned long long n, int *byte)
{
	char	*a;

	a = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ft_putaddress(n / 16, byte);
		ft_putaddress(n % 16, byte);
	}
	else
		ft_putchar(a[n], byte);
	free(a);
}
