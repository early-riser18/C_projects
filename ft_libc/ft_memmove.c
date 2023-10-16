#include <stdio.h>

void	*ft_memmove(void *to, void *from, size_t size)
{
	size_t	i;
	char	from_copy[size + 1];

	i = 0;
	from_copy[size + 1] = 0;
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
