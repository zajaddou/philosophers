/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:39:25 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/25 21:29:47 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_input
{
    int num_philo;
    int time_dead;
    int time_eat;
    int time_sleep;
    int must_eat;
    time_t  start_time;
    struct s_philo *philo;
    pthread_mutex_t *fork;
    pthread_mutex_t write;

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

void init_philo(t_input **input);
time_t  get_time(void);