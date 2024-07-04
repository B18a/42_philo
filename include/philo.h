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
# define R	"\033[1;31m"
# define G	"\033[1;32m"
# define Y	"\033[1;33m"
# define B	"\033[1;34m"
# define M	"\033[1;35m"
# define C	"\033[1;36m"
# define W	"\033[1;37m"


# define TRUE 1
# define FALSE 0

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

typedef	struct s_butler t_butler;
typedef	struct s_fork t_fork;
typedef	struct s_philo t_philo;


typedef	struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
	//pthread_mutex_t	*left_fork;
	//pthread_mutex_t	right_fork;
}			t_fork;


typedef struct	s_philo
{
	pthread_t	philo;
	
	t_fork	*fork_first;
	t_fork	*fork_second;
	
	int		id;
	int		meals_eaten;
	int		done;
	long	last_time_eaten;

	t_butler	*butler;

//	struct t_philo	*prev;
//	struct t_philo	*next;

//	int	is_alive;
}		t_philo;

typedef struct	s_butler
{
	int		nbr_of_philos;
	int		tt_die;
	int		tt_eat;
	int		tt_sleep;
	int		meals_to_eat;
	long	start_time;
	int		end_of_dinner;
	t_philo		*philos;
	t_fork		*forks;

}				t_butler;

//ft_free
void	free_mem(t_butler *butler);

//handle_input
int		check_argument(char *str);
int		check_input(int argc, char **argv);
void	assign_values(int argc, char **argv, t_butler *butler);
int		validate_values(int argc, char **argv, t_butler *butler);
int		handle_input(int argc, char **argv, t_butler *butler);


//libft
int		ft_isdigit(int c);
int		ft_atoi(const char *str);


//handler
int		mutex_handler(pthread_mutex_t *mutex, t_mutex code);
int		thread_handler(pthread_t *thread, void *(*foo)(void *), void *data, t_thread code);

//dinner
void	start_dinner(t_butler *butler);


#endif