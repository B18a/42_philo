/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:48:06 by ajehle            #+#    #+#             */
/*   Updated: 2024/08/07 09:43:34 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_status(t_table *table, t_philo *philo, t_status code)
{
	long	time_gone;

	mutex_handler(&philo->table->status_mtx, LOCK);
	time_gone = get_time_in_millis()
		- get_value_long(&philo->table->start_time_mtx,
			&philo->table->start_time);
	if (code == DIED)
		printf("%lu	%i died\n", time_gone, philo->thread_nbr);
	else if (code == EAT && !dinner_finished(table))
		printf("%lu	%i is eating\n", time_gone, philo->thread_nbr);
	else if (code == SLEEP && !dinner_finished(table))
		printf("%lu	%i is sleeping\n", time_gone, philo->thread_nbr);
	else if (code == THINK && !dinner_finished(table))
		printf("%lu	%i is thinking\n", time_gone, philo->thread_nbr);
	else if (code == TOOK_FIRST_FORK && !dinner_finished(table))
		printf("%lu	%i has taken a fork\n", time_gone, philo->thread_nbr);
	else if (code == TOOK_SEC_FORK && !dinner_finished(table))
		printf("%lu	%i has taken a fork\n", time_gone, philo->thread_nbr);
	mutex_handler(&philo->table->status_mtx, UNLOCK);
}
