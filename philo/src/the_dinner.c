/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:31:18 by ajehle            #+#    #+#             */
/*   Updated: 2024/08/07 11:34:26 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	end_of_dinner(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		thread_handler(&table->philos[i].thread, NULL, NULL, JOIN);
		i++;
	}
	thread_handler(&table->thread_butler, NULL, NULL, JOIN);
	i = 0;
	while (i < table->nbr_of_philos)
	{
		mutex_handler(&table->philos[i].done_mtx, DESTROY);
		mutex_handler(&table->forks[i].fork_mtx, DESTROY);
		i++;
	}
	mutex_handler(&table->end_of_dinner_mtx, DESTROY);
	mutex_handler(&table->ready_flag_mtx, DESTROY);
	mutex_handler(&table->wait_counter_mtx, DESTROY);
	mutex_handler(&table->start_time_mtx, DESTROY);
	free_allocs(table);
}

void	set_time(t_table *table)
{
	int		i;
	long	time;

	i = 0;
	time = get_time_in_millis();
	set_value_long(&table->start_time_mtx, time, &table->start_time);
	while (i < table->nbr_of_philos)
	{
		set_value_long(&table->philos[i].last_time_eaten_mtx, time,
			&table->philos[i].last_time_eaten);
		i++;
	}
}

void	greeting_philos(t_table *table)
{
	int	i;

	i = 0;
	if (table->nbr_of_philos == 1)
	{
		set_time(table);
		thread_handler(&table->philos[0].thread, single_philo,
			(void *)&table->philos[0], CREATE);
	}
	else
	{
		while (i < table->nbr_of_philos)
		{
			set_time(table);
			thread_handler(&table->philos[i].thread, dining,
				(void *)&table->philos[i], CREATE);
			i++;
			usleep(60);
		}
	}
	thread_handler(&table->thread_butler, supervision, table, CREATE);
	set_value_int(&table->ready_flag_mtx, TRUE, &table->ready_flag);
}
