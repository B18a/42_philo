
#include "../include/philo.h"

void free_mem(t_table *table)
{
		if(table->philos)
			free(table->philos);
		if(table->forks)
			free(table->forks);
}
