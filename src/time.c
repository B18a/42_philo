
#include "../include/philo.h"



long	get_time_in_ms(void)
{
	struct	timeval time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}



void	better_usleep(t_butler *butler, long time_in_ms)
{
	struct	timeval current;
	struct	timeval start_sleep;
	long	elapsed;	

	if(dining_finished(butler))	
		return;
	gettimeofday(&start_sleep, NULL);
	if(butler->end_of_dinner)
		return;
	while(1)
	{
		gettimeofday(&current, NULL);
		elapsed = (current.tv_sec - start_sleep.tv_sec) * 1000000 + (current.tv_usec - start_sleep.tv_usec);
		if(elapsed >= time_in_ms)
			break;
		usleep(1);
	}
	return;
}