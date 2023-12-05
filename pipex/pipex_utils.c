#include "libft.h"
#include <libc.h>

extern char **environ;

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
		if (ft_strncmp(env_key, environ[i], len_key) == 0 && environ[i][len_key] == '=')
		{
			env_val = environ[i] + len_key + 1;
			break;
		}
		i++;
	}
	return (env_val);
}

char	*resolve_filepath(char *short_path)
{
	char *path;
	char	*path_stub;
	int	i;

	i = 0;
	path = get_env_val("PATH");
	path_stub = NULL;
	while(path[i])
	{
		// printf("checlking %c\n", path[i]);

		if (path[i] != ':')
		{
			i++;
		}
		else if (i > 0)
		{
			// printf("i is %d\n", i);
			path_stub = malloc(i + ft_strlen(short_path) + 1);
			ft_strlcpy(path_stub, path, i + 1);
			path_stub[i] = '/';
			ft_strlcat(&path_stub[i + 1], short_path, ft_strlen(short_path) + 1);
			if (access(path_stub, X_OK) == 0)
			{
				printf("path found %s \n", path_stub );
				return path_stub;
			}
			path = &path[i + 1];
			i = 0;
		}
	}
	return (NULL);
}

