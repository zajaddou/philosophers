/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:09:16 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 15:47:31 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

int	check_args(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
		if (!is_valid(av[i]))
			return (0);
	return (1);
}

int	check_limit(void)
{
	if (num_philo(GET) < 0 || num_philo(GET) > 200)
		return (1);
	if (time_dead(GET) < 0)
		return (1);
	if (time_eat(GET) < 60)
		return (1);
	if (time_sleep(GET) < 60)
		return (1);
	if (must_eat(GET) <= 0)
		return (1);
	return (0);
}

int	parse(int ac, char *av[])
{
	if (!(ac == 5 || ac == 6))
		return (printf("Invalid Argument.\n"), 1);
	if (!check_args(av))
		return (printf("Invalid Params.\n"), 1);
	num_philo(atoi(av[1]));
	time_dead(atoi(av[2]));
	time_eat(atoi(av[3]));
	time_sleep(atoi(av[4]));
	start_time(get_time());
	must_eat(-1);
	if (ac == 6)
		must_eat(atoi(av[5]));
	if (check_limit())
		return (printf("out of Limit.\n"), 1);
	return (0);
}
