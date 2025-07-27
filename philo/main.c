/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:36 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 19:37:31 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 + now.tv_usec / 1000));
}

int	start_threads(void)
{
	pthread_t	*threads;
	pthread_t	monitor_th;
	t_philo		*philo;
	int			err;
	int			i;

	philo = philo_stack();
	threads = pthreads_stack();
	i = -1;
	while (++i < num_philo(GET))
	{
		err = pthread_create(&threads[i], NULL, philo_life, &philo[i]);
		if (err != 0)
			return (1);
	}
	err = pthread_create(&monitor_th, NULL, monitor, philo);
	if (err != 0)
		return (1);
	pthread_join(monitor_th, NULL);
	i = -1;
	while (++i < num_philo(GET))
		pthread_detach(threads[i]);
	return (0);
}

int	main(int ac, char *av[])
{
	if (parse(ac, av))
		return (1);
	if (init_data())
		return (1);
	if (start_threads())
	{
		write(2, "Error.\n", 7);
		clean_all();
		return (1);
	}
	clean_all();
	return (0);
}
