/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:51:02 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 15:51:15 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < num_philo(GET))
		{
			if ((get_time() - philo[i].last_eat) >= time_dead(GET))
			{
				print_status(&philo[i], "is died");
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
