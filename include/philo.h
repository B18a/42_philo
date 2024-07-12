//HEADER is missing



#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdint.h>
#include <limits.h>

#ifndef PHILO_H
 #define PHILO_H

# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define G	"\033[1;32m"
# define Y	"\033[1;33m"
# define B	"\033[1;34m"
# define M	"\033[1;35m"
# define C	"\033[1;36m"
# define W	"\033[1;37m"

# define TRUE 1
# define FALSE 0

# define DEBUG 1

typedef enum	e_status
{
	TOOK_FIRST_FORK,
	TOOK_SEC_FORK,
	EAT,
	SLEEP,
	THINK,
	DIED,
}			t_status;

typedef enum	e_mutex
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
}			t_mutex;

typedef enum	e_thread
{
	CREATE,
	JOIN,
	DETACH,
}			t_thread;

typedef enum	e_time
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}			t_time;


typedef	struct s_table t_table;
typedef	struct s_fork t_fork;
typedef	struct s_philo t_philo;


typedef	struct s_fork
{
	pthread_mutex_t	fork_mtx;
	int				fork_id;
}			t_fork;


typedef struct	s_philo
{
	pthread_t		thread;
	pthread_mutex_t	philo_mtx;
	
	t_fork	*fork_first;
	t_fork	*fork_second;
	
	int		id;
	int		meals_eaten;
	int		done;
	long	last_time_eaten;

	t_table	*table;

//	int	is_alive;
}		t_philo;

typedef struct	s_table
{
	int				nbr_of_philos;
	long			tt_die;
	long			tt_eat;
	long			tt_sleep;
	long			start_time;
	int				meals_to_eat;
	int				end_of_dinner;
	pthread_mutex_t	end_of_dinner_mtx;
	int				all_philos_ready_to_eat;
	pthread_mutex_t	all_philos_ready_to_eat_mtx;
	pthread_t		butler;
	t_philo			*philos;
	t_fork			*forks;
}				t_table;

//[nbr_of_philos][tt_die][tt_eat][tt_sleep ][meals_to_eat]

//ft_free
void	free_mem(t_table *table);

//handle_input
int		check_argument(char *str);
int		check_input(int argc, char **argv);
void	assign_values(int argc, char **argv, t_table *table);
int		validate_values(int argc, char **argv, t_table *table);
int		handle_input(int argc, char **argv, t_table *table);


//libft
int		ft_isdigit(int c);
int		ft_atoi(const char *str);


//handler
int		mutex_handler(pthread_mutex_t *mutex, t_mutex code);
int		thread_handler(pthread_t *thread, void *(*foo)(void *), void *data, t_thread code);

//dinner
void	greeting_philos(t_table *table);

void	set_value_long(pthread_mutex_t *mutex,long *dst ,long value);
long	get_value_long(pthread_mutex_t *mutex,long *dst);
void	set_value_int(pthread_mutex_t *mutex,int *dst ,int value);
int		get_value_int(pthread_mutex_t *mutex,int *dst);
int		dinner_finished(t_table *table);


long	get_time_in_millis(void);
long	get_time_in_micros(void);
void	better_usleep(t_table *table, long time_in_micros);


void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
int		philo_died(t_philo *philo);

void	print_status(t_table *table,t_philo *philo, t_status code);

void	*butler_handling(void *arg);

#endif