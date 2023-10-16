#include <stdio.h>

void	*ft_memset(void *block, int c, size_t size)
{
	unsigned char	*my_ptr;
	size_t			i;

	my_ptr = (unsigned char *)block;
	i = 0;
	while (i < size)
	{
		*my_ptr = c;
		my_ptr++;
		i++;
	}
	return (block);
}
