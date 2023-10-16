#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (!*s1 || !*s2)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
		else if (*(unsigned char *)s1 != *(unsigned char *)s2)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
		i++;
		s1++;
		s2++;
	}
	return (0);
}
