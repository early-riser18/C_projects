#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t eltsize)
{
	size_t	block_len;
	void	*return_ptr;
	size_t	i;

	block_len = count * eltsize;
	return_ptr = malloc(block_len);
	if (!return_ptr)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; i < block_len; i++, return_ptr++)
		{
			*(char *)return_ptr = 0;
		}
		return_ptr -= (block_len);
		return (return_ptr);
	}
}
