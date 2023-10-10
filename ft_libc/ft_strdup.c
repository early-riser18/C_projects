#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char *ft_strdup(const char* s)
{   
    size_t strByteSize = ft_strlen(s) +1;
    void * returnPtr = malloc(strByteSize);    
    if (returnPtr != NULL){
        ft_strlcpy(returnPtr, s, strByteSize);
    }
    return returnPtr;
}

// int test(int num, const char *string, char *expected)
// {
//     printf("\n-----OUTCOME TEST %d------\n Output |%s|\t Expected result: |%s|\n",
//            num,
//            ft_strdup(string),
//            &expected[0]);
//     return 0;
// }

// int main()
// {
//     test(1, &"hello"[0], "1234");
//     return 0;
// }
