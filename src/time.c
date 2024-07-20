/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:17:06 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/20 10:40:23 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//		get_time_in_millis
	//time in sec * 1000	= time in ms
	//time in usec / 1000	= time in ms
	//						+
	//----------------------------------
	//	total time in ms	=
long	get_time_in_millis(void)
{
	struct	timeval time;

	gettimeofday(&time, NULL);

	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}



//		get_time_in_micros
	//time in sec * 1000000	= time in us
	//time in usec			= time in us
	//						+
	//----------------------------------
	//	total time in us	=
long	get_time_in_micros(void)
{
	struct	timeval time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000000) + time.tv_usec);
}

void	better_usleep(t_table *table, long tts_in_micros)
{
	long	start;
	long	current;
	long	time_gone;

	start = get_time_in_micros();
	while(!dinner_finished(table))
	{
		current = get_time_in_micros();
		time_gone = current - start;
		if(time_gone > tts_in_micros)
			break;
		// usleep(1);
	}
}
