/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:31:45 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/25 21:31:49 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_input **input)
{
    int i;
    t_input *tmp;

    tmp = *input;
    tmp->philo = malloc(sizeof(t_philo) * tmp->num_philo);
    i = 0;
    while (i < tmp->num_philo)
    {
        tmp->philo[i].id = i + 1;
        tmp->philo[i].eat_time = get_time();
        tmp->philo[i].eat_num = 0;
        tmp->philo[i].input = tmp;
        tmp->philo[i].l_fork = tmp->fork[i];
        tmp->philo[i].r_fork = tmp->fork[(i + 1) % tmp->num_philo];
        pthread_mutex_init(&tmp->fork[i], NULL);
        i++;
    }
    pthread_mutex_init(&tmp->write, NULL);
}
