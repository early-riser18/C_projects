#include <stdio.h>

void	ft_bzero(void *block, size_t size)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)block;
	i = 0;
	while (i < size)
	{
		*ptr = 0;
		i++;
		ptr++;
	}
	return ;
}
