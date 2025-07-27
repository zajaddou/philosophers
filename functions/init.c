/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:40 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 01:11:53 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t	*write_lock(void)
{
	static pthread_mutex_t	lock;

	return (&lock);
}

t_philo	*philo_stack(void)
{
	static t_philo	array[200];

	return (array);
}

pthread_mutex_t	*forks_stack(void)
{
	static pthread_mutex_t	philo_forks[200];

	return (philo_forks);
}

void	init_philo(void)
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	int				i;

	philo = philo_stack();
	fork = forks_stack();
	if (!philo || !fork)
		return ;
	i = -1;
	while (++i < num_philo(GET))
	{
		pthread_mutex_init(&fork[i], NULL);
		pthread_mutex_init(&philo[i].safe_philo, NULL);
		philo[i].id = i + 1;
		philo[i].last_eat = get_time();
		philo[i].eat_num = 0;
		philo[i].l_fork = &fork[i];
		philo[i].r_fork = &fork[(i + 1) % num_philo(GET)];
	}
	pthread_mutex_init(write_lock(), NULL);
}
