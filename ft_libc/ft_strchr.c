#include <stdio.h>

char	*ft_strchr(const char *string, int c)
{
	while (*string)
	{
		if (*string == (char)c)
		{
			return ((char *)string);
		}
		string++;
	}
	if (c == 0)
	{
		return ((char *)string);
	}
	return (NULL);
}
