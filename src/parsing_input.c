/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:25:00 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/19 16:04:01 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int		check_number(char *str)
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

int	check_argument(int argc, char **argv)
{
	int	i;

	i = 1;
	if(argc < 5 || argc > 6)
		return(1);
	while (i < argc)
	{
		if(check_number(argv[i]))
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
		// table->tt_die = ft_atol(argv[2]);
		// table->tt_eat = ft_atol(argv[3]);
		// table->tt_sleep = ft_atol(argv[4]);
		table->tt_die = ft_atol(argv[2]) * 1000;
		table->tt_eat = ft_atol(argv[3]) * 1000;
		table->tt_sleep = ft_atol(argv[4]) * 1000;
		if(argc == 6)
			table->meals_to_eat = ft_atoi(argv[5]);
		else
			table->meals_to_eat = -1;
		table->start_time = 0;
		table->end_of_dinner = FALSE;
		table->philos = NULL;
		table->forks = NULL;
		table->ready_counter = 0;
	}
}


int	validate_values(int argc, t_table *table)
{
	if(table->nbr_of_philos < PHILO_MIN || table->nbr_of_philos > PHILO_MAX)
		return(1);
	if(table->tt_die < TIME_MIN || table->tt_die > INT_MAX)
		return(1);
	if(table->tt_eat < TIME_MIN || table->tt_eat > INT_MAX)
		return(1);
	if(table->tt_sleep < TIME_MIN || table->tt_sleep > INT_MAX)
		return(1);
	if(argc == 6 && table->meals_to_eat <= 0)
		return(1);
	return(0);
}


int parsing_input(int argc, char **argv, t_table *table)
{
	if(check_argument(argc, argv))
	{
		printf("INVALID ARGUMENTS\n");
		return(1);
	}
	assign_values(argc, argv, table);
	if(validate_values(argc, table))
	{
		printf("INVALID ARGUMENTS\n");
		return(1);
	}
	return(0);
}
