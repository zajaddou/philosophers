/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:48 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 01:09:13 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	num_philo(int io)
{
	static int	save;

	if (io != GET)
		save = io;
	return (save);
}

int	time_dead(int io)
{
	static int	save;

	if (io != GET)
		save = io;
	return (save);
}

int	time_sleep(int io)
{
	static int	save;

	if (io != GET)
		save = io;
	return (save);
}

int	time_eat(int io)
{
	static int	save;

	if (io != GET)
		save = io;
	return (save);
}

int	must_eat(int io)
{
	static int	save;

	if (io != GET)
		save = io;
	return (save);
}
