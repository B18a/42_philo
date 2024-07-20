/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:08:35 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/20 14:40:48 by andreasjehl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eat(t_philo *philo)
{
	mutex_handler(&philo->fork_first->fork_mtx, LOCK);
	print_status(philo->table, philo, TOOK_FIRST_FORK);
	mutex_handler(&philo->fork_sec->fork_mtx, LOCK);
	print_status(philo->table, philo, TOOK_SEC_FORK);
	set_value_long(&philo->thread_mtx, get_time_in_millis(), &philo->last_time_eaten);
	philo->meals_eaten++;
	print_status(philo->table, philo, EAT);
	better_usleep(philo->table, philo->table->tt_eat);
	mutex_handler(&philo->fork_first->fork_mtx, UNLOCK);
	mutex_handler(&philo->fork_sec->fork_mtx, UNLOCK);
	if(philo->table->meals_to_eat > 0 && philo->meals_eaten == philo->table->meals_to_eat)
		set_value_int(&philo->thread_mtx, TRUE, &philo->done);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo->table, philo, SLEEP);
	better_usleep(philo->table, philo->table->tt_sleep);
}

void	philo_think(t_philo *philo)
{
	print_status(philo->table, philo, THINK);
	// usleep(1);
	better_usleep(philo->table, 10);
}

int	philo_died(t_philo *philo)
{

	long	timestamp_last_meal;
	long	timestamp_current;
	long	diff;

	timestamp_last_meal = get_value_long(&philo->thread_mtx, &philo->last_time_eaten);
	timestamp_current = get_time_in_millis();
	diff = timestamp_current - timestamp_last_meal;

	// printf("ID[%i] timestamp_last_meal	[%lu] timestamp_current [%lu] diff[%lu]\n",philo->thread_nbr,timestamp_last_meal, timestamp_current, diff);

	if(diff > philo->table->tt_die / 1000)
	{
		print_status(philo->table, philo, DIED);

		return(1);
	}
	return(0);
}
