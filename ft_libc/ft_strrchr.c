#include <stdio.h>

char *strrchr(const char *string, int c)
{
    char *myPtr = (char *)string;
    while (*myPtr)
    {
        myPtr++;
    }

    myPtr--;
    while (*myPtr)
    {

        if (*myPtr == (char)c)
        {
            return myPtr;
        }
        myPtr--;
    }
    return NULL;
}

// int main()
// {
//     printf("%s\n", strrchr("", 'h'));
//     return 0;
// }