/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:28:28 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/18 14:15:30 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	mutex_handler(pthread_mutex_t *mutex, t_mutex code)
{
	if(INIT == code)
		return(pthread_mutex_init(mutex,NULL));
	else if(DESTROY == code)
		return(pthread_mutex_destroy(mutex));
	else if(LOCK == code)
		return(pthread_mutex_lock(mutex));
	else if(UNLOCK == code)
		return(pthread_mutex_unlock(mutex));
	return(1);
}

int	thread_handler(pthread_t *thread, void*(*routine)(void*), void *arg, t_thread code)
{
	if(CREATE == code)
		return(pthread_create(thread, NULL, routine, arg));
	else if(JOIN == code)
		return(pthread_join(*thread, NULL));
	else if(DETACH == code)
		return(pthread_detach(*thread));
	else
		return(1);
}
