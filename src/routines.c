/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:48:00 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/31 11:28:44 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*single_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_for_all(philo->table);
	increase_long(&philo->table->wait_counter_mtx, &philo->table->wait_counter);
	print_status(philo->table, philo, TOOK_FIRST_FORK);
	while (!dinner_finished(philo->table))
	{
		usleep(500);
	}
	return (NULL);
}

void	*dining(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_for_all(philo->table);
	increase_long(&philo->table->wait_counter_mtx, &philo->table->wait_counter);
	if (philo->nbr_of_philos % 2 == 0)
	{
		if (philo->thread_nbr % 2 == 0)
			philo_think(philo);
	}
	else
	{
		if ((philo->thread_nbr % 2) == 1)
			philo_think(philo);
	}
	while (!dinner_finished(philo->table))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	*supervision(void *arg)
{
	int		i;
	t_table	*table;

	table = (t_table *)arg;
	supervisor_wait(table);
	while (!dinner_finished(table))
	{
		i = 0;
		while (i < table->nbr_of_philos && !dinner_finished(table))
		{
			if (philo_died(&table->philos[i]))
			{
				set_value_int(&table->end_of_dinner_mtx, TRUE,
					&table->end_of_dinner);
				print_status(table, &table->philos[i], DIED);

			}
			i++;
		}
		if (all_philos_done(table))
			set_value_int(&table->end_of_dinner_mtx, TRUE,
				&table->end_of_dinner);
		usleep(60);
	}
	return (NULL);
}
