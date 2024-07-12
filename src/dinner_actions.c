
#include "../include/philo.h"

void	philo_eat(t_philo *philo)
{
	mutex_handler(&philo->fork_first->fork_mtx, LOCK);
	print_status(philo->table, philo, TOOK_FIRST_FORK);
	mutex_handler(&philo->fork_second->fork_mtx, LOCK);
	print_status(philo->table, philo, TOOK_SEC_FORK);

	set_value_long(&philo->philo_mtx, &philo->last_time_eaten, get_time_in_millis());
	philo->meals_eaten++;
	print_status(philo->table, philo, EAT);
	better_usleep(philo->table, philo->table->tt_eat);
	if( philo->table->meals_to_eat > 0 && philo->meals_eaten == philo->table->meals_to_eat)
		set_value_int(&philo->philo_mtx, &philo->done, TRUE);
	mutex_handler(&philo->fork_first->fork_mtx, UNLOCK);
	mutex_handler(&philo->fork_second->fork_mtx, UNLOCK);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo->table, philo, SLEEP);
	better_usleep(philo->table, philo->table->tt_sleep);
}

void	philo_think(t_philo *philo)
{
	print_status(philo->table, philo, THINK);
}


int	philo_died(t_philo *philo)
{
	long	actual_time;
	long	left_to_die;

	if(get_value_int(&philo->philo_mtx, &philo->done));
		return(0);
	actual_time = get_time_in_millis();
	left_to_die = get_value_long(&philo->philo_mtx, &philo->last_time_eaten);
	if((actual_time - left_to_die) > philo->table->tt_die)
	{
		print_status(philo->table, philo, DIED);
		return(1);
	}
	return(0);
}
