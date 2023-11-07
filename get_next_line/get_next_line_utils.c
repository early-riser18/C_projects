#include <libc.h>
#include <stdio.h>

char	*ft_realloc(char *from, size_t size)
{
	char	*output;
	int		i;

	i = 0;
	output = malloc(size);
	if (!output)
	{
		return (NULL);
	}
	while (from[i] && (size_t)i < size - 1)
	{
		output[i] = from[i];
		i++;
	}
	output[i] = 0;
	free(from);
	return (output);
}

size_t	ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *to, const char *from, size_t size)
{
	size_t	from_len;
	size_t	i;
	
	from_len = ft_strlen(from);
	i = 0;
	if (size > 0)
	{
		while ((i + 1) < size && *from)
		{	
			*to = *from;
			from++;
			to++;
			i++;
			
		}
		*to = 0;
	}
	return (from_len);
}

void	*ft_memmove(void *to, void *from, size_t size)
{
	size_t	i;
	char	from_copy[size + 1];

	i = 0;
	from_copy[size] = 0; 
	while (i < size)
	{
		from_copy[i] = ((char *)from)[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		((char *)to)[i] = from_copy[i];
		i++;
	}
	return (to);
}

int	get_buffer(int fd, char *buffer, int *iter, size_t buffer_size)
{
	int	read_size;
	read_size = ft_strlen(buffer);

	if (read_size == 0)
		{
			read_size = read(fd, buffer, buffer_size);
			if (read_size <= 0)
			{
				buffer[0] = 0;
				return -(1);
			}
			*iter = 0;
		}
		buffer[read_size] = 0;
		return (read_size);
}