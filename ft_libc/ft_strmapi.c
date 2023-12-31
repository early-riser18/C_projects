#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_str;

	if (!s || !f)
	{
		return (NULL);
	}
	i = 0;
	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (!new_str)
	{
		return (NULL);
	}
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
