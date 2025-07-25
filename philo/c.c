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

void print_input(t_input *in)
{
    printf("philo  : %d\n", in->num_philo);
    printf("dead   : %d\n", in->time_dead);
    printf("eat    : %d\n", in->time_eat);
    printf("sleep  : %d\n", in->time_sleep);
    if (in->must_eat)
        printf("max    : %d\n", in->must_eat);
}

time_t  get_time(void)
{
    struct timeval now;

    gettimeofday(&now, NULL);
    return ((now.tv_sec * 1000 + now.tv_usec / 1000));
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
    init_input(in);
    return (0);
}
