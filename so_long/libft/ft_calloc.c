/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:58:38 by ykuru             #+#    #+#             */
/*   Updated: 2022/03/14 23:01:24 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t countbyte)
{
	void	*p;

	p = malloc(count * countbyte);
	if (!p)
		return (0);
	ft_bzero(p, count * countbyte);
	return (p);
}
