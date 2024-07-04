#include "../include/philo.h"



void *routine()
{

}
void	start_dinner(t_butler *butler)
{
	int	i;

	i = 0;
	if(butler->nbr_of_philos == 1)
	{
		//let the philo die
	}
	else
	{
		while(i < butler->nbr_of_philos)
		{
			if(pthread_create(&butler->philos[i].philo, NULL, &routine, NULL) != 0)
			{
				printf("failed to create Philo[%i]\n",i);
			}
			printf("Philo[%i] created\n",i);
			i++;
		}
		i = 0;
		while(i < butler->nbr_of_philos)
		{
			if(pthread_join(butler->philos[i].philo, NULL) != 0)
			{
				printf("failed to join Philo[%i]\n",i);
			}
			printf("Philo[%i] joined\n",i);
			i++;
		}
	}
}