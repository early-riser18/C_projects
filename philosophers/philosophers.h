#include <libc.h>

typedef struct s_philo {
		pthread_t philo_t;
		int philo_id;
		suseconds_t time_to_die;
		suseconds_t time_to_eat;
		suseconds_t time_to_sleep;
		pthread_mutex_t ***fork_arr;

	}	t_s_philo ;

int	ft_isdigit(int c);
int	ft_atoi(const char *string);
int get_forks(t_s_philo *philo);
int release_forks(t_s_philo *philo);
pthread_mutex_t **find_forks(t_s_philo *philo);
