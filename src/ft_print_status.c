
#include "../include/philo.h"



void	print_status_funny(t_table *table,t_philo *philo, t_status code)
{
	long	time_gone;

	time_gone = get_time_in_ms() - table->start_time;
	mutex_handler(&philo->philo_mtx, LOCK);
	if(code == EAT && !dining_finished(table))
		printf(C"%lu"RST" Philo %i 🥘 is eating\n", time_gone, philo->id);
	else if(code == SLEEP && !dining_finished(table))
		printf(C"%lu"RST" Philo %i 💤 is sleeping\n", time_gone, philo->id);
	else if(code == THINK && !dining_finished(table))
		printf(C"%lu"RST" Philo %i 🤔 is thinking\n", time_gone, philo->id);
	else if(code == DIED && !dining_finished(table))
		printf(RED"%lu"RST" Philo %i 💀 died\n", time_gone, philo->id);
	else if(code == TOOK_FIRST_FORK  && !dining_finished(table))
		printf(C"%lu"RST" Philo %i 🍴 has taken a fork %i\n", time_gone, philo->id, philo->fork_first->fork_id);
	else if(code == TOOK_SEC_FORK && !dining_finished(table))
		printf(C"%lu"RST" Philo %i 🍴 has taken a fork %i\n", time_gone, philo->id, philo->fork_second->fork_id);
	mutex_handler(&philo->philo_mtx, UNLOCK);
}



void	print_status(t_table *table,t_philo *philo, t_status code)
{
	if(DEBUG)
	{
		print_status_funny(table, philo,code);
		return;
	}
	long	time_gone;

	time_gone = get_time_in_ms() - table->start_time;
	mutex_handler(&philo->philo_mtx, LOCK);
	if(code == EAT && !dining_finished(table))
		printf(C"%lu"RST" %i is eating\n", time_gone, philo->id);
	else if(code == SLEEP && !dining_finished(table))
		printf(C"%lu"RST" %i is sleeping\n", time_gone, philo->id);
	else if(code == THINK && !dining_finished(table))
		printf(C"%lu"RST" %i is thinking\n", time_gone, philo->id);
	else if(code == DIED && !dining_finished(table))
		printf(RED"%lu"RST" %i died\n", time_gone, philo->id);
	else if(code == TOOK_FIRST_FORK  && !dining_finished(table))
		printf(C"%lu"RST" %i has taken a fork\n", time_gone, philo->id);
	else if(code == TOOK_SEC_FORK && !dining_finished(table))
		printf(C"%lu"RST" %i has taken a fork\n", time_gone, philo->id);
	mutex_handler(&philo->philo_mtx, UNLOCK);
}	
