/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:05:19 by ajehle            #+#    #+#             */
/*   Updated: 2024/07/25 17:50:58 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
 #define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdint.h>
#include <limits.h>

# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define G		"\033[1;32m"
# define YEL	"\033[1;33m"
# define B		"\033[1;34m"
# define M		"\033[1;35m"
# define C		"\033[1;36m"
# define W		"\033[1;37m"

# define PHILO_MIN 1
# define PHILO_MAX 200
# define TIME_MIN 60
// # define TIME_MIN 60

# define TRUE 1
# define FALSE 0

# define DEBUG 0

typedef struct s_table t_table;
typedef struct s_philo t_philo;
typedef struct s_fork t_fork;

typedef struct s_fork
{
	pthread_mutex_t	fork_mtx;
	int				fork_nbr;
} 				t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	thread_mtx;
	int				thread_nbr;
	int				done;
	long			meals_eaten;
	pthread_mutex_t	last_time_eaten_mtx;
	long			last_time_eaten;
	t_table			*table;
	t_fork			*fork_first;
	t_fork			*fork_sec;
	long			nbr_of_philos;
	long			tt_die;
	long			tt_eat;
	long			tt_sleep;
	int				meals_to_eat;
}					t_philo;

typedef struct s_table
{
	long			nbr_of_philos;
	long			tt_die;
	long			tt_eat;
	long			tt_sleep;
	int				meals_to_eat;
	pthread_mutex_t	status_mtx;
	pthread_mutex_t	start_time_mtx;
	long			start_time;
	pthread_mutex_t	end_of_dinner_mtx;
	int				end_of_dinner;
	pthread_mutex_t	ready_flag_mtx;
	int				ready_flag;
	pthread_mutex_t	wait_counter_mtx;
	long			wait_counter;
	t_philo			*philos;
	t_fork			*forks;
	pthread_t		thread_butler;
}					t_table;

//[nbr_of_philos][tt_die][tt_eat][tt_sleep ][meals_to_eat]

typedef enum s_mutex
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
}			t_mutex;

typedef enum s_thread
{
	CREATE,
	JOIN,
	DETACH,
}			t_thread;

typedef enum	e_status
{
	TOOK_FIRST_FORK,
	TOOK_SEC_FORK,
	EAT,
	SLEEP,
	THINK,
	DIED,
}			t_status;

//handle input
int 	parsing_input(int argc, char **argv, t_table *table);
int		validate_values(int argc, t_table *table);
void	assign_values(int argc, char **argv, t_table *table);
int		check_argument(int argc, char **argv);
int		check_number(char *str);

//libft functions
int	ft_isdigit(int c);
//check!!!!!!!!!
int	ft_atol(const char *str);
int	ft_atoi(const char *str);

//handler
int	mutex_handler(pthread_mutex_t *mutex, t_mutex code);
int	thread_handler(pthread_t *thread, void*(*routine)(void*), void *arg, t_thread code);

//preping
void	assign_forks(t_philo *philo, t_fork *forks);
int		prep_philos(t_table *table);
int		prep_dinner(t_table *table);

// the dinner

void	greeting_philos(t_table *table);
void	end_of_dinner(t_table *table);

// set and get
int		get_value_int(pthread_mutex_t *mutex, int *value);
void	set_value_int(pthread_mutex_t *mutex, int value, int *dest);
long	get_value_long(pthread_mutex_t *mutex, long *value);
void	set_value_long(pthread_mutex_t *mutex, long value, long *dest);
int		dinner_finished(t_table *table);

// time		sek/milli/micro
long	get_time_in_millis(void);
long	get_time_in_micros(void);
void	better_usleep(t_table *table, long tts_in_micros);
void	other_usleep(long tts_in_micros);

// free_mem
void free_allocs(t_table *table);

// status
void	print_status(t_table *table,t_philo *philo, t_status code);

// dinner actions
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
int		philo_died(t_philo *philo);

// the dinner
void	wait_for_all(t_table *table);
void	supervisor_wait(t_table *table);
int	all_philos_done(t_table *table);


// routines
void	*dining(void* arg);
void	*supervision(void* arg);
void	*single_philo(void *arg);

// utils
void	wait_for_all(t_table *table);
void	supervisor_wait(t_table *table);
int		all_philos_done(t_table *table);
void	increase_long(pthread_mutex_t *mtx, long *number);

#endif
