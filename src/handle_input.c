

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

void	assign_values(int argc, char **argv, t_butler *butler)
{
	if(butler)
	{
		butler->nbr_of_philos = ft_atoi(argv[1]);
		butler->tt_die = ft_atoi(argv[2]);
		butler->tt_eat = ft_atoi(argv[3]);
		butler->tt_sleep = ft_atoi(argv[4]);
		if(argc == 6)
			butler->meals_to_eat = ft_atoi(argv[5]);
		else 
			butler->meals_to_eat = -1;
		butler->start_time = 0;
		butler->end_of_dinner = FALSE;
		butler->philos = NULL;
		butler->forks= NULL;
	}
}

int	validate_values(int argc, char **argv, t_butler *butler)
{
	if(butler->nbr_of_philos < 0 || butler->nbr_of_philos > 200)
		return(1);
	if(butler->tt_die < 60 || butler->tt_die > INT_MAX)
		return(1);
	if(butler->tt_eat < 60 || butler->tt_eat > INT_MAX)
		return(1);
	if(butler->tt_sleep < 60 || butler->tt_sleep > INT_MAX)
		return(1);
	if(argc == 6 && butler->meals_to_eat <= 0)
		return(1);
	return(0);
}

int handle_input(int argc, char **argv, t_butler *butler)
{
	if(check_input(argc, argv))
	{
		//free_mem(butler);
		printf("Invalid Input\n");
		return(1);
	}
	assign_values(argc, argv, butler);
	if(validate_values(argc, argv, butler))
	{
		//free_mem(butler);
		printf("Invalid Values\n");
		return(1);
	}
	return(0);
}
