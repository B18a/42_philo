#include "../include/philo.h"



void *butler_handling(void *arg)
{
	t_table	*table;
	int			pos;

	table = (t_table*)arg;
	// all threads must run

	while (!dinner_finished(table))
	{
		pos = 0;
		while (pos < table->nbr_of_philos && !dinner_finished(table))
		{
			if(philo_died(&table->philos[pos]))
			{
				set_value_int(&table->end_of_dinner_mtx, &table->end_of_dinner, TRUE);
			}
			pos++;
		}
	}
}
