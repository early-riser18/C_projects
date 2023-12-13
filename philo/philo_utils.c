#include "philo.h"
#include <libc.h>
#include <pthread.h>

int	ft_isdigit(int c)
{
	return (47 < c && c < 58);
}

int	ft_atoi(const char *string)
{
	char	sign;
	int		sum;
	int		i;

	sum = 0;
	sign = 1;
	i = 0;
	while (string[i] && !ft_isdigit(string[i]) && string[i] != '\e')
	{
		if (string[i] == '-')
		{
			sign *= -1;
			i++;
			break ;
		}
		else if (string[i] == '+')
		{
			i++;
			break ;
		}
		i++;
	}
	while (string[i] && ft_isdigit(string[i]))
	{
		sum = sum * 10 + string[i] - '0';
		i++;
	}
	return (sum * sign);
}

void	log_state(t_s_philo *philo, char *s)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%d %d %s\n", tv.tv_usec, philo->philo_id, s);
}

pthread_mutex_t	**find_forks(t_s_philo *philo)
{
	int				id;
	pthread_mutex_t	**fork_pair;

	// TODO: How to make sure forks are being searched only once all threads have been created?
	// printf("find_fork(): fork_arr address is %p\n", philo->fork_arr);
	fork_pair = (pthread_mutex_t **)malloc(2 * sizeof(pthread_mutex_t));
	if (!fork_pair)
	{
		printf("Malloc failed\n");
		exit(1);
	}
	id = philo->philo_id;
	if (*(*(philo->fork_arr) + id))
	{
		if (id == 1)
		{
			fork_pair[0] = *(*(philo->fork_arr) + 0);
			fork_pair[1] = *(*(philo->fork_arr) + id);
		}
		else
		{
			fork_pair[0] = *(*(philo->fork_arr) + id - 1);
			fork_pair[1] = *(*(philo->fork_arr) + id);
		}
	}
	else
	{
		fork_pair[0] = *(*(philo->fork_arr) + id - 1);
		fork_pair[1] = *(*(philo->fork_arr) + 0);
	}
	// printf("Forks found at address %p and %p\n", fork_pair[0], fork_pair[1]);
	return (fork_pair);
}

int	get_forks(t_s_philo *philo)
{
	pthread_mutex_t	**fork_pair;

	fork_pair = find_forks(philo);
	pthread_mutex_lock(fork_pair[0]);
	log_state(philo, "has taken a fork");
	pthread_mutex_lock(fork_pair[1]);
	log_state(philo, "has taken a fork");
	// NEED TO FREE??
	return (0);
	// TODO: check if failure and return (1);
}

int	release_forks(t_s_philo *philo)
{
	pthread_mutex_t	**fork_pair;

	// printf("%d Getting forks...\n", philo->philo_id);
	fork_pair = find_forks(philo);
	// printf("%d Unlocking forks...\n", philo->philo_id);
	pthread_mutex_unlock(fork_pair[0]);
	pthread_mutex_unlock(fork_pair[1]);
	// printf("%d Forks unlocked\n", philo->philo_id);
	return (0);
	// TODO: check if failure and return (1);
}

void	eat_philo(t_s_philo *philo)
{
	struct timeval	tv;

	get_forks(philo);
	log_state(philo, "is eating");
	gettimeofday(&tv, NULL);
	philo->t_last_eat = tv.tv_usec;
	usleep(philo->time_to_eat);
	release_forks(philo);
	philo->eat_count++;
}

void	sleep_philo(t_s_philo *philo)
{
	log_state(philo, "is sleeping");
	usleep(philo->time_to_sleep);
}

void	think_philo(t_s_philo *philo)
{
	log_state(philo, "is thinking");
}

int	check_health(t_s_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if ((tv.tv_usec - philo->t_last_eat) > philo->time_to_die)
	{
		log_state(philo, "died");
		return (1);
		// TODO: How to close parent process without using exit()
	}
	return (0);
}