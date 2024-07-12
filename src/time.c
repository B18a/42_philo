
#include "../include/philo.h"



long	get_time_in_ms(void)
{
	struct	timeval time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}



void	better_usleep(t_table *table, long time_in_ms)
{
	struct	timeval current;
	struct	timeval start_sleep;
	long	time_gone;	

	if(dining_finished(table))	
		return;
	gettimeofday(&start_sleep, NULL);
	if(table->end_of_dinner)
		return;
	while(1)
	{
		gettimeofday(&current, NULL);
		time_gone = (current.tv_sec - start_sleep.tv_sec) * 1000000 + (current.tv_usec - start_sleep.tv_usec);
		if(time_gone >= time_in_ms)
			break;
		usleep(1);
	}
	return;
}