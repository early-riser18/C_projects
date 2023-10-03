#include <stdio.h>

int ft_tolower(int c)
{
    return (64 < c && c < 91) ? (c + 32) : c;
}

// int main(){
//     printf("%c", ft_tolower('P'));
//     return 0;
// }