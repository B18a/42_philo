

#include "../include/philo.h"



int main(int argc, char **argv)
{
	t_table table;

	if(handle_input(argc, argv, &table))
		return(0);
	if(prep_dinner(&table) == 1)
		return(0);
	greeting_philos(&table);
//	free_mem(&table);
	return(1);
}
