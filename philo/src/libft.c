/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:34:09 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/18 09:42:33 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atol(const char *str)
{
	long	nbr;
	long	pre;

	nbr = 0;
	pre = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pre = pre * (-1);
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		nbr = nbr * 10;
		nbr = nbr + (*str - 48);
		str++;
	}
	return (pre * nbr);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	long	pre;

	nbr = 0;
	pre = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pre = pre * (-1);
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		nbr = nbr * 10;
		nbr = nbr + (*str - 48);
		str++;
	}
	return (pre * nbr);
}
