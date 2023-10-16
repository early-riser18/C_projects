#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	char	*ptr;
	int		len;

	ptr = (char *)s;
	len = 0;
	while (*ptr)
	{
		len++;
		ptr++;
	}
	return (len);
}
