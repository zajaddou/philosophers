/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:31:45 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/23 12:10:56 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo    init_philo(t_input *input)
{
    int i;
    
    t_philo *philo;
    input->philo = malloc(sizeof(t_philo) * input->num_philo);
    i = 0;
    while (i < input->num_philo)
    {
        input->philo[i].id = i + 1;
        input->philo[i].eat_time = get_time();
        input->philo[i].eat_num = 0;
        pthread_mutex_init(&input->fork[i], NULL);
        i++;
    }
}