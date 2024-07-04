#include "../include/philo.h"




void	mutex_handler(pthread_mutex_t *mutex, t_mutex code)
{
	if(code == LOCK)
		pthread_mutex_lock(mutex);
	else if(code == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if(code == INIT)
		pthread_mutex_init(mutex, NULL);
	else if(code == DESTROY)
		pthread_mutex_destroy(mutex);
	else
		return;//???
}

void	thread_handler(pthread_t *thread, void *(*foo)(void *), void *data, t_thread code)
{
	if(code == CREATE)
		pthread_create(thread, NULL, foo, data);
	else if(code == JOIN)
		pthread_join(*thread, NULL);
	else if(code == DETACH)
		pthread_detach(*thread);
	else
		return;//???
}
