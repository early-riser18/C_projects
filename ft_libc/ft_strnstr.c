#include <stdio.h>
#include "libft.h"

// Did not manage to write a more concise function...
char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	char	*little_iter;
	char	*big_iter;
	size_t	i;

	little_iter = (char *)little;
	big_iter = (char *)big;
	i = 0;
	if (!*little_iter)
	{
		return ((char *)big);
	}
	while (*big_iter && i < size) // Will timeout for big size values.
	{
		if (!*little_iter)
		{
			return ((char *)big);
		}
		if (*big_iter)
		{
			if (*little_iter == *big_iter)
			{
				little_iter++;
			}
			else
			{
				little_iter = (char *)little;
				big = big_iter + 1;
			}
			big_iter++;
		}
		i++;
	}
	return (NULL);
}
