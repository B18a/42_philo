#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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