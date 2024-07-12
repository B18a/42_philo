#include "../include/philo.h"



long	get_time_in_millis(void)
{
	struct		timeval time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_sleep(int t_in_s)
{
	usleep(t_in_s * 1000);
}



int main(int argc, char **argv)
{
	struct		timeval time;
//	for(int i = 0; i < 10; i++)
//	{
		gettimeofday(&time ,NULL);
		printf("%lu\n",time.tv_usec);
		printf("%lu\n",time.tv_sec);
		printf("%lu\n",time.tv_sec + time.tv_usec);
		printf("[%f]\n",((time.tv_sec) + (time.tv_usec / 1e6)));
		//ft_sleep(1);
		//usleep(1000);
		//gettimeofday(&end ,NULL);
		//printf("%lu\n",end.tv_usec);
		//printf("%lu\n",end.tv_sec);
		//printf("time passed u_sec:[%lu]\n",((end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec)));
		//printf("time passed m_sec:[%lu]\n",((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)));

//	}
	return(0);
}




