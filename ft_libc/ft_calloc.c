#include <stdio.h>
#include <stdlib.h>

void *ft_calloc(size_t count, size_t eltsize)
{
    size_t blockLen = count * eltsize;
    void *returnPtr = malloc(blockLen);

    if (returnPtr != NULL)
    {
        for (size_t i = 0; i < blockLen; i++, returnPtr++)
        {
            *(char *)returnPtr = 0;
        }
        returnPtr -= (blockLen);
    }

    return returnPtr;
}
