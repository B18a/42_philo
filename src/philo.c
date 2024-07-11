

#include "../include/philo.h"




void	get_forks(t_philo *philo, t_fork *forks)
{
	int nbr_of_philos;
	
	nbr_of_philos = philo->butler->nbr_of_philos;
	if(philo->id % 2)
	{
		philo->fork_first = &forks[philo->id - 1];
		philo->fork_second = &forks[philo->id % nbr_of_philos];
	}
	else
	{
		philo->fork_first = &forks[philo->id % nbr_of_philos];
		philo->fork_second = &forks[philo->id - 1];
	}
}




int	prep_philos(t_butler *butler)
{
	int	pos;

	pos = 0;
	while(pos < butler->nbr_of_philos)
	{
	if(mutex_handler(&butler->philos[pos].philo_mtx, INIT))
		return(1);
//return Value?
		butler->philos[pos].id = pos + 1 ;
		butler->philos[pos].meals_eaten = 0;
		butler->philos[pos].done = 0;
		//butler->philos[pos].last_time_eaten = 0;
		butler->philos[pos].butler = butler;
		get_forks(&butler->philos[pos], butler->forks);
		pos++;
	}
}


int	prep_dinner(t_butler *butler)
{
	int	i;

	i = 0;
	butler->end_of_dinner = FALSE;
	if(mutex_handler(&butler->ready_mtx, INIT))
		return(1);
	butler->philos = (t_philo*)malloc(sizeof(t_philo) * butler->nbr_of_philos);
	if(!butler->philos)
		return(0);
	butler->forks = (t_fork*)malloc(sizeof(t_fork) * butler->nbr_of_philos);
	if(!butler->forks)
		return(0);
	while(i < butler->nbr_of_philos)
	{
		if(mutex_handler(&butler->forks[i].fork_mtx, INIT))
		{
			free_mem(butler);
			return(1);
		}
		butler->forks[i].fork_id = i; //only for debugging
		i++;
	}
	prep_philos(butler);
	return(0);
}

/*
	//butler->philos = malloc(sizeof(pthread_t) * butler->nbr_of_philos);
	while(i < butler->nbr_of_philos)
	{
		if(pthread_create(&butler->philos[i], NULL, &routine, NULL) != 0)
		{
			printf("failed to create Philo[%i]\n",i);
			return(0);
		}
		printf("Philo[%i] created\n",i);
		i++;
	}
	
	i = 0;
	while(i < butler->nbr_of_philos)
	{
		pthread_join(butler->philos[i], NULL);
		printf("Philo[%i] finished\n",i);
		i++;
	}
	return(1);
*/





int main(int argc, char **argv)
{
	t_butler butler;

	if(handle_input(argc, argv, &butler))
		return(0);
	if(prep_dinner(&butler) == 1)
		return(0);
	greeting_philos(&butler);
	free_mem(&butler);
	return(1);
}



