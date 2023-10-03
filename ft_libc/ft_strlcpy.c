#include <stdio.h>

size_t ft_strlcpy(char *restrict to, const char *restrict from, size_t size)
{
    size_t i = 0;

    while (*from && i < (size - 1))
    {
        *to = *from;
        from++;
        to++;
        i++;
    }
    *to = 0;
    return i;
}

// int main()
// {   size_t len;
//     char tstFr[] = "Apple";
//     char tstTo[] = "I love to eat Bananas";
//     printf("\n-----TEST 1-----\n");
//     len = ft_strlcpy(&tstTo[14], tstFr, 10);
//     printf("Output: %s\t string \"from\" length: %zu\n", tstTo, len);

//     printf("\n-----TEST 2-----\n");
//     char tstFr1[] = "Greatly";
//     char tstTo1[] = "anticonstitutional";
//     len = ft_strlcpy(&tstTo1[4], tstFr1, 60);
//     printf("Output: %s\t string \"from\" length: %zu\n", tstTo1, len);

//     printf("\n-----TEST 3-----\n");
//     char tstFr2[] = "I am humongusly huge";
//     char tstTo2[9] = "im small";
//     len = ft_strlcpy(&tstTo2[3], &tstFr2[5], 60);
//     printf("Output: %s  string \"from\" length: %zu\n", tstTo2, len);
//     return 0;
// }