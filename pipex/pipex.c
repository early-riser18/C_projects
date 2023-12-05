#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <libc.h>
#include <errno.h>
#include "libft.h"
#include "pipex.h"

extern char **environ;
 

int main(int argc, char *argv[])
{
	int fd_file[2];
	int fd_pipe[2];
	int c_pid[2];

	if(argc < 5 || access(argv[1], R_OK) != 0 || access(argv[4], R_OK) != 0)
	{
		exit(1);
	}

	if (pipe(fd_pipe) == -1)
	{
		perror("pipe");
		return 1;
	}

	c_pid[0] = fork();
	if (c_pid[0] < 0)
	{
		// fork failed
		printf("fork failed\n");
	} else if (c_pid[0] == 0)
	{
		// child process
		close(0);
		fd_file[0] = open(argv[1],O_RDONLY);
		dup2(fd_file[0], 0);
		close(1);
		dup2(fd_pipe[1], 1);
		execve(resolve_filepath(ft_split(argv[2], ' ')[0]), ft_split(argv[2], ' '), environ); 
		printf("did not work 1\n");
		exit(1);
	}
	wait(&c_pid[0]);
	close(fd_pipe[1]);

	c_pid[1] = fork();
	if (c_pid[1] < 0)
	{
		printf("fork failed \n");
	}
	else if (c_pid[1] == 0)
	{
		close(0);
		dup2(fd_pipe[0], 0);
		close(1);
		fd_file[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
		dup2(fd_file[1], 1);
		

		execve(resolve_filepath(ft_split(argv[3], ' ')[0]), ft_split(argv[3], ' '), environ);
		printf("did not work 2\n");

		exit(1);
	}
	wait(&c_pid[1]);
	exit(0);
	
}