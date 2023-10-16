#include <stdio.h>

void	*ft_memset(void *block, int c, size_t size)
{
	unsigned char *myPtr;
	size_t i;

	myPtr = (unsigned char *)block;
	i = 0;
	while (i < size)
	{
		*myPtr = c;
		myPtr++;
		i++;
	}
	return block  ;
}