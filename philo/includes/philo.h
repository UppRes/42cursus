/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 02:17:32 by ykuru             #+#    #+#             */
/*   Updated: 2022/12/29 22:01:21 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define FORTUNATELY 1
# define UNFORTUNATELY 0

struct	s_philos;

typedef struct s_rules
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_think;
	int				time_to_sleep;
	int				must_eat;
	struct s_philos	*philos;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	print_lock;
}	t_rules;

typedef struct s_philos
{
	int			id;
	int			l_philo;
	int			r_philo;
	int			should_i_sleep;
	int			should_i_eat;
	int			should_i_think;
	int			am_i_still_alive;
	long		start_time;
	long		last_meal;
	int			how_many_meals;
	pthread_t	thread_id;
	t_rules		*rules;
}	t_philos;

//create_rules_functions
int		checkargs(char **argv);
int		create_philos(t_rules *rules);
int		create_mutexes(t_rules *rules);

//create_threads_functions
void	*the_birth_of_thread(void *type);
void	print_status(t_philos *plato);
void	is_time_up(t_philos *plato, int time);
long	get_time(void);
void	time_to_meal(t_philos *plato);
void	time_to_sleep(t_philos *plato);
void	time_to_think(t_philos *plato);
void	time_to_die(t_philos *plato);

#endif
