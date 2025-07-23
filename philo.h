/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:39:25 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/23 12:02:24 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct s_input
{
    int num_philo;
    int time_dead;
    int time_eat;
    int time_sleep;
    int must_eat;
    time_t  start_time;
    t_philo *philo;
    pthread_mutex_t *fork;
    // pthread_mutex_t

} t_input;

typedef struct  s_philo
{
    int id;
    time_t eat_time;
    int eat_num;
    t_input *input;
    pthread_mutex_t l_fork;
    pthread_mutex_t r_fork;
}   t_philo;