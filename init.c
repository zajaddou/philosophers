/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:40 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 16:31:20 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**philo_stack(int io)
{
	static t_philo	*philo;

	if (io == INIT)
	{
		philo = malloc(sizeof(t_philo) * num_philo(GET));
		if (!philo)
			return (NULL);
	}
	if (philo)
		return (&philo);
	return (NULL);
}

pthread_mutex_t	**forks_stack(int io)
{
	static pthread_mutex_t	*fork;

	if (io == INIT)
	{
		fork = malloc(sizeof(pthread_mutex_t) * num_philo(GET));
		if (!fork)
			return (NULL);
	}
	if (fork)
		return (&fork);
	return (NULL);
}

void	init_philo(void)
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	int				i;

	philo = *philo_stack(INIT);
	fork = *forks_stack(INIT);
	if (!philo || !fork)
		return ;
	i = -1;
	while (++i < num_philo(GET))
	{
		pthread_mutex_init(&fork[i], NULL);
		philo[i].id = i + 1;
		philo[i].last_eat = get_time();
		philo[i].eat_num = 0;
		philo[i].l_fork = &fork[i];
		philo[i].r_fork = &fork[(i + 1) % num_philo(GET)];
	}
	pthread_mutex_init(write_lock(), NULL);
}
