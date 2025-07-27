/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:36 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 02:47:43 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 + now.tv_usec / 1000));
}

void	start_threads(void)
{
	pthread_t	threads[200];
	pthread_t	monitor_th;
	t_philo		*philo;
	int			i;

	philo = philo_stack();
	i = -1;
	while (++i < num_philo(GET))
		pthread_create(&threads[i], NULL, philo_life, &philo[i]);
	pthread_create(&monitor_th, NULL, monitor, philo);
	pthread_join(monitor_th, NULL);
	i = -1;
	while (++i < num_philo(GET))
		pthread_detach(threads[i]);
}

int	main(int ac, char *av[])
{
	if (parse(ac, av))
		return (1);
	if (init_philo())
		return (1);
	start_threads();
	clean_all();
	return (0);
}
