/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:53:07 by ajehle            #+#    #+#             */
/*   Updated: 2024/08/07 09:55:34 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_allocs(t_table *table)
{
	if (table->philos)
	{
		free(table->philos);
		table->philos = NULL;
	}
	if (table->forks)
	{
		free(table->forks);
		table->forks = NULL;
	}
}
