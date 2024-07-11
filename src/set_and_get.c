#include "../include/philo.h"


void	set_value_long(pthread_mutex_t *mutex,long *dst ,long value)
{
	pthread_mutex_lock(mutex);
	*dst = value;
	pthread_mutex_unlock(mutex);

}

long	get_value_long(pthread_mutex_t *mutex,long *dst)
{
	long	value;

	value = 0;
	pthread_mutex_lock(mutex);
	value = *dst;
	pthread_mutex_unlock(mutex);
	return(value);
}


void	set_value_int(pthread_mutex_t *mutex,int *dst ,int value)
{
	pthread_mutex_lock(mutex);
	*dst = value;
	pthread_mutex_unlock(mutex);

}

int	get_value_int(pthread_mutex_t *mutex,int *dst)
{
	int	value;

	value = 0;
	pthread_mutex_lock(mutex);
	value = *dst;
	pthread_mutex_unlock(mutex);
	return(value);
}

int	dining_finished(t_butler *butler)
{
	return(get_value_int(&butler->ready_mtx, &butler->end_of_dinner));
}