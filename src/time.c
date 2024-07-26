/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:17:06 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/26 12:37:37 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//		get_time_in_millis
// time in sec * 1000	= time in ms
// time in usec / 1000	= time in ms
//						+
//----------------------------------
//	total time in ms	=
long	get_time_in_millis(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)(time.tv_sec * 1000L) + (long)(time.tv_usec / 1000L));
}

//		get_time_in_micros
// time in sec * 1000000	= time in us
// time in usec			= time in us
//						+
//----------------------------------
//	total time in us	=
long	get_time_in_micros(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)(time.tv_sec * 1000000L) + (long)time.tv_usec);
}

void	better_usleep(t_table *table, long tts_in_micros)
{
	long	start;
	long	time_gone;
	long	time_left;

	start = get_time_in_micros();
	if (start == -1)
		return ;
	else
	{
		while (get_time_in_micros() - start < tts_in_micros)
		{
			if (dinner_finished(table))
				break ;
			time_gone = get_time_in_micros() - start;
			time_left = tts_in_micros - time_gone;
			if (time_left > 1000)
				usleep(time_left / 2);
			else
				while (get_time_in_micros() - start < tts_in_micros)
					;
		}
		return ;
	}
}
