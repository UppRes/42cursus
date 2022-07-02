/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:02:45 by ykuru             #+#    #+#             */
/*   Updated: 2022/07/03 00:34:09 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

void	ft_putchar(int x, int *index);
void	ft_putstr(char *new, int *byte);
void	ft_putnumber(int x, int *byte);
void	ft_putunsigned(unsigned int x, int *byte);
void	ft_puthex(unsigned int n, int type, int *byte);
void	ft_putaddress(unsigned long long n, int *byte);

int		ft_printf(const	char *str, ...);

#endif