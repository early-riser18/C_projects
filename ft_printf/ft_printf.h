#include <stdarg.h>
#ifndef FT_PRINTF
#define FT_PRINTF

int		ft_printf(const char *foo, ...);
char	*ft_interpret_type(char c, va_list *va);
char	*ft_printf_itoa(int n, int un_signed);
char	*ft_printf_dtoa(double num);
char	*ft_printf_itoh(unsigned long long num, int uppercase, int hex_prefix);

#endif