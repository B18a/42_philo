
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


void	better_usleep(long time_in_micros)
{
	long	start;	
	long	current;	
	long	time_gone;	

	start = 0;
	current = 0;
	time_gone = 0;
	start = get_time_in_micros();
	while(1)
	{
		current = get_time_in_micros();
		time_gone = current - start;
		if(time_gone > time_in_micros)
			break;
		usleep(1);
	}
	return;
}