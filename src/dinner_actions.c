
#include "../include/philo.h"

void	philo_eat(t_philo *philo)
{
	mutex_handler(&philo->fork_first->fork_mtx, LOCK);
	print_status(philo->butler, philo, TOOK_FIRST_FORK);
	mutex_handler(&philo->fork_second->fork_mtx, LOCK);
	print_status(philo->butler, philo, TOOK_SEC_FORK);




	mutex_handler(&philo->fork_first->fork_mtx, UNLOCK);
	mutex_handler(&philo->fork_second->fork_mtx, UNLOCK);
}

void	philo_sleep(t_philo *philo)
{

}

void	philo_think(t_philo *philo)
{

}
