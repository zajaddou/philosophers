
#include "philo.h"

int		num_philo(int io)
{
	static int save;
	if (io != GET)
		save = io;
	return (save);
}

int		time_dead(int io)
{
	static int save;
	if (io != GET)
		save = io;
	return (save);
}

int		time_sleep(int io)
{
	static int save;
	if (io != GET)
		save = io;
	return (save);
}

int		time_eat(int io)
{
	static int save;
	if (io != GET)
		save = io;
	return (save);
}

int		must_eat(int io)
{
	static int save;
	if (io != GET)
		save = io;
	return (save);
}

time_t    start_time(time_t io)
{
	static time_t save;
	if (io != GET)
		save = io;
	return (save);
}

pthread_mutex_t     *write_lock(void)
{
    static time_t lock;
	return (lock);
}