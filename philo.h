/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:39:25 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 16:16:13 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

#define GET -1337
#define INIT -7331

typedef struct s_philo
{
	int				id;
	time_t			last_eat;
	int				eat_num;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

int				parse(int ac, char *av[]);
void			init_philo(void);

int				time_eat(int io);
int				num_philo(int io);
int				time_dead(int io);
int				time_sleep(int io);
int				must_eat(int io);
time_t			start_time(time_t io);
time_t			get_time(void);

pthread_mutex_t	*write_lock(void);
t_philo			**philo_stack(int io);
void			*philo_life(void *arg);
void			*monitor(void *arg);
void			print_status(t_philo *philo, char *msg);