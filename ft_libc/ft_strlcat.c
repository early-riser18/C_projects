#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *to, const char *from, size_t size)
{
	size_t	to_len;
	size_t	from_len;
	size_t	i;

	to_len = ft_strlen(to);
	from_len = ft_strlen(from);
	if (size <= to_len)
	{
		return (from_len + size);
	}
	to += to_len;
	i = to_len + 1;
	while (*from && i < size)
	{
		*to = *from;
		from++;
		to++;
		i++;
	}
	*to = 0;
	return (to_len + from_len);
}
