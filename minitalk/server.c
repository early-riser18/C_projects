#include <libc.h>
#include <signal.h>
unsigned int	bin_msg = 0;

void handler_1(int signum)
{
	int	i;
	i = 0;
	// use write and not printf! Only async safe functions 
	write(0, "Got 0\n",7);
	
	bin_msg = bin_msg << 1;
	
	printf("Adding 0 to bin_msg\n");
	return;
}

void handler_2(int signum)
{
	int	i;
	i = 0;
	// use write and not printf! Only async safe functions 
	write(0, "Got 1\n",7);
	bin_msg = bin_msg << 1;
	bin_msg += 1;
	printf("Adding 1 to bin_msg\n");
	return;
}




int main(void)
{
	char	*output_msg;
	int		byte_i;

	struct sigaction sa_1; 
	sa_1.sa_handler = handler_1;
	sigemptyset(&sa_1.sa_mask);
	sa_1.sa_flags = 0;
	sigaction(SIGUSR1, &sa_1 , NULL);

	struct sigaction sa_2; 
	sa_2.sa_handler = handler_2;
	sigemptyset(&sa_2.sa_mask);
	sa_2.sa_flags = 0;
	sigaction(SIGUSR2, &sa_2 , NULL);


	printf("Server's pid: %d\n",getpid());
	byte_i = 0;
	bin_msg = 0;

	output_msg = malloc(2);
	if (!output_msg)
	{
		printf("Malloc failed");
		exit(1);
	}
	output_msg[1] = 0;

	while(1)
	{	
		// every time the 8 bytes have been filled, interpret  
	pause();
	byte_i++;
	if (byte_i > 6)
	{
		// add char to the output_msg
		printf("final char passed is: %c\n", bin_msg);
		byte_i = 0;
		bin_msg = 0;

	}
	printf("bin_msg:%d, going back to sleep\n", bin_msg);

	}
	return 0;
}


// server listens 
// when handler_1, interpret as 0
// when handler2, interpret as 1;
// upon handler triggered,
// each time server is woken up: checks that the global var has enough space, and last char. If char is 0, then create string, then print.
