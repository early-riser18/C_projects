#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	str_byte_size;
	void	*return_ptr;

	str_byte_size = ft_strlen(s) +1;
	return_ptr = malloc(str_byte_size);
	if (return_ptr != NULL)
	{
		ft_strlcpy(return_ptr, s, str_byte_size);
	}
	return (return_ptr);
}
