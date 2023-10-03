#include <stdio.h>

int ft_toupper(int c)
{
    return (96 < c && c < 123) ? (c - 32) : c;
}

int main(){
    printf("%c", ft_toupper('e'));
    return 0;
}