
#include "../include/philo.h"

void free_mem(t_supervisor *supervisor)
{
	if(supervisor)
	{
		if(supervisor->philos)
			free(supervisor->philos);
		free(supervisor);
	}
}
