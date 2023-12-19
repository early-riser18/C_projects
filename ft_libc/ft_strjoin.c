#include "libft.h"
#include <libc.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sub_str_size;
	char	*cat_str;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	sub_str_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	cat_str = ft_calloc(sizeof(char), sub_str_size);
	if (!cat_str)
	{
		return (NULL);
	}
	ft_strlcat(cat_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(&cat_str[ft_strlen(s1)], s2, sub_str_size);
	return (cat_str);
}
