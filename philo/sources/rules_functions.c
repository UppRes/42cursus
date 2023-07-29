/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:13:08 by ykuru             #+#    #+#             */
/*   Updated: 2022/12/29 23:17:27 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_mutexes(t_rules *rules)
{
	int	i;

	i = -1;
	rules->mutexes = malloc(sizeof(pthread_mutex_t) * rules->number_of_philos);
	while (++i < rules->number_of_philos)
	{
		if (pthread_mutex_init(&rules->mutexes[i], NULL))
			return (0 * printf("%d. mutex is not created.\n", i));
	}
	pthread_mutex_init(&rules->print_lock, NULL);
	return (1);
}

int	create_philos(t_rules *rules)
{
	int	i;

	i = -1;
	rules->philos = malloc(sizeof(t_philos) * rules->number_of_philos);
	while (++i < rules->number_of_philos)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].l_philo = i;
		rules->philos[i].r_philo = (i + 1) % rules->number_of_philos;
		rules->philos[i].how_many_meals = 0;
		rules->philos[i].should_i_sleep = UNFORTUNATELY;
		rules->philos[i].should_i_eat = FORTUNATELY;
		if (rules->time_to_think > 0)
			rules->philos[i].should_i_think = FORTUNATELY;
		else
			rules->philos[i].should_i_think = UNFORTUNATELY;
		rules->philos[i].am_i_still_alive = FORTUNATELY;
		rules->philos[i].rules = rules;
	}
	return (1);
}
