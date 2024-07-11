
#include "../include/philo.h"

void	philo_eat(t_philo *philo)
{
	mutex_handler(&philo->fork_first->fork_mtx, LOCK);
	print_status(philo->butler, philo, TOOK_FIRST_FORK);
	mutex_handler(&philo->fork_second->fork_mtx, LOCK);
	print_status(philo->butler, philo, TOOK_SEC_FORK);

	set_value_long(&philo->philo_mtx, &philo->last_time_eaten, get_time_in_ms());
	philo->meals_eaten++;
	print_status(philo->butler, philo, EAT);
	better_usleep(philo->butler, philo->butler->tt_eat);
	if( philo->butler->meals_to_eat > 0 && philo->meals_eaten == philo->butler->meals_to_eat)
		set_value_int(&philo->philo_mtx, &philo->done, TRUE);
	mutex_handler(&philo->fork_first->fork_mtx, UNLOCK);
	mutex_handler(&philo->fork_second->fork_mtx, UNLOCK);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo->butler, philo, SLEEP);
	better_usleep(philo->butler, philo->butler->tt_sleep);
}

void	philo_think(t_philo *philo)
{
	print_status(philo->butler, philo, THINK);
}


int	philo_died(t_philo *philo)
{
	long	actual_time;
	long	left_to_die;

	if(get_value_int(&philo->philo_mtx, &philo->done));
		return(0);
	actual_time = get_time_in_ms();
	left_to_die = get_value_long(&philo->philo_mtx, &philo->last_time_eaten);
	if((actual_time - left_to_die) > philo->butler->tt_die)
	{
		print_status(philo->butler, philo, DIED);
		return(1);
	}
	return(0);
}
