/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:18:59 by ykuru             #+#    #+#             */
/*   Updated: 2022/02/09 16:38:48 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	x;

	x = 0;
	if (n > 0)
	{
		while (src [x] != '\0' && x < (n - 1))
		{
			dst[x] = src [x];
			x++;
		}
		dst[x] = 0;
	}
	while (src[x])
		x++;
	return (x);
}
