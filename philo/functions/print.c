/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:27:24 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 17:29:38 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_status(t_philo *philo, char *msg)
{
	time_t	time;

	lock(write_lock());
	time = get_time() - start_time(GET);
	printf("%ld\t%d %s\n", time, philo->id, msg);
	if (!ft_strcmp(msg, "died"))
		return ;
	unlock(write_lock());
}
