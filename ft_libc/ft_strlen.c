#include <stdio.h>
size_t ft_strlen(const char *s)
{
    char *ptr = (char *)s;
    int len = 0;
    while (*ptr)
    {
        len++;
        ptr++;
    }
    return len;
}