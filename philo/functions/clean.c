/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 02:47:53 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 20:21:33 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clean_all(void)
{
	t_philo	*philo;
	int		i;

	unlock(write_lock());
	pthread_mutex_destroy(write_lock());
	philo = philo_stack();
	i = -1;
	while (++i < num_philo(GET))
	{
		unlock(philo[i].l_fork);
		pthread_mutex_destroy(philo[i].l_fork);
		unlock(philo[i].r_fork);
		pthread_mutex_destroy(philo[i].r_fork);
		unlock(&philo[i].safe_monitor);
		pthread_mutex_destroy(&philo[i].safe_monitor);
	}
}
