/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:50:30 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/25 17:51:55 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


void	wait_for_all(t_table *table)
{
	while(1)
	{
		if(get_value_int(&table->ready_flag_mtx, &table->ready_flag))
			break;
	}
}

void	supervisor_wait(t_table *table)
{
	while(1)
	{
		if(get_value_long(&table->wait_counter_mtx, &table->wait_counter) == table->nbr_of_philos)
			break;
	}
}

int	all_philos_done(t_table *table)
{
	int	i;
	int	done;

	i = 0;
	done = 0;

	while(i< table->nbr_of_philos && !dinner_finished(table))
	{
		if(get_value_int(&table->philos[i].thread_mtx, &table->philos[i].done))
			done++;
		if(done == table->nbr_of_philos)
			return(1);
		i++;
	}
	return(0);
}


void	increase_long(pthread_mutex_t *mtx, long	*number)
{
		mutex_handler(mtx, LOCK);
		*number +=1;
		mutex_handler(mtx, UNLOCK);
}
