/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:59:15 by ykuru             #+#    #+#             */
/*   Updated: 2022/12/26 17:39:03 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	checknumber(char *str, int id)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0 * printf("Arguments Are not numeric\n"));
		i++;
	}
	i = atoi(str);
	if (id != 5)
	{
		if (i < 60)
			return (0 * printf("Paramaters cannot be lower than 60\n"));
	}
	if (i == 0 || i == -1)
		return (0 * printf("Parameters must integer\n"));
	return (1);
}

int	checkargs(char **argv)
{
	int	i;

	i = 1;
	while (argv[++i])
	{
		if (!checknumber(argv[i], i))
			return (0);
	}
	if (atoi(argv[1]) <= 200)
	{
		i = 0;
		while (argv[1][i])
		{
			if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
				return (0 * printf("Arguments Are not numeric\n"));
			i++;
		}
	}
	else
		return (0 * printf("Maximum philosopher count is 200\n"));
	return (1);
}
