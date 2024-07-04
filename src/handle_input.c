

#include "../include/philo.h"

int	check_argument(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(ft_isdigit(str[i]) == 0)
			return(1);
		i++;
	}
	return(0);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if(argc < 5 || argc > 6)
		return(1);
	while(i < argc)
	{
		if(check_argument(argv[i]))
			return(1);
		i++;
	}
	return(0);
}

void	assign_values(int argc, char **argv, t_supervisor *supervisor)
{
	if(supervisor)
	{
		supervisor->nbr_of_philos = ft_atoi(argv[1]);
		supervisor->tt_die = ft_atoi(argv[2]);
		supervisor->tt_eat = ft_atoi(argv[3]);
		supervisor->tt_sleep = ft_atoi(argv[4]);
		if(argc == 6)
			supervisor->meals_to_eat = ft_atoi(argv[5]);
		else 
			supervisor->meals_to_eat = -1;
		supervisor->start_time = 0;
		supervisor->end_of_dinner = FALSE;
		supervisor->philos = NULL;
		supervisor->forks= NULL;
	}
}

int	validate_values(int argc, char **argv, t_supervisor *supervisor)
{
	if(supervisor->nbr_of_philos < 0 || supervisor->nbr_of_philos > 200)
		return(1);
	if(supervisor->tt_die < 60 || supervisor->tt_die > INT_MAX)
		return(1);
	if(supervisor->tt_eat < 60 || supervisor->tt_eat > INT_MAX)
		return(1);
	if(supervisor->tt_sleep < 60 || supervisor->tt_sleep > INT_MAX)
		return(1);
	if(argc == 6 && supervisor->meals_to_eat <= 0)
		return(1);
	return(0);
}

int handle_input(int argc, char **argv, t_supervisor *supervisor)
{
	if(check_input(argc, argv))
	{
		//free_mem(supervisor);
		printf("Invalid Input\n");
		return(1);
	}
	assign_values(argc, argv, supervisor);
	if(validate_values(argc, argv, supervisor))
	{
		//free_mem(supervisor);
		printf("Invalid Values\n");
		return(1);
	}
	return(0);
}
