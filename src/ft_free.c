
#include "../include/philo.h"

void free_mem(t_butler *butler)
{
		if(butler->philos)
			free(butler->philos);
		if(butler->forks)
			free(butler->forks);
}
