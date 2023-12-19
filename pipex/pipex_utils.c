#include "libft.h"
#include <libc.h>

extern char	**environ;

char	*get_env_val(char *env_key)
{
	int			i;
	size_t		len_key;
	char		*env_val;

	i = 0;
	env_val = NULL;
	len_key = ft_strlen(env_key);
	while (environ[i])
	{
		if (ft_strncmp(env_key, environ[i], len_key) == 0
			&& environ[i][len_key] == '=')
		{
			env_val = environ[i] + len_key + 1;
			break;
		}
		i++;
	}
	return (env_val);
}

char	**parse_args(char *args)
{
	char	**parsed_args;
	int		i;

	i = 1;
	parsed_args = ft_split(args, ' ');
	printf("%s\n", parsed_args[0]);
	while (parsed_args[i])
	{
		parsed_args[i] = ft_strtrim(parsed_args[i], "\"");
		i++;
	}
	return (parsed_args);
}

char	*resolve_filepath(char *short_path)
{
	char	*path;
	char	*path_stub;
	int		i;

	i = 0;
	path = get_env_val("PATH");
	path_stub = NULL;
	if (access(short_path, X_OK) == 0)
	{
		return (short_path);
	}
	while (path[i])
	{
		if (path[i] != ':')
		{
			i++;
		}
		else if (i > 0)
		{
			path_stub = malloc(i + ft_strlen(short_path) + 1);
			ft_strlcpy(path_stub, path, i + 1);
			path_stub[i] = '/';
			ft_strlcat(&path_stub[i + 1],
				short_path,
				ft_strlen(short_path) + 1);
			if (access(path_stub, X_OK) == 0)
			{
				printf("path found %s \n", path_stub);
				return (path_stub);
			}
			path = &path[i + 1];
			i = 0;
		}
	}
	return (NULL);
}

int	*create_child(int fd_in, int fd_out, char *cmd_str, char **environ)
{
	char	*cmd;
	char	*cmd_path;
	char	**args_val;
	int		*c_pid;

	(void)fd_out;
	c_pid = malloc(sizeof(int));
	*c_pid = fork();
	if (*c_pid < 0)
	{
		exit(1);
	}
	else if (*c_pid == 0)
	{
		dup2(fd_in, 0);
		dup2(fd_out, 1);
		cmd = ft_split(cmd_str, ' ')[0];
		cmd_path = resolve_filepath(cmd);
		args_val = parse_args(cmd_str);
		execve(cmd_path, args_val, environ);
		exit(1);
	}
	return (c_pid);
}

int	validate_input(int argc, char *argv[])
{
	return (argc < 5 || access(argv[1], R_OK) != 0);
}
