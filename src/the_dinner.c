/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:31:18 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/20 14:54:26 by andreasjehl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_for_all(t_table *table)
{
	while(1)
	{
		if(get_value_int(&table->ready_counter_mtx, &table->ready_counter) == table->nbr_of_philos)
			break;
	}
}




void	*dining(void* arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	increase_int(&philo->table->ready_counter_mtx, &philo->table->ready_counter);
	set_value_long(&philo->thread_mtx, get_time_in_millis(), &philo->last_time_eaten);
	wait_for_all(philo->table);
	if(philo->thread_nbr % 2 == 1) // needed for uneven nbr of philos otherwise one will die in the beginning
		usleep(100);
	while (!dinner_finished(philo->table))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return(NULL);
}

void	end_of_dinner(t_table *table)
{
	int	i;

	i = 0;
	while(i < table->nbr_of_philos)
	{
		thread_handler(&table->philos[i].thread, NULL, NULL, JOIN);
		i++;
	}
	thread_handler(&table->thread, NULL, NULL, JOIN);
}

int	all_philos_done(t_table *table)
{
	int	i;
	int	done;

	i = 0;
	done = 0;

	while(i< table->nbr_of_philos)
	{
		if(get_value_int(&table->philos[i].thread_mtx, &table->philos[i].done))
			done++;
		if(done == table->nbr_of_philos)
			return(1);
		i++;
	}
	return(0);
}

void	*supervision(void* arg)
{
	int	i;
	t_table	*table;

	table = (t_table*)arg;
	wait_for_all(table);
	while(!dinner_finished(table))
	{
		i = 0;
		while(i < table->nbr_of_philos)
		{
			if(all_philos_done(table))
				set_value_int(&table->end_of_dinner_mtx, TRUE,&table->end_of_dinner);
			if(philo_died(&table->philos[i]))
				set_value_int(&table->end_of_dinner_mtx, TRUE, &table->end_of_dinner);
			i++;
			better_usleep(table, 10);
		}
	}
	return(NULL);
}

void *single_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	increase_int(&philo->table->ready_counter_mtx, &philo->table->ready_counter);
	set_value_long(&philo->thread_mtx, get_time_in_millis(), &philo->last_time_eaten);
	wait_for_all(philo->table);
	// if(philo->thread_nbr % 2 == 1) // needed for uneven nbr of philos otherwise one will die in the beginning
	// 	usleep(100);
	while (!dinner_finished(philo->table))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return(NULL);
}

void	greeting_philos(t_table *table)
{
	int	i;

	i = 0;
	if(table->nbr_of_philos == 1)
	{
		// let the philo die ?!?!?!??!??!
		thread_handler(&table->philos[0].thread, single_philo, (void*)&table->philos[0], CREATE);
				
		printf("Threat created\n");

		// thread_handler(&table->philos[0].thread, NULL, NULL, JOIN);
		// printf("Threat joined\n");


	}
	else
	{
		while(i < table->nbr_of_philos)
		{
			thread_handler(&table->philos[i].thread, dining, (void*)&table->philos[i], CREATE);
			i++;
		}
	}
	table->start_time = get_time_in_millis();
	thread_handler(&table->thread, supervision, table, CREATE);
	end_of_dinner(table);
}
