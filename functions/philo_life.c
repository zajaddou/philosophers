/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:48:42 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 17:02:59 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_sleep(time_t time)
{
	time_t	now;

	now = get_time();
	while ((get_time() - now) < time)
		usleep(time / 10);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		pthread_mutex_lock(&philo->safe_philo);
		philo->last_eat = get_time();
		philo->eat_num++;
		pthread_mutex_unlock(&philo->safe_philo);
		ft_sleep(time_eat(GET));
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		print_status(philo, "is sleeping");
		ft_sleep(time_sleep(GET));
		print_status(philo, "is thinking");
	}
	return (NULL);
}
