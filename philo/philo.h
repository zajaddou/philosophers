/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:39:25 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/27 19:37:14 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define GET -1

typedef struct s_philo
{
	int				id;
	time_t			last_eat;
	int				eat_num;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	safe_monitor;
}	t_philo;

int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				parse(int ac, char *av[]);
int				init_data(void);
int				time_eat(int io);
int				num_philo(int io);
int				time_dead(int io);
int				time_sleep(int io);
int				must_eat(int io);
int				lock(pthread_mutex_t *ptr);
int				unlock(pthread_mutex_t *ptr);
void			*philo_life(void *arg);
void			*monitor(void *arg);
void			clean_all(void);
void			print_status(t_philo *philo, char *msg);
time_t			start_time(time_t io);
time_t			get_time(void);
t_philo			*philo_stack(void);
pthread_mutex_t	*write_lock(void);
pthread_mutex_t	*forks_stack(void);
pthread_t		*pthreads_stack(void);

#endif