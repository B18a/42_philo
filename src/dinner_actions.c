/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:08:35 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/25 20:31:44 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eat(t_philo *philo)
{
	mutex_handler(&philo->fork_first->fork_mtx, LOCK);
	print_status(philo->table, philo, TOOK_FIRST_FORK);
	mutex_handler(&philo->fork_sec->fork_mtx, LOCK);
	set_value_long(&philo->last_time_eaten_mtx, get_time_in_millis(), &philo->last_time_eaten);
	print_status(philo->table, philo, TOOK_SEC_FORK);
	print_status(philo->table, philo, EAT);

	/***********************************************/
	better_usleep(philo->table, philo->tt_eat);
	// if(!dinner_finished(philo->table))
	// 	other_usleep(philo->tt_eat);
	/***********************************************/

	philo->meals_eaten++;
	if(philo->meals_to_eat > 0 && philo->meals_eaten == philo->meals_to_eat)
		set_value_int(&philo->thread_mtx, TRUE, &philo->done);
	mutex_handler(&philo->fork_first->fork_mtx, UNLOCK);
	mutex_handler(&philo->fork_sec->fork_mtx, UNLOCK);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo->table, philo, SLEEP);

	/***********************************************/
	better_usleep(philo->table, philo->tt_sleep);
	// if(!dinner_finished(philo->table))
	// 	other_usleep(philo->tt_sleep);
	/***********************************************/
}

// void	philo_think(t_philo *philo)
// {
// 	long	tt_think;

// 	print_status(philo->table, philo, THINK);
// 		// usleep(50);
// 	if(philo->nbr_of_philos % 2 == 0)
// 		return;
// 	tt_think =  philo->tt_eat * 2 - philo->tt_sleep;
// 	if(tt_think < 0)
// 		tt_think = 0;
// 	usleep(tt_think * 0.42);
// 	other_usleep(tt_think * 0.42);
// }

void	philo_think(t_philo *philo)
{
	long	tt_think;

	print_status(philo->table, philo, THINK);
	tt_think = philo->tt_die - philo->tt_eat - philo->tt_sleep;
	if(tt_think < 0)
		tt_think = 0;
	better_usleep(philo->table, tt_think * 0.5);
}

int	philo_died(t_philo *philo)
{

	long	timestamp_last_meal;
	long	timestamp_current;
	long	diff;

	// timestamp_last_meal = get_value_long(&philo->thread_mtx, &philo->last_time_eaten);
	timestamp_last_meal = get_value_long(&philo->last_time_eaten_mtx, &philo->last_time_eaten);
	timestamp_current = get_time_in_millis();
	diff = timestamp_current - timestamp_last_meal;

	// printf("ID[%i] timestamp_last_meal	[%lu] timestamp_current [%lu] diff[%lu] tt_die[%lu]\n",philo->thread_nbr,timestamp_last_meal, timestamp_current, diff, philo->tt_die);

	if(diff > philo->tt_die)
	{
		print_status(philo->table, philo, DIED);
		return(1);
	}
	return(0);
}
