#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <libc.h>
#include "libft.h"

int	server_pid;

int	binary_as_int_to_sig(int bin_as_int)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		if (bin_as_int % 10 == 1)
		{

			if(kill(server_pid, SIGUSR2) == -1)
			{
				printf("Kill ERRNO %d\n",errno);
			}
			bin_as_int -= 1;
		} 
		else if (bin_as_int % 10 == 0)
		{
			// printf("|i %d|Sending SIGUSR1\n", i);
			if(kill(server_pid, SIGUSR1) == -1)
			{
				printf("Kill ERRNO %d\n",errno);
			}
		}
		else
		{
			printf("wrong binary as int representation passed. Got %d\n", bin_as_int);
			return (1);
		}
		bin_as_int /= 10;
		i++;
		usleep(100);
	}
	return (0);
}

int	char_to_binary_as_int(char c)
{
	int	i;
	int	bin_as_int;
	int place;

	place = 1;
	bin_as_int = 0;
	i = 0;

	while (i < 7)
	{
		bin_as_int += (c % 2) * place;
		place *= 10;
		c -= c % 2;
		c /=2;
		i++;
	}
	return bin_as_int;
}

int main(int argc, char	*argv[])
{	

	printf("We have %d arguments, 2nd value is: %s\n", argc, argv[1]);
	server_pid = ft_atoi(argv[1]);

	while(argv[2][0])
	{
		binary_as_int_to_sig(
			char_to_binary_as_int(argv[2][0])
		);
		argv[2]++;
		usleep(100);
	}
	binary_as_int_to_sig(0);

	return 0;
}
