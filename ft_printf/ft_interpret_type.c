#include <libc.h>
#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_interpret_type(char c, va_list *va)
{	
	char	*var_str;
	char	*temp;
	int		i;

	switch (c)
	{
		case 'c':
		var_str = malloc(sizeof(char) + 1); 
		var_str[0] = (char)va_arg(*va, unsigned int);
		var_str[1] = 0;
		break;

		case 's':
		temp = va_arg(*va, char*);
		i = 0;
		var_str = malloc(ft_strlen(temp) + 1);
		if (!var_str) 
		{
			printf("Allocation failed");
			return (NULL);
		}
		while ((size_t)i < ft_strlen(temp) + 1)
		{
			var_str[i] = temp[i];
			i++;
		}
		break;

		case '%':
		var_str = malloc(sizeof(char) + 1); 
		var_str[0] = '%';
		var_str[1] = 0;
		break;

		case 'i': 
		var_str = ft_printf_itoa(va_arg(*va,long int), 0);
		break;

		case 'd':	
		var_str = ft_printf_dtoa(va_arg(*va, double));
		break;

		case 'u':
		var_str = ft_printf_itoa((unsigned long int)va_arg(*va, unsigned long int), 1);
		break;

		case 'p':
		var_str = ft_printf_itoh((unsigned long long)va_arg(*va, void *), 0, 1);
		break;

		case 'x':
		var_str = ft_printf_itoh(va_arg(*va, unsigned long long), 0, 0);
		break;

		case 'X':
		var_str = ft_printf_itoh(va_arg(*va, unsigned long long), 1, 0);
		break;

		default:
		printf("convertor '%%%c' invalid.\n", c);
		return (NULL);
	}
	return var_str;
}