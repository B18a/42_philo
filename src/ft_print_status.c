
#include "../include/philo.h"



void	print_status_funny(t_table *table,t_philo *philo, t_status code)
{
	long	time_gone;

	time_gone = get_time_in_millis() - table->start_time;
	mutex_handler(&philo->philo_mtx, LOCK);
	if(code == EAT && !dinner_finished(table))
		printf(C"%lu	"RST B" Philo %i 🥘 is eating meal nbr	%i\n" RST, time_gone, philo->id, philo->meals_eaten);
	else if(code == SLEEP && !dinner_finished(table))
		printf(C"%lu	"RST G" Philo %i 💤 is sleeping\n" RST, time_gone, philo->id);
	else if(code == THINK && !dinner_finished(table))
		printf(C"%lu	"RST" Philo %i 🤔 is thinking\n", time_gone, philo->id);
	else if(code == DIED && !dinner_finished(table))
		printf(RED"%lu	"RST" Philo %i 💀 died\n", time_gone, philo->id);
	else if(code == TOOK_FIRST_FORK  && !dinner_finished(table))
		printf(C"%lu	"RST	Y" Philo %i 🍴 has taken a fork		%i\n"RST, time_gone, philo->id, philo->fork_first->fork_id);
	else if(code == TOOK_SEC_FORK && !dinner_finished(table))
		printf(C"%lu	"RST	Y" Philo %i 🍴 has taken a fork		%i\n"RST, time_gone, philo->id, philo->fork_second->fork_id);
	mutex_handler(&philo->philo_mtx, UNLOCK);
}



void	print_status(t_table *table,t_philo *philo, t_status code)
{
	//DEBUG needs to be removed for eval!!!!
	if(DEBUG)
	{
		print_status_funny(table, philo,code);
		return;
	}
	long	time_gone;
	if(philo->done)
		return;
//	if(get_value_int(&philo->philo_mtx, &philo->done));
//		return;
	time_gone = get_time_in_millis() - table->start_time;
	mutex_handler(&philo->philo_mtx, LOCK);
	if(code == EAT && !dinner_finished(table))
		printf(C"%lu	"RST B" %i is eating\n" RST, time_gone, philo->id);
	else if(code == SLEEP && !dinner_finished(table))
		printf(C"%lu	"RST G" %i is sleeping\n" RST, time_gone, philo->id);
	else if(code == THINK && !dinner_finished(table))
		printf(C"%lu	"RST" %i is thinking\n", time_gone, philo->id);
	else if(code == DIED && !dinner_finished(table))
		printf(RED"%lu	"RST" %i died\n", time_gone, philo->id);
	else if(code == TOOK_FIRST_FORK  && !dinner_finished(table))
		printf(C"%lu	"RST" %i has taken a fork\n", time_gone, philo->id);
	else if(code == TOOK_SEC_FORK && !dinner_finished(table))
		printf(C"%lu	"RST" %i has taken a fork\n", time_gone, philo->id);
	mutex_handler(&philo->philo_mtx, UNLOCK);
}	
