#include <stdio.h>
char *strchr(const char *string, int c)
{
    char *myPtr = (char *)string;
    while (*myPtr)
    {
        if (*myPtr == (char)c)
        {
            return myPtr;
        }
        myPtr++;
    }
    return NULL;
}

// int main()
// {  

//     printf("%s\n", strchr("hello world", 'o'));
//     return 0;
// }