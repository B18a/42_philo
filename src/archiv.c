// void	print_status(t_table *table,t_philo *philo, t_status code)
// {
// 	long	time_gone;

// 	time_gone = get_time_in_millis() - table->start_time;
// 	mutex_handler(&philo->thread_mtx, LOCK);
// 	if(code == EAT && !dinner_finished(table))
// 	{
// 		if(DEBUG)
// 			printf(B"%lu	"RST B" %i is eating at 		[%lu]\n" RST, time_gone, philo->thread_nbr, philo->last_time_eaten);
// 		else
// 			printf("%lu	%i is eating\n", time_gone, philo->thread_nbr);
// 			// printf(B"%lu	"RST B" %i is eating\n" RST, time_gone, philo->thread_nbr);
// 	}
// 	else if(code == SLEEP && !dinner_finished(table))
// 	{
// 		if(DEBUG)
// 			printf(G"%lu	"RST G" %i is sleeping at 		[%lu]\n" RST, time_gone, philo->thread_nbr, philo->last_time_eaten + philo->table->tt_sleep/1000);
// 		else
// 			printf("%lu	%i is sleeping\n", time_gone, philo->thread_nbr);
// 			// printf(G"%lu	"RST G" %i is sleeping\n" RST, time_gone, philo->thread_nbr);
// 	}
// 	else if(code == THINK && !dinner_finished(table))
// 		printf("%lu	%i is thinking\n", time_gone, philo->thread_nbr);
// 		// printf(M"%lu	"RST M" %i is thinking\n" RST, time_gone, philo->thread_nbr);
// 	else if(code == DIED && !dinner_finished(table))
// 		printf("%lu	%i died\n", time_gone, philo->thread_nbr);
// 		// printf(RED"%lu	"RST RED" %i died\n" RST, time_gone, philo->thread_nbr);
// 	else if(code == TOOK_FIRST_FORK  && !dinner_finished(table))
// 	{
// 		if(DEBUG)
// 			printf(YEL"%lu	"RST YEL" %i has taken a fork	[%i]\n" RST, time_gone, philo->thread_nbr, philo->fork_first->fork_nbr);
// 		else
// 			printf("%lu	%i has taken a fork\n" , time_gone, philo->thread_nbr);
// 			// printf(YEL"%lu	"RST YEL" %i has taken a fork\n" RST, time_gone, philo->thread_nbr);
// 	}
// 	else if(code == TOOK_SEC_FORK && !dinner_finished(table))
// 	{
// 		if(DEBUG)
// 			printf(YEL"%lu	"RST YEL" %i has taken a fork	[%i]\n" RST, time_gone, philo->thread_nbr, philo->fork_sec->fork_nbr);
// 		else
// 			printf("%lu	%i has taken a fork\n", time_gone, philo->thread_nbr);
// 			// printf(YEL"%lu	"RST YEL" %i has taken a fork\n" RST, time_gone, philo->thread_nbr);
// 	}
// 	mutex_handler(&philo->thread_mtx, UNLOCK);
// }
