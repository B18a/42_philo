

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

void	assign_values(int argc, char **argv, t_table *table)
{
	if(table)
	{
		table->nbr_of_philos = ft_atoi(argv[1]);
		table->tt_die = ft_atoi(argv[2]) * 1000;
		table->tt_eat = ft_atoi(argv[3]) * 1000;
		table->tt_sleep = ft_atoi(argv[4]) * 1000;
		if(argc == 6)
			table->meals_to_eat = ft_atoi(argv[5]);
		else 
			table->meals_to_eat = -1;
		table->start_time = 0;
		table->end_of_dinner = FALSE;
		table->all_philos_ready_to_eat = FALSE;
		table->philos = NULL;
		table->forks= NULL;
	}
}

int	validate_values(int argc, char **argv, t_table *table)
{
	if(table->nbr_of_philos < 0 || table->nbr_of_philos > 200)
		return(1);
	if(table->tt_die < 60 * 1000 || table->tt_die > INT_MAX)
		return(1);
	if(table->tt_eat < 60 * 1000 || table->tt_eat > INT_MAX)
		return(1);
	if(table->tt_sleep < 60 * 1000 || table->tt_sleep > INT_MAX)
		return(1);
	if(argc == 6 && table->meals_to_eat <= 0)
		return(1);
	return(0);
}

int handle_input(int argc, char **argv, t_table *table)
{
	if(check_input(argc, argv))
	{
		printf("Invalid Input\n");
		return(1);
	}
	assign_values(argc, argv, table);
	if(validate_values(argc, argv, table))
	{
		printf("Invalid Values\n");
		return(1);
	}
	return(0);
}
