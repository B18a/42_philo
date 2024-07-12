#include "../include/philo.h"


void	wait_for_all_philos(t_table *table)
{
	while(1)
	{
		if(get_value_int(&table->all_philos_ready_to_eat_mtx, &table->all_philos_ready_to_eat))
			break;
	}
}



void *dining(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	wait_for_all_philos(philo->table);
	while(!dinner_finished(philo->table))
	{
//			if(get_value_int(&philo->philo_mtx, &philo->done));
		if(philo->done)
			break;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	
	return(NULL);
}


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


void	greeting_philos(t_table *table)
{
	int	i;

	i = 0;
	if(table->nbr_of_philos == 1)
	{
		//let the philo die
	}
	else if(table->meals_to_eat  == 0) // not needed or change handle input
		return;
	else
	{
		while(i < table->nbr_of_philos)
		{
			if(pthread_create(&table->philos[i].thread, NULL, &dining, (void*)&table->philos[i]) != 0)
				printf("failed to create Philo[%i]\n",i + 1); // Needed?
			printf("Philo[%i] created\n",i + 1); // Needed?
			i++;
		}
		//butler
		pthread_create(&table->butler, NULL, &butler_handling, &table);

		//get the time
		table->start_time = get_time_in_millis();
		//all philos are ready to eat
		set_value_int(&table->all_philos_ready_to_eat_mtx, &table->all_philos_ready_to_eat, TRUE);

		//dining
		i = 0;
		while(i < table->nbr_of_philos)
		{
			if(pthread_join(table->philos[i].thread, NULL) != 0)
				printf("failed to join Philo[%i]\n",i + 1); // Needed?
			printf("Philo[%i] joined\n",i + 1); // Needed?
			i++;
		}
		//all philos are full
	}
}
