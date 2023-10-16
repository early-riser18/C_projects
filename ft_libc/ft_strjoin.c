#include <libc.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sub_str_size;
	char	*cat_str;

	sub_str_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	cat_str = malloc(sub_str_size);
	if (cat_str == NULL)
	{
		return (NULL);
	}
	ft_strlcat((char *)cat_str, s1, sizeof(s1));
	ft_strlcat((char *)cat_str, s2, sizeof(s2));
	return (cat_str);
}
