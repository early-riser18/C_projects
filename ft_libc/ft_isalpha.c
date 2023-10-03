int ft_isalpha(int c)
{
    // Returns true if c is an alphabetic character (a letter).
    return ((64 < c && c < 91) || (96 < c && c < 123));
}
