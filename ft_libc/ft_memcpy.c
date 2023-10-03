#include <stdio.h>

void *ft_memcpy(void *restrict to, const void *restrict from, size_t size)
{
    char *pTo = to;
    char *pFrom = (char *)from;

    for (size_t i = 0; i < size; i++, pTo++, pFrom++)
    {
        *pTo = *pFrom;
    }

    return to;
}

// int main()
// {
//     char testAr[] = "this is a test";
//     ft_memcpy(&testAr[6], testAr, 2);
//     printf("%s", testAr);
//     return 0;
// }