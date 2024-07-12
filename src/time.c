
#include "../include/philo.h"



long	get_time_in_millis(void)
{
	struct	timeval time;

	gettimeofday(&time, NULL);
	//time in sec * 1000	= time in ms
	//time in usec / 1000	= time in ms
	//						+
	//----------------------------------
	//	total time in ms	= 
	return((time.tv_sec * 1000) + (time.tv_usec / 1000)); 
}

long	get_time_in_micros(void)
{
	struct	timeval time;

	gettimeofday(&time, NULL);
	//time in sec * 1000000	= time in us
	//time in usec			= time in us
	//						+
	//----------------------------------
	//	total time in us	= 
	return((time.tv_sec * 1000000) + time.tv_usec); 
}


void	better_usleep(t_table *table, long time_in_ms)
{
	struct	timeval current;
	struct	timeval start_usleep;
	long	time_gone;	

	if(dining_finished(table))	
		return;
	gettimeofday(&start_usleep, NULL);
	if(table->end_of_dinner)
		return;
	while(1)
	{
		gettimeofday(&current, NULL);
		time_gone = (current.tv_sec - start_usleep.tv_sec) * 1000000 + (current.tv_usec - start_usleep.tv_usec);
		if(time_gone >= time_in_ms)
			break;
		usleep(1);
	}
	return;
}