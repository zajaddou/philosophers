/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:36 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 17:11:22 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 + now.tv_usec / 1000));
}

void	get_start(void)
{
	pthread_t	*threads;
	pthread_t	monitor_th;
	t_philo		*philo;
	int			i;

	philo = *philo_stack(GET);
	threads = malloc(sizeof(pthread_t) * num_philo(GET));
	if (!threads)
		return ;
	i = 0;
	while (i < num_philo(GET))
	{
		pthread_create(&threads[i], NULL, philo_life, &philo[i]);
		i++;
	}
	pthread_create(&monitor_th, NULL, monitor, philo);
	pthread_join(monitor_th, NULL);
	i = -1;
	while (++i < num_philo(GET))
		pthread_detach(threads[i]);
	free(threads);
}

int	main(int ac, char *av[])
{
	if (parse(ac, av))
		return (1);
	init_philo();
	get_start();
	return (0);
}
