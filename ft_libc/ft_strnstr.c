#include <stdio.h>
#include "libft.h"

// Did not manage to write a more concise function...
char *ft_strnstr(const char *big, const char *little, size_t size)
{
    char *littleIter = (char *)little;
    char *bigIter = (char *)big;
    size_t i = 0;

    if (!*littleIter)
    {
        return (char *)big;
    }

    while (i < size) // Will timeout for big size values.
    {

        if (!*littleIter)
        {
            return (char *)big;
        }
        if (*bigIter)
        {
            if (*littleIter == *bigIter)
            {
                littleIter++;
            }
            else
            {
                littleIter = (char *)little;
                big = bigIter + 1;
            }
            bigIter++;
        }
        i++;
    }
    return NULL;
}