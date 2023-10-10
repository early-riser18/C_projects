#include <stdio.h>
#include <libc.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *subS = malloc(len + 1);
    if (subS == NULL)
    {
        return NULL;
    }

    return ft_memcpy(subS, &s[start], len);
}

// int main(){
//     char myS[] = "hello";
//     printf("%s", ft_substr(myS,1,3));
//     return 0;
// }