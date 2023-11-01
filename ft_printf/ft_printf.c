#include <stdarg.h>
#include <stdio.h>
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

int	ft_printf(const char *foo, ...)
{
	va_list	vars_ptr;
	int		i;
	char	*curr_var_str;
	int		j;

	va_start(vars_ptr, foo);
	i = 0;
	j = 0;
	while (foo[i])
	{
		if (foo[i] == '%')
		{
			i++;
			curr_var_str = ft_interpret_type(foo[i], &vars_ptr);
			write(1, curr_var_str, 1);
			j++;
			write(1, &curr_var_str[1],ft_strlen(curr_var_str) -1);
			j += ft_strlen(&curr_var_str[1]);
			free(curr_var_str);
		}
		else
		{
			write(1, &foo[i],1);
			j++;
		}
		i++;
	}
	va_end(vars_ptr);
	return (j);
}
