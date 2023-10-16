#include <stdio.h>

int	ft_memcmp(const char *a1, const char *a2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(unsigned char *)a1 != *(unsigned char *)a2)
		{
			return (*(unsigned char *)a1 - *(unsigned char *)a2);
		}
		i++;
		a1++;
		a2++;
	}
	return (0);
}
