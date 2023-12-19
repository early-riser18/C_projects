#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < size && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < size)
		{
			if (little[j + 1] == '\0')
				return (char *)(big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
