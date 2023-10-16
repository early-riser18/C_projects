#include <stdio.h>
#include <libc.h>
#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    size_t s1Len = ft_strlen(s1);
    size_t setLen = ft_strlen(set);
    char *substr = malloc(s1Len +1);
    if (substr == NULL)
    {
        return substr;
    }
    
    int pref = ft_strncmp(s1, set, setLen);
    int suf = ft_strncmp(&s1[s1Len - setLen], set, setLen);

    // printf("Preffix %d\n", ft_strncmp(s1, set, setLen));
    // printf("Suffix %d\n", ft_strncmp(&s1[(ft_strlen(s1) - setLen)], set, setLen));

    if (pref == 0 && suf == 0)
    {
        ft_strlcpy(substr, &s1[setLen], s1Len - 2 * (setLen) + 1);
    }
    else if (pref == 0 || suf == 0)
    {
        ft_strlcpy(
            substr,
            pref == 0 ? &s1[setLen] : s1,
            ft_strlen(s1) - setLen + 1);
    }
    else {
        ft_strlcpy(substr, s1, s1Len +1);
    }
    // *(substr + ft_strlen(substr)) = 0;
    return substr;
}

// int main()
// {
//     char s1[] = "frannncefr";
//     char s2[] = "fr";
//     printf("%s \n", ft_strtrim(s1, s2));

//     char s3[] = "frannnce\tfr";
//     char s4[] = "\tfr";
//     printf("%s \n", ft_strtrim(s3, s4));

//     char s5[] = "Hello \t  Please\n Trim me !";
//     char s6[] = " \n\t";
//     printf("%s \n", ft_strtrim(s5, s6));
//     return 0;
// }