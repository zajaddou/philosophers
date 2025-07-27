/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:48:42 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 19:35:03 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	run(time_t time)
{
	time_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(50);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(200);
	while (1)
	{
		lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		lock(philo->r_fork);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		lock(&philo->safe_monitor);
		philo->last_eat = get_time();
		philo->eat_num++;
		unlock(&philo->safe_monitor);
		run(time_eat(GET));
		unlock(philo->l_fork);
		unlock(philo->r_fork);
		print_status(philo, "is sleeping");
		run(time_sleep(GET));
		print_status(philo, "is thinking");
	}
	return (NULL);
}
