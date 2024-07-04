

#include "../include/philo.h"


void *routine()
{

}


void	get_forks(t_philo *philo, t_fork *forks)
{
	int nbr_of_philos;
	
	nbr_of_philos = philo->supervisor->nbr_of_philos;
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




int	prep_philos(t_supervisor *supervisor)
{
	int	pos;

	pos = 0;
	while(pos < supervisor->nbr_of_philos)
	{
		supervisor->philos[pos].id = pos + 1 ;
		supervisor->philos[pos].meals_eaten = 0;
		supervisor->philos[pos].done = 0;
		//supervisor->philos[i].last_time_eaten = ?;
		supervisor->philos[pos].supervisor = supervisor;
		get_forks(&supervisor->philos[pos], supervisor->forks);
		pos++;
	}
}


int	prep_dinner(t_supervisor *supervisor)
{
	int	i;

	i = 0;
	supervisor->end_of_dinner = 0;
	supervisor->philos = (t_philo*)malloc(sizeof(t_philo) * supervisor->nbr_of_philos);
	if(!supervisor->philos)
		return(0);
	supervisor->forks = (t_fork*)malloc(sizeof(t_fork) * supervisor->nbr_of_philos);
	if(!supervisor->forks)
		return(0);
	while(i < supervisor->nbr_of_philos)
	{
		if(mutex_handler(&supervisor->forks[i].fork, INIT))
		{
			free_mem(supervisor);
			return(1);
		}
		supervisor->forks[i].fork_id = i; //only for debugging
		i++;
	}
	prep_philos(supervisor);
	return(0);
}

/*
	//supervisor->philos = malloc(sizeof(pthread_t) * supervisor->nbr_of_philos);
	while(i < supervisor->nbr_of_philos)
	{
		if(pthread_create(&supervisor->philos[i], NULL, &routine, NULL) != 0)
		{
			printf("failed to create Philo[%i]\n",i);
			return(0);
		}
		printf("Philo[%i] created\n",i);
		i++;
	}
	
	i = 0;
	while(i < supervisor->nbr_of_philos)
	{
		pthread_join(supervisor->philos[i], NULL);
		printf("Philo[%i] finished\n",i);
		i++;
	}
	return(1);
*/





int main(int argc, char **argv)
{
	t_supervisor supervisor;

	if(handle_input(argc, argv, &supervisor))
		return(0);
	if(prep_dinner(&supervisor) == 1)
		return(0);
	start_dinner(&supervisor);
	free_mem(&supervisor);
	return(1);
}



