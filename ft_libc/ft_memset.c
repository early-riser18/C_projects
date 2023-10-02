#include <stdio.h>

void *ft_memset(void *block, int c, size_t size)
{
    unsigned char *myPtr = (unsigned char *)block;

    size_t i = 0;
    while (i < size)
    {
        *myPtr = c;
        myPtr++;
        i++;
    }
    return block;
}