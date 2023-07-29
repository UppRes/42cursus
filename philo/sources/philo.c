/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:59:31 by ykuru             #+#    #+#             */
/*   Updated: 2022/12/29 23:31:26 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_rules(int ac, char **av, t_rules *rules)
{
	if (!checkargs(av))
		return (0);
	if (atoi(av[1]) <= 1)
		return (0 * printf("0 0 Dead."));
	rules->number_of_philos = atoi(av[1]);
	rules->time_to_die = atoi(av[2]);
	rules->time_to_eat = atoi(av[3]);
	rules->time_to_sleep = atoi(av[4]);
	rules->time_to_think = (rules->time_to_die
			- (rules->time_to_eat + rules->time_to_sleep));
	if (ac == 6)
		rules->must_eat = atoi(av[5]);
	else
		rules->must_eat = -1;
	if (!create_philos(rules))
		return (0);
	if (!create_mutexes(rules))
		return (0);
	return (1);
}

int	create_threads(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->number_of_philos)
	{
		pthread_create(&rules->philos[i].thread_id, NULL,
			the_birth_of_thread, &rules->philos[i]);
	}
	i = -1;
	while (++i < rules->number_of_philos)
		pthread_join(rules->philos[i].thread_id, NULL);
	i = -1;
	while (++i < rules->number_of_philos)
		pthread_mutex_destroy(&rules->mutexes[i]);
	pthread_mutex_destroy(&rules->print_lock);
	free(rules->philos);
	free(rules->mutexes);
	return (1);
}

int	main(int ac, char **av)
{
	t_rules		rules;

	if (ac != 5 && ac != 6)
		return (0 * printf("Usage: ./philo t_die t_eat t_sleep <eat_count>\n"));
	if (!create_rules(ac, av, &rules))
		return (EXIT_FAILURE);
	if (!create_threads(&rules))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
