/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:36:03 by ykuru             #+#    #+#             */
/*   Updated: 2022/12/29 23:24:10 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long)tv.tv_sec * 1000) + ((long)tv.tv_usec / 1000));
}

void	is_time_up(t_philos *plato, int time)
{
	long	start_time;

	start_time = get_time();
	while (get_time() - plato->last_meal < plato->rules->time_to_die)
	{
		if (get_time() - start_time >= time)
			break ;
		usleep(1 * 500);
	}
}

void	print_status(t_philos *plato)
{
	pthread_mutex_lock(&plato->rules->print_lock);
	if (plato->am_i_still_alive == UNFORTUNATELY)
	{
		printf("%ld ms %d. philo is die\n",
			(get_time() - plato->start_time), plato->id);
	}
	else if (plato->should_i_think)
	{
		printf("%ld ms %d. philo is thinking\n",
			(get_time() - plato->start_time), plato->id);
	}
	else if (plato->should_i_eat)
	{
		printf("%ld ms %d. philo has take forks\n",
			get_time() - plato->start_time, plato->id);
		printf("%ld ms %d. philo is eating\n",
			(get_time() - plato->start_time), plato->id);
	}
	else if (plato->should_i_sleep)
	{
		printf("%ld ms %d. philo is sleeping\n",
			(get_time() - plato->start_time), plato->id);
	}
	pthread_mutex_unlock(&plato->rules->print_lock);
}

// void	*check(void *type)
// {
// 	t_rules	*rules;
// 	int		i;

// 	rules = (t_rules *)type;
// 	i = 0;
// 	while (1)
// 	{
// 		if (!rules->philos[i].am_i_still_alive)
// 			break ;
// 		if (get_time() - rules->philos[i].last_meal > rules->time_to_die)
// 			time_to_die(&rules->philos[i]);
// 		if (i == rules->number_of_philos - 1)
// 			i = 0;
// 		usleep(1 * 100);
// 	}
// 	return (NULL);
// }

void	*the_birth_of_thread(void *type)
{
	t_philos	*plato;

	plato = (t_philos *)type;
	plato->start_time = get_time();
	plato->last_meal = get_time();
	while (plato->am_i_still_alive == FORTUNATELY)
	{
		if (plato->how_many_meals == plato->rules->must_eat)
			break ;
		if (get_time() - plato->last_meal > plato->rules->time_to_die)
			time_to_die(plato);
		if (plato->should_i_think)
			time_to_think(plato);
		else if (plato->should_i_eat)
			time_to_meal(plato);
		else if (plato->should_i_sleep)
			time_to_sleep(plato);
	}
	return (NULL);
}
