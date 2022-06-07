/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:18:48 by ykuru             #+#    #+#             */
/*   Updated: 2022/02/09 16:37:16 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;
	size_t	j;

	dst_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	i = dst_size;
	j = 0;
	if (size == 0)
		return (src_size);
	if (size < dst_size)
		return (src_size + size);
	else
	{
		while (src[j] && (dst_size + j) < size)
			dest[i++] = src[j++];
		if ((dst_size + j) == size && dst_size < size)
			dest[--i] = '\0';
		else
			dest[i] = '\0';
		return (src_size + dst_size);
	}
}
