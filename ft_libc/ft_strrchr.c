#include <stdio.h>

char	*ft_strrchr(const char *string, int c)
{
	char	*last_occurence;

	last_occurence = NULL;
	while (*string)
	{
		if (*string == (char)c)
		{
			last_occurence = (char *)string;
		}
		string++;
	}
	if (c == 0)
	{
		return ((char *)string);
	}
	return (last_occurence);
}
