/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 02:51:33 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 03:24:07 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	lock(pthread_mutex_t *ptr)
{
	return (pthread_mutex_lock(ptr));
}

int	unlock(pthread_mutex_t *ptr)
{
	return (pthread_mutex_unlock(ptr));
}
