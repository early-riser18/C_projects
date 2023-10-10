#include <stdio.h>

char *ft_strrchr(const char *string, int c)
{
    char *lastOccurence = NULL;

    while (*string)
    {
        if (*string == (char)c)
        {
            lastOccurence = (char *)string;
        }
        string++;
    }

    if (c == 0)
    {
        return (char *)string;
    }

    return lastOccurence;
}