#include <stdio.h>
#include "libft.h"

size_t ft_strlcat(char *restrict to, const char *restrict from, size_t size)
{
    size_t toLen = ft_strlen(to);
    size_t fromLen = ft_strlen(from);

    to += toLen;
    size_t i = 0;
    while (*from && i < (size - 1))
    {
        *to = *from;
        from++;
        to++;
        i++;
    }
    *to = 0;
    return toLen + fromLen;
}

// int main(){
//     size_t len;
//     char tstFr[] = " & Apple";
//     char tstTo[] = "I love to eat Bananas";
//     printf("\n-----TEST 1-----\n");
//     len = ft_strlcat(tstTo, tstFr, 5);
//     printf("Output: %s\t strlcat returns: %zu\n", tstTo, len);

//     printf("\n-----TEST 2-----\n");
//     char tstFr1[50] = "Greatly ";
//     char tstTo1[30] = "anticonstitutional";
//     len = ft_strlcat(tstFr1, tstTo1, 10);
//     printf("Output: %s\t strlcat returns: %zu\n", tstFr1, len);

// }