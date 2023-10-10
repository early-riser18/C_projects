#include <stdio.h>

void *ft_memchr(const void *block, int c, size_t size)
{
    unsigned char *myPtr = (unsigned char *)block;
    for (size_t i = 0; i < size; i++, myPtr++)
    {
        if ((unsigned char)c == *myPtr)
        {
            return myPtr;
        }
    }
    return NULL;
}

// int main()
// {
//     char mylist[] = "hellwo";
//     unsigned char * output = ft_memchr(mylist, 'a', 10);
//     printf(" %s\n",  output);

//     const char str[] = "https://www.tutorialspoint.com";
//     const char ch = 'z';
//     char *ret;

//     ret = ft_memchr(str, ch, 31);

//     printf("String after |%c| is - |%s|\n", ch, ret);
//     return 0;
// }