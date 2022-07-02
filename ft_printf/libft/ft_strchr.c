/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:18:39 by ykuru             #+#    #+#             */
/*   Updated: 2022/02/08 19:46:27 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (c > 255)
		c -= 256;
	while (*(str + i))
	{
		if (*(str + i) == c)
			return ((char *)(str + i));
		i++;
	}
	if (*(str + i) == c)
		return ((char *)str + i);
	return (NULL);
}
