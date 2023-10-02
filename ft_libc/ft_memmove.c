#include <stdio.h>

void *ft_memmove(void *to, void *from, size_t size)
{
    char *toPtr = (char *)to;
    char *fromPtr = (char *)from;
    char fromCopy[size + 1];
    fromCopy[size] = 0;

    for (size_t i = 0; i < size; i++, fromPtr++)
    {
        fromCopy[i] = *fromPtr;
    }

    for (size_t j = 0; j < size; j++, toPtr++)
    {
        *toPtr = fromCopy[j];
    }
    return to;
}

int main()
{
    char testAr[] = "Melody is Justin";
    ft_memmove(&testAr[2], testAr, 6);
    printf("%s\n", testAr);
    return 0;
}