/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:27:24 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 01:09:09 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_status(t_philo *philo, char *msg)
{
	long	time;

	time = get_time() - start_time(GET);
	pthread_mutex_lock(write_lock());
	printf("%ld\t%d\t%s\n", time, philo->id, msg);
	if (!strcmp(msg, "is died"))
		return ;
	pthread_mutex_unlock(write_lock());
}

time_t	start_time(time_t io)
{
	static time_t	save;

	if (io != GET)
		save = io;
	return (save);
}
