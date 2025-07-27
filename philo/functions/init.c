/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:40 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 17:23:55 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_data(void)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				i;

	philo = philo_stack();
	forks = forks_stack();
	if (!philo || !forks)
		return (1);
	i = -1;
	while (++i < num_philo(GET))
	{
		pthread_mutex_init(&forks[i], NULL);
		pthread_mutex_init(&philo[i].safe_monitor, NULL);
		philo[i].id = i + 1;
		philo[i].last_eat = get_time();
		philo[i].eat_num = 0;
		philo[i].l_fork = &forks[i];
		philo[i].r_fork = &forks[(i + 1) % num_philo(GET)];
	}
	pthread_mutex_init(write_lock(), NULL);
	return (0);
}
