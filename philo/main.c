#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int is_valid(char *str)
{
    int i = -1;
    while (str[++i])
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
    return (1);
}

int check_args(char **av)
{
    int i = 0;
    while (av[++i])
        if (!is_valid(av[i]))
            return (0);
    return (1);
}

int check_limit(t_input *in)
{
    if (in->num_philo < 0 || in->num_philo > 200)
        return (1);
    if (in->time_dead < 0)
        return (1);
    if (in->time_eat < 60)
        return (1);
    if (in->time_sleep < 60)
        return (1);
    if (in->must_eat <= 0)
        return (1);
    return (0);
}

// void print_input(t_input *in)
// {
//     printf("philo  : %d\n", in->num_philo);
//     printf("dead   : %d\n", in->time_dead);
//     printf("eat    : %d\n", in->time_eat);
//     printf("sleep  : %d\n", in->time_sleep);
//     if (in->must_eat)
//         printf("max    : %d\n", in->must_eat);
// }

time_t  get_time(void)
{
    struct timeval now;

    gettimeofday(&now, NULL);
    return ((now.tv_sec * 1000 + now.tv_usec / 1000));
}

void    print_status(t_philo *philo, char *msg)
{
    time_t  time;

    time = philo->input->start_time;
    pthread_mutex_lock(&philo->input->write);
    printf("%ld\t%d\t%s\n", get_time() - time , philo->id, msg);
    pthread_mutex_unlock(&philo->input->write);
}

void    ft_sleep(time_t time)
{
    time_t  now;

    now = get_time();
    while ((get_time() - now) < time)
        usleep(time / 10);
}

void    *life_philo(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        usleep(500);
    while (1)
    {
        pthread_mutex_lock(&philo->l_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&philo->r_fork);
        print_status(philo, "has taken a fork");
        print_status(philo, "is eating");
        ft_sleep(philo->input->time_eat);
        pthread_mutex_unlock(&philo->r_fork);
        pthread_mutex_unlock(&philo->l_fork);
        print_status(philo, "has lift a fork");
    }
    return (NULL);
}

// void    *monitor(void *arg)
// {
//     t_input *data;

//     data = (t_input *)arg;
//     while (1)
//     {

//     }
// }

void    get_start(t_input **data)
{
    int i;
    t_input *tmp;
    pthread_t   *threads;
    // pthread_t   monitor;

    tmp = *data;
    threads = malloc(sizeof(pthread_t) * tmp->num_philo);
    i = -1;
    while (++i < tmp->num_philo)
        pthread_create(&threads[i], NULL, life_philo, &tmp->philo[i]);
    // pthread_create(&monitor, NULL, monitor, tmp);
    i = -1;
    while (++i < tmp->num_philo)
        pthread_join(threads[i], NULL);

}

int main(int ac, char *av[])
{
    t_input *in;

    in = malloc(sizeof(t_input));
    if (!(ac == 5 || ac == 6))
        return (printf("Invalid Argement.\n"), 1);

    if (!check_args(av))
        return (printf("Invalid Params.\n"), 1);

    in->num_philo = atoi(av[1]);
    in->time_dead = atoi(av[2]);
    in->time_eat = atoi(av[3]);
    in->time_sleep = atoi(av[4]);
    in->must_eat = -1;
    if (ac == 6)
        in->must_eat = atoi(av[5]);
    in->start_time = get_time();
    if (check_limit(in))
        return (printf("Out of Limit.\n"), 1);
    
    in->fork = malloc(sizeof(pthread_mutex_t) * in->num_philo);
    // print_input(&in);
    init_philo(&in);
    get_start(&in);
    return (0);
}
