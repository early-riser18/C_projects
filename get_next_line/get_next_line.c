#include "get_next_line.h"
#include <libc.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	char		*out;
	static char	read_buff[BUFFER_SIZE + 1] = {0};
	int			i;
	int			read_size;

	i = 0;
	read_size = 0;
	out = NULL;
	if (fd < 0)
	{
		return (NULL);
	}
	while (1)
	{
		read_size = get_buffer(fd, read_buff, &i, BUFFER_SIZE);
		if (read_size <= 0)
		{
			return (out);
		}
		while (i < read_size && read_buff[i] != 10)
		{
			i++;
		}
		if (!out)
		{
			out = malloc(1);
			out[0] = 0;
		}
		out = ft_realloc(out, ft_strlen(out) + 2 + i);
		if (!out)
		{
			return (NULL);
		}
		ft_strlcpy(&out[ft_strlen(out)], (char *)read_buff, i + 2);
		if (i >= read_size) // order is important to not read outside buffer!
		{
			read_buff[0] = 0;
			read_size = 0;
		}
		else if (read_buff[i] == 10)
		{
			ft_memmove(read_buff, &read_buff[i + 1], read_size - i - 1);
			read_buff[read_size - i - 1] = 0;
			return (out);
		}
	}
}
