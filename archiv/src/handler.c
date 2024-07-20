#include "../include/philo.h"




int	mutex_handler(pthread_mutex_t *mutex, t_mutex code)
{
	if(code == LOCK)
		return(pthread_mutex_lock(mutex));
	else if(code == UNLOCK)
		return(pthread_mutex_unlock(mutex));
	else if(code == INIT)
		return(pthread_mutex_init(mutex, NULL));
	else if(code == DESTROY)
		return(pthread_mutex_destroy(mutex));
	else
		return(1);//???
}

int	thread_handler(pthread_t *thread, void *(*foo)(void *), void *data, t_thread code)
{
	if(code == CREATE)
		return(pthread_create(thread, NULL, foo, data));
	else if(code == JOIN)
		return(pthread_join(*thread, NULL));
	else if(code == DETACH)
		return(pthread_detach(*thread));
	else
		return 1;//???
}
