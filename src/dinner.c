#include "../include/philo.h"


void	wait_for_all_philos(t_butler *butler)
{
	while(1)
	{
		if(get_value(&butler->ready_mtx, &butler->all_philos_ready_to_eat))
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
		// full
		if(philo->done)
			break;
		// eat
		// sleep
		// think

	}
	
	return(NULL);
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
				printf("failed to create Philo[%i]\n",i);
			}
			printf("Philo[%i] created\n",i);
			i++;
		}
		//get the time
		butler->start_time = get_time_in_ms();


		//all philos are ready to eat
		set_value(&butler->ready_mtx, &butler->all_philos_ready_to_eat, TRUE);

		//dining
		i = 0;
		while(i < butler->nbr_of_philos)
		{
			if(pthread_join(butler->philos[i].thread, NULL) != 0)
			{
				printf("failed to join Philo[%i]\n",i);
			}
			printf("Philo[%i] joined\n",i);
			i++;
		}
		//all philos are full
	}
}
