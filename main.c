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

int check_limit(t_data *data)
{
    if (num_philo(GET) < 0 || num_philo(GET) > 200)
        return (1);
    if (time_dead(GET) < 0)
        return (1);
    if (time_eat(GET) < 60)
        return (1);
    if (time_sleep(GET) < 60)
        return (1);
    if (must_eat(GET) <= 0)
        return (1);
    return (0);
}

// void print_data(t_data *data)
// {
//     printf("philo  : %d\n", data->num_philo);
//     printf("dead   : %d\n", data->time_dead);
//     printf("eat    : %d\n", data->time_eat);
//     printf("sleep  : %d\n", data->time_sleep);
//     if (data->must_eat)
//         printf("max    : %d\n", data->must_eat);
// }

time_t  get_time(void)
{
    struct timeval now;

    gettimeofday(&now, NULL);
    return ((now.tv_sec * 1000 + now.tv_usec / 1000));
}

void    print_status(t_philo *philo, char *msg)
{
    pthread_mutex_lock(write_lock());
    printf("%ld\t%d\t%s\n", get_time() - start_time(GET) , philo->id, msg);
    if (!strcmp(msg, "is died"))
        return ;
    pthread_mutex_unlock(write_lock());
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
        pthread_mutex_lock(philo->l_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->r_fork);
        print_status(philo, "has taken a fork");
        print_status(philo, "is eating");
        philo->eat_time = get_time();
        ft_sleep(time_eat(GET));
        pthread_mutex_unlock(philo->r_fork);
        pthread_mutex_unlock(philo->l_fork);
        print_status(philo, "is sleeping");
        ft_sleep(time_sleep(GET));
        print_status(philo, "is thinking");
    }
    return (NULL);
}

void    *monitor(void *arg)
{
    t_data *data;
    t_philo *philo;
    int     i;

    data = (t_data *)arg;
    philo = data->philo;
    while (1)
    {
        i = 0;
        while (i < num_philo(GET))
        {
            if ((get_time() - data->philo[i].eat_time) >= time_dead(GET))
            {
                print_status(philo, "is died");
                return (NULL);
            }
            i++;
        }
    }
    return (NULL);
}


void    get_start(t_data **data)
{
    int i;
    t_data     *tmp;
    pthread_t   *threads;
    pthread_t   monitor_th;

    tmp = *data;
    threads = malloc(sizeof(pthread_t) * num_philo(GET));
    i = -1;
    while (++i < num_philo(GET))
        pthread_create(&threads[i], NULL, life_philo, &tmp->philo[i]);
    pthread_create(&monitor_th, NULL, monitor, tmp);
    pthread_join(monitor_th, NULL);
    i = -1;
    while (++i < num_philo(GET))
        pthread_detach(threads[i]);

}

int parse(int ac, char *av[])
{
    if (!(ac == 5 || ac == 6))
        return (printf("Invalid Argement.\n"), 1);

    if (!check_args(av))
        return (printf("Invalid Params.\n"), 1);

    num_philo(atoi(av[1]));
    time_dead(atoi(av[2]));
    time_eat(atoi(av[3]));
    time_sleep(atoi(av[4]));
    must_eat(-1);
    if (ac == 6)
        must_eat(atoi(av[5]));
    if (check_limit(data))
        return (printf("Out of Limit.\n"), 1);
    start_time(get_time());
    malloc(sizeof(pthread_mutex_t) * num_philo(GET));
}

int main(int ac, char *av[])
{
    if (parce(ac, av))
        return (1);
    retirn (0);
    init_philo(data);
    get_start(data);
    return (0);
}
