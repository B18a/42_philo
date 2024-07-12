#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdint.h>
#include <limits.h>


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
	//struct	timeval current;
	//struct	timeval start_usleep;
	
	long	start;	
	long	current;	
	long	time_gone;	

	start = 0;
	current = 0;
	time_gone = 0;
	start = get_time_in_micros();

	printf("start of usleep %lu\n", start);
	while(1)
	{
		printf("%lu\n", time_gone);
		current = get_time_in_micros();
		time_gone = current - start;
		if(time_gone > time_in_micros)
			break;
		usleep(1);
	}
	return;
}



int main(void)
{
	better_usleep(5 * 1000);
}