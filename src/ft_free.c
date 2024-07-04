
#include "../include/philo.h"

void free_mem(t_supervisor *supervisor)
{
		if(supervisor->philos)
			free(supervisor->philos);
		if(supervisor->forks)
			free(supervisor->forks);
}
