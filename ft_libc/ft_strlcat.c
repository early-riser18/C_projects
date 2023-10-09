#include <stdio.h>
#include "libft.h"

size_t ft_strlcat(char * to, const char *from, size_t size)
{
    size_t toLen = ft_strlen(to);
    size_t fromLen = ft_strlen(from);

    if (size <= toLen)
        return fromLen + size;

    to += toLen;
    size_t i = toLen+1;

    // i == output size
    while (*from && i < size)
    {
        *to = *from;
        from++;
        to++;
        i++;
    }
    *to= 0;
    return toLen + fromLen;
}

// int main(){
//     size_t len;
//     char tstFr[] = "DDEE";
//     char tstTo[] = "AABBCC";
//     printf("\n-----TEST 1-----\n");
//     len = ft_strlcat(tstTo, tstFr, 8);
//     printf("Output: %s\t strlcat returns: %zu\n", tstTo, len);

//     printf("\n-----TEST 2-----\n");
//     char tstFr1[] = "the cake is a lie !\0I'm hidden lol\r\n"; // strlen = 19
//     char tstTo1[] = "there is no stars in the sky";
//     len = ft_strlcat(tstTo1, tstFr1, ft_strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4);
//     printf("Output: %s\t strlcat returns: %zu\n", tstTo1, len);

//     printf("\n-----TEST 3-----\n");
//     char tstFr2[] = "abcd";
//     char tstTo2[] = "pqrstuvwxyz";
//     len = ft_strlcat(tstTo2, tstFr2, 1);
//     printf("Output: %s\t strlcat returns: %zu\n", tstTo2, len);

//     printf("\n-----TEST 4-----\n");
//     char tstFr3[] = "aaa";
//     char tstTo3[] = "BBBBBBBBBBBBBBBBBBBB";
//     len = ft_strlcat(tstTo3, tstFr3, 0);
//     printf("Output: %s\t strlcat returns: %zu\n", tstTo3, len);


// }