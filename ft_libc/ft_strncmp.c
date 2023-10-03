#include <stdio.h>

int strncmp(const char *s1, const char *s2, size_t size)
{
    int diff;
    size_t i = 0;
    while (i < size && *s1 && *s2)
    {
        diff = *s1 - *s2;
        if (diff != 0)
        {
            return diff;
        }
        i++, s1++, s2++;
    }
    return diff;
}

// int main()
// {
//     char str1[] = "capi";
//     char str2[] = "capitali";
//     printf("%d", strncmp(str1, str2, 10));
//     return 0;
// }