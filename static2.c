/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:48 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 15:44:52 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	start_time(time_t io)
{
	static time_t	save;

	if (io != GET)
		save = io;
	return (save);
}

pthread_mutex_t	*write_lock(void)
{
	static pthread_mutex_t	lock;

	pthread_mutex_init(&lock, NULL);
	return (&lock);
}
