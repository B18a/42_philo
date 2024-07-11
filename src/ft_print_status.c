
#include "../include/philo.h"



void	print_status(t_butler *butler,t_philo *philo, t_status code)
{
	long	time_gone;

	time_gone = get_time_in_ms() - butler->start_time;
	mutex_handler(&philo->philo_mtx, LOCK);
	if(code == EAT && !dining_finished(butler))
		printf(C"%lu"RST"%i is eating\n", time_gone, philo->id);
	else if(code == SLEEP && !dining_finished(butler))
		printf(C"%lu"RST" %i is sleeping\n", time_gone, philo->id);
	else if(code == THINK && !dining_finished(butler))
		printf(C"%lu"RST" %i is thinking\n", time_gone, philo->id);
	else if(code == DIED && !dining_finished(butler))
		printf(C"%lu"RST" %i died\n", time_gone, philo->id);
	else if(code == TOOK_FIRST_FORK  && !dining_finished(butler))
		printf(C"%lu"RST" %i has taken a fork\n", time_gone, philo->id);
	else if(code == TOOK_SEC_FORK && !dining_finished(butler))
		printf(C"%lu"RST" %i has taken a fork\n", time_gone, philo->id);
	mutex_handler(&philo->philo_mtx, UNLOCK);

}	
