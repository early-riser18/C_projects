#include <stdio.h>
#include "libft.h"

size_t ft_strlcpy(char *to, const char *from, size_t size)
{

    size_t fromLen = ft_strlen(from);
    size_t i = 0;

    if (size > 0)
    {
        while ((i + 1) < size  && *from)
        {
            *to = *from;
            from++, to++, i++;
        }
        *to = 0;
    }

    return fromLen;
}