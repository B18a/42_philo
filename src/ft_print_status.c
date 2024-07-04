
#include "../include/philo.h"

void	print_fork(int timestamp, int nbr_of_philo)
{
	ft_printf("%i %i has taken a fork\n", timestamp, nbr_of_philo);
}

void	print_eat(int timestamp, int nbr_of_philo)
{
	ft_printf("%i %i is eating\n", timestamp, nbr_of_philo);
}

void	print_sleep(int timestamp, int nbr_of_philo)
{
	ft_printf("%i %i is sleeping\n", timestamp, nbr_of_philo);
}

void	print_think(int timestamp, int nbr_of_philo)
{
	ft_printf("%i %i is thinking\n", timestamp, nbr_of_philo);
}

void	print_die(int timestamp, int nbr_of_philo)
{
	ft_printf("%i %i dies\n", timestamp, nbr_of_philo);
}
