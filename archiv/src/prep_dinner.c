#include "../include/philo.h"



void	get_forks(t_philo *philo, t_fork *forks)
{
	int nbr_of_philos;
	
	nbr_of_philos = philo->table->nbr_of_philos;
	if(philo->id % 2 == 0)
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




int	prep_philos(t_table *table)
{
	int	pos;

	pos = 0;
	while(pos < table->nbr_of_philos)
	{
		if(mutex_handler(&table->philos[pos].philo_mtx, INIT))
			return(1);
//return Value?
		table->philos[pos].id = pos + 1 ;
		table->philos[pos].meals_eaten = 0;
		table->philos[pos].done = 0;
		//table->philos[pos].last_time_eaten = 0;
		table->philos[pos].table = table;
		get_forks(&table->philos[pos], table->forks);
		pos++;
	}
}


int	prep_dinner(t_table *table)
{
	int	i;

	i = 0;
	table->end_of_dinner = FALSE;
	if(mutex_handler(&table->end_of_dinner_mtx, INIT))
		return(1);
	if(mutex_handler(&table->all_philos_ready_to_eat_mtx, INIT))
		return(1);
	table->philos = (t_philo*)malloc(sizeof(t_philo) * table->nbr_of_philos);
	if(!table->philos)
		return(0);
	table->forks = (t_fork*)malloc(sizeof(t_fork) * table->nbr_of_philos);
	if(!table->forks)
		return(0);
	while(i < table->nbr_of_philos)
	{
		if(mutex_handler(&table->forks[i].fork_mtx, INIT))
		{
			free_mem(table);
			return(1);
		}
		table->forks[i].fork_id = i; //only for debugging
		i++;
	}
	prep_philos(table);
	return(0);
}
