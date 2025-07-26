/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:27:24 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 17:10:17 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t	*write_lock(void)
{
	static pthread_mutex_t	lock;

	return (&lock);
}

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
