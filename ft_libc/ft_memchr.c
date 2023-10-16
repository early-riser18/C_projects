#include <stdio.h>

void	*ft_memchr(const char *block, int c, size_t size)
{
	unsigned char	*my_ptr;
	size_t			i;

	i = 0;
	my_ptr = (unsigned char *)block;
	while (i < size)
	{
		if ((unsigned char)c == *my_ptr)
		{
			return (my_ptr);
		}
		my_ptr++;
		i++;
	}
	return (NULL);
}
