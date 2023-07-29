/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 02:14:30 by ykuru             #+#    #+#             */
/*   Updated: 2022/12/29 23:27:42 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	time_to_meal(t_philos *plato)
{
	pthread_mutex_lock(&plato->rules->mutexes[plato->l_philo]);
	pthread_mutex_lock(&plato->rules->mutexes[plato->r_philo]);
	print_status(plato);
	plato->how_many_meals++;
	is_time_up(plato, plato->rules->time_to_eat);
	plato->last_meal = get_time();
	plato->should_i_eat = UNFORTUNATELY;
	plato->should_i_sleep = FORTUNATELY;
	pthread_mutex_unlock(&plato->rules->mutexes[plato->l_philo]);
	pthread_mutex_unlock(&plato->rules->mutexes[plato->r_philo]);
}

void	time_to_sleep(t_philos *plato)
{
	print_status(plato);
	is_time_up(plato, plato->rules->time_to_sleep);
	plato->should_i_sleep = UNFORTUNATELY;
	if (plato->rules->time_to_think > 0)
		plato->should_i_think = FORTUNATELY;
	else
		plato->should_i_think = UNFORTUNATELY;
}

void	time_to_think(t_philos *plato)
{
	print_status(plato);
	is_time_up(plato, plato->rules->time_to_think);
	plato->should_i_think = UNFORTUNATELY;
	if (plato->rules->number_of_philos > 1)
		plato->should_i_eat = FORTUNATELY;
}

void	time_to_die(t_philos *plato)
{
	plato->am_i_still_alive = UNFORTUNATELY;
	print_status(plato);
}
