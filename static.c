
#include "philo.h"

pthread_mutex_t *forks(pthread_mutex_t *new)
{
	static pthread_mutex_t *tk_save;
	if (new)
		tk_save = new;
	return (tk_save);
}

t_data *data(t_data *new)
{
	static t_data *db_save;
	if (new)
		db_save = new;
	return (db_save);
}

