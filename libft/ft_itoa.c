/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:15:28 by ykuru             #+#    #+#             */
/*   Updated: 2022/03/15 01:05:50 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr <= 0)
		nbr_len++;
	while (nbr)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*dizi;
	long	nbr;

	nbr = n;
	len = numlen(nbr);
	dizi = malloc(sizeof(char) * len + 1);
	if (!dizi)
		return (0);
	dizi[len--] = '\0';
	if (n < 0)
	{
		dizi[0] = '-';
		nbr = -nbr;
	}
	if (n == 0)
		dizi[0] = '0';
	while (nbr > 0)
	{
		dizi[len--] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (dizi);
}
