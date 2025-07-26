/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:31:45 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 12:59:01 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_data **data)
{
    int i;
    t_data *tmp;

    tmp = *data;
    tmp->philo = malloc(sizeof(t_philo) * num_philo(GET));
    i = 0;
    while (i < num_philo(GET))
    {
        pthread_mutex_datait(&tmp->fork[i], NULL);
        tmp->philo[i].id = i + 1;
        tmp->philo[i].eat_time = get_time();
        tmp->philo[i].eat_num = 0;
        tmp->philo[i].data = tmp;
        tmp->philo[i].l_fork = &tmp->fork[i];
        tmp->philo[i].r_fork = &tmp->fork[(i + 1) % num_philo(GET)];
        i++;
    }
    pthread_mutex_datait(&tmp->write, NULL);
}
