/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:51:02 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 17:02:35 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;
	int		done;

	philo = (t_philo *)arg;
	while (1)
	{
		i = -1;
		done = 0;
		while (++i < num_philo(GET))
		{
			pthread_mutex_lock(&philo[i].safe_philo);
			if ((get_time() - philo[i].last_eat) >= time_dead(GET))
			{
				print_status(&philo[i], "is died");
				pthread_mutex_unlock(&philo[i].safe_philo);
				return (NULL);
			}
			if (must_eat(GET) > 0 && philo[i].eat_num >= must_eat(GET))
				done++;
			pthread_mutex_unlock(&philo[i].safe_philo);
		}
		if (must_eat(GET) > 0 && done == num_philo(GET))
			return (NULL);
		// pthread_mutex_lock(&philo->safe_philo);
		// usleep(100);
	}
}
