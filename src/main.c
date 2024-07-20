/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:05:12 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/19 10:35:46 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if(parsing_input(argc, argv, &table) == 1)
		return(0);
	if(prep_dinner(&table) == 1)
		return(free_allocs(&table), 0);
	greeting_philos(&table);
	free_allocs(&table);
}
