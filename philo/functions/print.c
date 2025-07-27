/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:27:24 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 17:26:24 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_status(t_philo *philo, char *msg)
{
	long	time;

	time = get_time() - start_time(GET);
	lock(write_lock());
	printf("%ld\t%d %s\n", time, philo->id, msg);
	if (!ft_strcmp(msg, "died"))
		return ;
	unlock(write_lock());
}
