#include <stdio.h>

void ft_bzero(void *block, size_t size)
{
    char *ptr = (char *)block;
    for (size_t i = 0; i < size; i++, ptr++)
    {
        *ptr = 0;
    }
    return;
}