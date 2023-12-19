#include <libc.h>
#include "libft.h"
#include "pipex.h"

extern char	**environ;	
// Limited parsing of arguments
int	main(int argc, char *argv[])
{
	int	fd_file[2];
	int	fd_pipe[2];
	int	**c_pid;

	c_pid = (int **)malloc(sizeof(int));
	if (validate_input(argc, argv))
	{
		exit(1);
	}
	if (pipe(fd_pipe) == -1)
	{
		perror("pipe");
		exit(1);
	}
	fd_file[0] = open(argv[1], O_RDONLY);
	fd_file[1] = open(argv[4],
			O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	c_pid[0] = create_child(fd_file[0], fd_pipe[1], argv[2], environ);
	close(fd_pipe[1]);
	c_pid[1] = create_child(fd_pipe[0], fd_file[1], argv[3], environ);
	wait(c_pid[0]);
	wait(c_pid[1]);
	exit(0);
}
