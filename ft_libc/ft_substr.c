#include <libc.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	ft_strlcpy(sub_str, &s[start], len+1);
	return (sub_str);
}
