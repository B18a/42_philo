/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:38:58 by ajehle            #+#    #+#             */
/*   Updated: 2024/08/07 10:35:19 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	assign_forks(t_philo *philo, t_fork *forks)
{
	int	nbr_of_philos;

	nbr_of_philos = philo->table->nbr_of_philos;
	if (philo->thread_nbr % 2 == 0)
	{
		philo->fork_first = &forks[philo->thread_nbr - 1];
		philo->fork_sec = &forks[philo->thread_nbr % nbr_of_philos];
	}
	else
	{
		philo->fork_first = &forks[philo->thread_nbr % nbr_of_philos];
		philo->fork_sec = &forks[philo->thread_nbr - 1];
	}
}

int	prep_philos(t_table *table)
{
	int	pos;

	pos = 0;
	while (pos < table->nbr_of_philos)
	{
		if (mutex_handler(&table->philos[pos].done_mtx, INIT))
			return (1);
		if (mutex_handler(&table->philos[pos].last_time_eaten_mtx, INIT))
			return (1);
		table->philos[pos].thread_nbr = pos + 1;
		table->philos[pos].done = FALSE;
		table->philos[pos].meals_eaten = 0;
		table->philos[pos].last_time_eaten = 0;
		table->philos[pos].table = table;
		table->philos[pos].nbr_of_philos = table->nbr_of_philos;
		table->philos[pos].tt_die = table->tt_die;
		table->philos[pos].tt_eat = table->tt_eat;
		table->philos[pos].tt_sleep = table->tt_sleep;
		table->philos[pos].meals_to_eat = table->meals_to_eat;
		assign_forks(&table->philos[pos], table->forks);
		pos++;
	}
	return (0);
}

int	prep_dinner(t_table *table)
{
	int	i;

	i = -1;
	if (mutex_handler(&table->end_of_dinner_mtx, INIT)
		|| mutex_handler(&table->ready_flag_mtx, INIT)
		|| mutex_handler(&table->start_time_mtx, INIT)
		|| mutex_handler(&table->status_mtx, INIT)
		|| mutex_handler(&table->wait_counter_mtx, INIT))
		return (1);
	table->philos = malloc(table->nbr_of_philos * sizeof(t_philo));
	if (table->philos == NULL)
		return (1);
	table->forks = malloc(table->nbr_of_philos * sizeof(t_fork));
	if (table->forks == NULL)
		return (1);
	while (++i < table->nbr_of_philos)
	{
		if (mutex_handler(&table->forks[i].fork_mtx, INIT))
			return (1);
		table->forks[i].fork_nbr = i;
	}
	table->wait_counter = FALSE;
	table->ready_flag = 0;
	table->end_of_dinner = FALSE;
	return (0);
}
