#include <pthread.h>
#include <libc.h>
#include "philosophers.h"

void *philosopher_t(void *args)
{	
	t_s_philo	*thread_args;
	suseconds_t		t_last_eat;
	struct timeval	tv;

	thread_args = args;
	gettimeofday(&tv, NULL);
	t_last_eat = tv.tv_usec;

	while(1)
	{
		gettimeofday(&tv, NULL);
		// printf("counted tine %d\t time to die %d\n", tv.tv_usec - t_last_eat, thread_args->time_to_die);
		if ((tv.tv_usec - t_last_eat) > thread_args->time_to_die)
		{
			write(1, "I shall die\n", 13);
			exit(1);
			// TODO: How to close parent process without using exit()
		}
		get_forks(thread_args);
		t_last_eat = tv.tv_usec;
		//TODO: Log thread safe
		printf("%d %d is eating\n", tv.tv_usec, thread_args->philo_id);
		usleep(thread_args->time_to_eat);
		printf("%d %d finished eating\n", tv.tv_usec, thread_args->philo_id);
		release_forks(thread_args);
		gettimeofday(&tv, NULL);
		printf("%d %d is sleeping\n", tv.tv_usec, thread_args->philo_id);
		usleep(thread_args->time_to_sleep);
	}
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
	printf("Fork 0 address is %p\n", forks);
	if (!philosophers || !forks)
		{
			printf("Malloc failed\n");
			exit(1);
		}
	i = 0;
	while(i < nbr_philo)
	{
		philosophers[i] = malloc(sizeof(t_s_philo));
		forks[i] = malloc(sizeof(pthread_mutex_t));
		printf("Fork %d is at %p\n", i, &forks[i]);
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
		pthread_create(&(philosophers[i]->philo_t), NULL, philosopher_t, philosophers[i]);
		i++;
	}

	usleep(20000); // just to time simulation;
	printf("***Simulation ends***\n");
	return 0;
}


// void	log_threadsafe(int philo_id, char *s, pthread_mutex_t lock)
// {
// 	struct timeval tv;
// 	gettimeofday(&tv, NULL);
// 	pthread_mutex_lock(&lock);
// 	//TODO: check if success
// 	//TODO: lock printing
// 	printf("%d %d %s", tv.tv_usec, philo_id, s);
// 	pthread_mutex_unlock(&lock);
// }