#include <libc.h>

struct						s_philo_status
{
	int						dead_count;
	int						completed_count;
};
typedef struct s_philo
{
	pthread_t				philo_t;
	int						philo_id;
	int						max_eat_count;
	suseconds_t				time_to_die;
	suseconds_t				time_to_eat;
	suseconds_t				time_to_sleep;
	pthread_mutex_t			***fork_arr;
	suseconds_t				t_last_eat;
	int						eat_count;
	struct s_philo_status	*status;
}							t_s_philo;

int							ft_isdigit(int c);
int							ft_atoi(const char *string);
int							get_forks(t_s_philo *philo);
int							release_forks(t_s_philo *philo);
pthread_mutex_t				**find_forks(t_s_philo *philo);
void						log_state(t_s_philo *philo, char *s);
void						eat_philo(t_s_philo *philo);
void						sleep_philo(t_s_philo *philo);
void						think_philo(t_s_philo *philo);
int							check_health(t_s_philo *philo);