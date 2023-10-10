#include <stdio.h>

int ft_memcmp(const char *a1, const char *a2, size_t size)
{
    for (size_t i = 0; i < size; i++, a1++, a2++)
    {
        if (*(unsigned char *)a1 != *(unsigned char *)a2)
        {
            return *(unsigned char *)a1 - *(unsigned char *)a2;
        }
    }
    return 0;
}

// int main()
// {
//     char str1[] = "capu";
//     char str2[] = "capu";
//     printf("%d", ft_memcmp(str1, str2, 10));
//     return 0;
// }