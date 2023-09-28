// NEEDS RECHECK
int ft_ascii(int c)
{
    // Problem with this approach is that if not an int is passed, it does not compile instead of returning 0.
    // And if it compiles, it always returns 1...
    // could use helper function to handle error but then the main function can accept more than int.
    return (0 <= c && c < 128);
}
