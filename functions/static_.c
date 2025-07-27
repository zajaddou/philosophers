/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 02:50:20 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 03:23:49 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	must_eat(int io)
{
	static int	save;

	if (io != GET)
		save = io;
	return (save);
}

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
