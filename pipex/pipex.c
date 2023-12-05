#include <libc.h>
#include "libft.h"
#include "pipex.h"

extern char	**environ;
// Supports limited parsing of arguments only.

int	main(int argc, char *argv[])
{
	int	fd_file;
	int	fd_pipe[2];
	int	c_pid[2];

	if (argc < 5 || access(argv[1], R_OK) != 0)
	{
		exit(1);
	}
	if (pipe(fd_pipe) == -1)
	{
		perror("pipe");
		exit(1);
	}
	c_pid[0] = fork();
	if (c_pid[0] < 0)
	{
		exit(1);
	}
	else if (c_pid[0] == 0)
	{
		fd_file = open(argv[1], O_RDONLY);
		dup2(fd_file, 0);
		dup2(fd_pipe[1], 1);
		execve(resolve_filepath(ft_split(argv[2], ' ')[0]),
			parse_args(argv[2]), environ
			);
		exit(1);
	}
	c_pid[1] = fork();
	if (c_pid[1] < 0)
	{
		exit(1);
	}
	else if (c_pid[1] == 0)
	{
		fd_file = open(
				argv[4],
				O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		dup2(fd_pipe[0], 0);
		dup2(fd_file, 1);
		close(fd_pipe[1]);
		execve(resolve_filepath(ft_split(argv[3], ' ')[0]),
			parse_args(argv[3]), environ);
		exit(1);
	}
	close(fd_pipe[1]);
	wait(&c_pid[0]);
	wait(&c_pid[1]);
	exit(0);
}
