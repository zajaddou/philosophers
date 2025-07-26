/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:36 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 15:50:54 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 + now.tv_usec / 1000));
}

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(write_lock());
	printf("%ld\t%d\t%s\n", get_time() - start_time(GET), philo->id, msg);
	if (!strcmp(msg, "is died"))
		return ;
	pthread_mutex_unlock(write_lock());
}

void	ft_sleep(time_t time)
{
	time_t	now;

	now = get_time();
	while ((get_time() - now) < time)
		usleep(time / 10);
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
	i = -1;
	while (++i < num_philo(GET))
		pthread_create(&threads[i], NULL, philo_life, &philo[i]);
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
