#include <libc.h>
#include <signal.h>
#include "libft.h"

char	g_bin_char = 0;

void	handler_sigusr(int signum)
{	
	if (signum == SIGUSR1)
	{
		g_bin_char >>= 1;
		g_bin_char &= 0x7F;
	} 
	else if (signum == SIGUSR2)
	{
		g_bin_char >>= 1;
		g_bin_char |= 0x80;
	}
}

char	*ft_realloc(char *s, size_t size)
{
	char	*temp;

	temp = ft_calloc(size, 1);
	ft_strlcpy(temp, s, strlen(s) + 1);
	free(s);
	return (temp);
}

int	main(void)
{
	char				*output_msg;
	int					byte_i;
	const int			block_size = 10;
	struct sigaction	sa;

	byte_i = 0;
	g_bin_char = 0;
	sa.sa_handler = handler_sigusr;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("%d\n", getpid());
	output_msg = ft_calloc(block_size, 1);
	if (!output_msg)
	{
		printf("Malloc failed");
		exit(1);
	}
	while (1)
	{	
		pause();
		byte_i++;
		if (byte_i > 7)
		{
			if (!output_msg)
			{
				output_msg = ft_calloc(block_size, 1);
			}
			if ((ft_strlen(output_msg) + 1) % block_size == 0)
			{
				output_msg = ft_realloc(output_msg, ft_strlen(output_msg) + 1 + block_size);
			}
			output_msg[ft_strlen(output_msg)] = g_bin_char;
			if (g_bin_char == 0)
			{
				printf("%s\n", output_msg);
				free(output_msg);
				output_msg = NULL;
			}
			byte_i = 0;
			g_bin_char = 0;
		}
	}
	return (0);
}
