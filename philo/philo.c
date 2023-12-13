#include "philo.h"
#include <libc.h>
#include <pthread.h>

void	*philosopher_t(void *args)
{
	t_s_philo	*thread_args;
	struct timeval	tv;

	thread_args = (t_s_philo *)args;
	gettimeofday(&tv, NULL);
	thread_args->t_last_eat = tv.tv_usec;
	while (thread_args->eat_count != thread_args->max_eat_count)
	{
		if (check_health(thread_args))
		{
			thread_args->status->dead_count++;
			break ;
		}
		think_philo(thread_args);
		eat_philo(thread_args);
		sleep_philo(thread_args);
	}
	thread_args->status->completed_count++;
	return (NULL);
}

void	init_philo(t_s_philo *philo, pthread_mutex_t ***forks, char *argv[],
		struct s_philo_status *status)
{
	static int	id = 1;

	pthread_mutex_init((*(forks))[id - 1], NULL);
	philo->fork_arr = forks;
	philo->philo_id = id;
	philo->time_to_die = ft_atoi(argv[2]) * 1000;
	philo->time_to_eat = ft_atoi(argv[3]) * 1000;
	philo->time_to_sleep = ft_atoi(argv[4]) * 1000;
	philo->max_eat_count = -1;
	philo->eat_count = 0;
	philo->status = status;
	if (argv[5])
	{
		philo->max_eat_count = ft_atoi(argv[5]);
	}
	pthread_create(&(philo->philo_t), NULL, philosopher_t, philo);
	pthread_detach(philo->philo_t);
	id++;
}

int	main(int argc, char *argv[])
{
	int					nbr_philo;
	int					i;
	t_s_philo			**philosophers;
	pthread_mutex_t		**forks;
	struct s_philo_status *status;

	(void)argc;
	nbr_philo = ft_atoi(argv[1]);
	philosophers = (t_s_philo **)malloc(nbr_philo * sizeof(t_s_philo *));
	forks = (pthread_mutex_t **)malloc((nbr_philo + 1)
			* sizeof(pthread_mutex_t *));
	status = (struct s_philo_status *)malloc(sizeof(struct s_philo_status));
	if (!philosophers || !forks || !status)
	{
		printf("Malloc failed\n");
		return (1);
	}
	forks[nbr_philo] = NULL;
	status->completed_count = 0;
	status->dead_count = 0;
	i = 0;
	while (i < nbr_philo)
	{
		philosophers[i] = malloc(sizeof(t_s_philo));
		forks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!philosophers[i] || !forks[i])
		{
			printf("Malloc failed\n");
			return (1);
		}
		init_philo(philosophers[i], &forks, argv, status);
		i++;
	}
	while (status->completed_count < i && status->dead_count == 0)
	{
	}
	return (0);
}
