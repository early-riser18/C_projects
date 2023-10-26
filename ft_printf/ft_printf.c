#include <stdarg.h>
#include <stdio.h>
#include <libc.h>

static char	*interpret_type(char c, va_list ptr)
{	
	// printf("Interpreting type of |%c|\n", c);
	// Returns a string
	char	*tst;
	int		i;

	switch (c)
	{
		case 'c':
			tst = malloc(sizeof(char) + 1); // Is this causing a memory leak?
			tst[0] = (char)va_arg(ptr, int);
			tst[1] = 0;
			return tst;
	
		case 's':
			tst = va_arg(ptr, char*);
			return tst;

		case '%':
			tst = malloc(sizeof(char) + 1); // Is this causing a memory leak?
			tst[0] = '%';
			tst[1] = 0;
			return tst; 


		default:
			return NULL;
	}
}

int	ft_printf(const char *foo, ...)
{
	va_list	vars_ptr;
	int		i;
	char	*tstReturn;
	va_start(vars_ptr, foo);

	i = 0;

	while (foo[i])
	{
		// printf("Evaluating |%c|\n", foo[i]);
		if (foo[i] == '%')
		{
			i++;
			tstReturn = interpret_type(foo[i],vars_ptr);
			// need error handling if interpret_type returns error.
		} else 
		{
			tstReturn = malloc(2); // is this causing memory leak?
			*tstReturn = foo[i];
			*(tstReturn + 1) = 0;
		}

		while (*tstReturn)
		{
			write(1, tstReturn,1);
			tstReturn++;
		}
		i++;
	}

	va_end(vars_ptr);


	return 0;
}

// va_arg helps me iterate through the variadic arguments
// set up exception when passed argument does not match the specified format
// write the string to stdout. each time you meet a %, check the next arg and interpret it accordingly. if you can't throw error. 
// . + nbr tells you how many digits after the coma to display
// 0 + nbr tells you how many zeros to put first
// nbr tells the field's width and justify right, except when - is preceding the nbr. 
// write to stdout with write 



int main(void)
{

	// ft_printf("ft_printf-> Output is: %% a8 {%s}\n", &"hello"[0]);
	ft_printf("A pct:%%\tan int %i\ta str %s\n", 110,&"hello"[0]);

	// printf("%10d \n", 'c');

	return 0;
}
