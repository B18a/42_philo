#include "../include/philo.h"


void	wait_for_all_philos(t_butler *butler)
{
	while(1)
	{
		if(get_value_int(&butler->ready_mtx, &butler->all_philos_ready_to_eat))
			break;
	}
}



void *dining(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;

	wait_for_all_philos(philo->butler);

	while(!dining_finished(philo->butler))
	{
		if(philo->done)
			break;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	
	return(NULL);
}


void *supervision(void *arg)
{
	t_butler	*butler;
	int			pos;

	butler = (t_butler*)arg;
	// all threads must run

	while (!dining_finished(butler))
	{
		pos = 0;
		while (pos < butler->nbr_of_philos && !dining_finished(butler))
		{
			if(philo_died(&butler->philos[pos]))
			{
				set_value_int(&butler->butler_mtx, &butler->end_of_dinner, TRUE);
			}
			pos++;
		}
		
		
	}
	


}


void	greeting_philos(t_butler *butler)
{
	int	i;

	i = 0;
	if(butler->nbr_of_philos == 1)
	{
		//let the philo die
	}
	else if(butler->meals_to_eat  == 0)
		return;
	else
	{
		while(i < butler->nbr_of_philos)
		{
			//if(pthread_create(&butler->philos[i].thread, NULL, &dining, (void*)&butler->philos[i]) != 0)
			if(pthread_create(&butler->philos[i].thread, NULL, &dining, &butler->philos[i]) != 0)
			{
				printf("failed to create Philo[%i]\n",i + 1);
			}
			printf("Philo[%i] created\n",i + 1);
			i++;
		}
		//supervisor
		pthread_create(&butler->supervisor, NULL, &supervision, &butler);

		//get the time
		butler->start_time = get_time_in_ms();


		//all philos are ready to eat
		set_value_int(&butler->ready_mtx, &butler->all_philos_ready_to_eat, TRUE);

		//dining

		i = 0;
		while(i < butler->nbr_of_philos)
		{
			if(pthread_join(butler->philos[i].thread, NULL) != 0)
			{
				printf("failed to join Philo[%i]\n",i + 1);
			}
			printf("Philo[%i] joined\n",i + 1);
			i++;
		}
		//all philos are full
	}
}
