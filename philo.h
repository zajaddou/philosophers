/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:39:25 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 13:39:14 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define GET -1337

typedef struct s_data
{
    struct s_philo *philo;
    pthread_mutex_t write;
} t_data;

typedef struct  s_philo
{
    int id;
    time_t eat_time;
    int eat_num;
    t_data *data;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
}   t_philo;

int                 time_eat(int io);
int                 num_philo(int io);
int                 time_dead(int io);
int                 time_sleep(int io);
int                 must_eat(int io);
time_t              start_time(time_t io);
void                init_philo(t_data **dataput);
time_t              get_time(void);
t_data              *data(t_data *new);
pthread_mutex_t     *forks(pthread_mutex_t *new);
pthread_mutex_t     *write_lock(void);
