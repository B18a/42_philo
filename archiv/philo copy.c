#include "../include/philo.h"

void	ft_sleep(int t_in_s)
{
	usleep(t_in_s * 1000);
}


/*
int main(int argc, char **argv)
{
	struct		timeval start;
	struct		timeval end;
	
	if(argc != 4 || argc != 5)
		return(0);
//	for(int i = 0; i < 10; i++)
//	{
		gettimeofday(&start ,NULL);
		printf("%lu\n",start.tv_usec);
		printf("%lu\n",start.tv_sec);
		//ft_sleep(1);
		usleep(1000);
		gettimeofday(&end ,NULL);
		printf("%lu\n",end.tv_usec);
		printf("%lu\n",end.tv_sec);
		printf("time passed u_sec:[%lu]\n",((end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec)));
		printf("time passed m_sec:[%lu]\n",((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)));

//	}
}
*/



