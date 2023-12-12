#include <pthread.h>
#include <libc.h>
#include "philo.h"

void *philosopher_t(void *args)
{	
	t_s_philo	*thread_args;
	suseconds_t		t_last_eat;
	struct timeval	tv;
	int eat_count;

	eat_count = 0;
	thread_args = args;
	gettimeofday(&tv, NULL);
	t_last_eat = tv.tv_usec;

	while(eat_count != thread_args->max_eat_count)
	{
		gettimeofday(&tv, NULL);
		// printf("counted tine %d\t time to die %d\n", tv.tv_usec - t_last_eat, thread_args->time_to_die);
		if ((tv.tv_usec - t_last_eat) > thread_args->time_to_die)
		{
			log_state(thread_args, "has died");
			exit(1);
			// TODO: How to close parent process without using exit()
		}
		log_state(thread_args, "is thinking");
		get_forks(thread_args);
		t_last_eat = tv.tv_usec;
		//TODO: Log thread safe
		log_state(thread_args, "is eating");
		usleep(thread_args->time_to_eat);
		eat_count++;
		release_forks(thread_args);
		log_state(thread_args, "is sleeping");
		usleep(thread_args->time_to_sleep);
	}
	printf("%d %d ate enough.\n", tv.tv_usec, thread_args->philo_id);
	return NULL; 
}



	//#TODO validate inputs passed by STDIN
	//#TODO support input beyond the max microseconds val (also bug prone even if little vals passed) 


int main(int argc, char *argv[])
{
	int				nbr_philo;
	int				i;
	t_s_philo	**philosophers;
	pthread_mutex_t **forks;

	nbr_philo = ft_atoi(argv[1]);
	philosophers = (t_s_philo **) malloc(nbr_philo * sizeof(t_s_philo*));
	forks = (pthread_mutex_t **) malloc((nbr_philo + 1) * sizeof(pthread_mutex_t *));
	forks[nbr_philo] = NULL;
	if (!philosophers || !forks)
		{
			printf("Malloc failed\n");
			return (1);
		}
	i = 0;
	while(i < nbr_philo)
	{
		philosophers[i] = malloc(sizeof(t_s_philo));
		*(forks + i) = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
		// printf("Fork ptr %d points to %p\n", i, *(forks + i));
		if (!philosophers[i] || !forks[i])
		{
			printf("Malloc failed\n");
			exit(1);
		}
		pthread_mutex_init(forks[i], NULL);
		philosophers[i]->fork_arr = &forks;
		philosophers[i]->philo_id = i + 1;
		philosophers[i]->time_to_die = ft_atoi(argv[2]) * 1000;
		philosophers[i]->time_to_eat = ft_atoi(argv[3]) * 1000;
		philosophers[i]->time_to_sleep = ft_atoi(argv[4]) * 1000;
		philosophers[i]->max_eat_count = -1;
		if (argc == 6)
		{
			philosophers[i]->max_eat_count = ft_atoi(argv[5]);
		}
		pthread_create(&(philosophers[i]->philo_t), NULL, philosopher_t, philosophers[i]);
		i++;
	}

	i = 0;
	while (i < nbr_philo)
	{
		pthread_join(philosophers[i]->philo_t, NULL);
		i++;
	}
	printf("***Simulation ends***\n");
	return 0;
}