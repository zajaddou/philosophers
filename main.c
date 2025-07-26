/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:36 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/26 15:29:38 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t get_time(void)
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return ((now.tv_sec * 1000 + now.tv_usec / 1000));
}

void print_status(t_philo *philo, char *msg)
{
    pthread_mutex_lock(write_lock());
    printf("%ld\t%d\t%s\n", get_time() - start_time(GET), philo->id, msg);
    if (!strcmp(msg, "is died"))
        return;
    pthread_mutex_unlock(write_lock());
}

void ft_sleep(time_t time)
{
    time_t now = get_time();
    while ((get_time() - now) < time)
        usleep(time / 10);
}

void *life_philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->id % 2 == 0)
        usleep(500);
    while (1)
    {
        pthread_mutex_lock(philo->l_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->r_fork);
        print_status(philo, "has taken a fork");
        print_status(philo, "is eating");
        philo->last_eat = get_time();
        ft_sleep(time_eat(GET));
        pthread_mutex_unlock(philo->r_fork);
        pthread_mutex_unlock(philo->l_fork);
        
        print_status(philo, "is sleeping");

        ft_sleep(time_sleep(GET));
        
        print_status(philo, "is thinking");
    }
    return (NULL);
}

void *monitor(void *arg)
{
    int i;
    t_philo *philo;
    
    philo = (t_philo *)arg;

    while (1)
    {
        i = 0;
        while (i < num_philo(GET))
        {
            if ((get_time() - philo[i].last_eat) >= time_dead(GET))
            {
                print_status(&philo[i], "is died");
                return (NULL);
            }
            i++;
        }
    }
    return (NULL);
}

void get_start()
{
    pthread_t   *threads;
    pthread_t   monitor_th;
    t_philo     *philo;
    int         i;

    philo = *philo_stack(GET);

    threads = malloc(sizeof(pthread_t) * num_philo(GET));
    if (!threads)
        return;

    i = -1;
    while (++i < num_philo(GET))
        pthread_create(&threads[i], NULL, life_philo, &philo[i]);

    pthread_create(&monitor_th, NULL, monitor, philo);
    pthread_join(monitor_th, NULL);

    i = -1;
    while (++i < num_philo(GET))
        pthread_detach(threads[i]);

    free(threads);
}



int main(int ac, char *av[])
{
    if (parse(ac, av))
        return (1);
    init_philo();
    get_start();
    return (0);
}
