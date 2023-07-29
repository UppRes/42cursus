/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:48:13 by ykuru             #+#    #+#             */
/*   Updated: 2022/08/30 12:10:54 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_signal(int s)
{
	static char		c = 0;
	static int		i = 128;

	if (s == SIGUSR1)
		c += i;
	i /= 2;
	if (i == 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 128;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	signal(SIGUSR1, put_signal);
	signal(SIGUSR2, put_signal);
	while (1)
		pause();
	return (0);
}
