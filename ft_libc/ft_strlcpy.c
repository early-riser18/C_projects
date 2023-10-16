#include <stdio.h>
#include "libft.h"

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
