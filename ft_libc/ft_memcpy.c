#include <stdio.h>

void	*ft_memcpy(void *to, const void *from, size_t size)
{
	char	*p_to;
	char	*p_from;
	size_t	i;

	p_to = to;
	p_from = (char *)from;
	i = 0;
	while (i < size)
	{
		*p_to = *p_from;
		i++;
		p_to++;
		p_from++;
	}
	return (to);
}
