#include <stdio.h>
#include <libc.h>
#include "libft.h"

char * ft_strjoin(char const * s1, char const * s2)
{
    size_t subStrSize = ft_strlen(s1) + ft_strlen(s2) + 1;
    char * catStr = malloc(subStrSize);
    if (catStr == NULL){
        printf("he");
        return NULL;

    }
    ft_strlcat((char*)catStr,s1,sizeof(s1));
    ft_strlcat((char*)catStr,s2,sizeof(s2));

    return catStr;
}

// int main()
// {
//     char s1[] = "prefix ";
//     char s2[] = "suffix";
//     printf("%s", ft_strjoin(s1,s2));
//     return 0;
// }