#include <libc.h>
#include "libft.h"

char	*ft_sub_strtr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;

	if (!s)
	{
		return (NULL);
	}
	sub_str = malloc(len+1);
	if (sub_str == NULL)
	{
		return (NULL);
	}
	return (ft_memcpy(sub_str, &s[start], len));
}
