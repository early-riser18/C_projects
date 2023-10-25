#include <stdarg.h>
#include <stdio.h>
#include <libc.h>

static char	*interpret_type(char c, va_list ptr)
{	
	char * tst;

	switch (c)
	{
		case 'c':
			*tst = (char)va_arg(ptr, int);
			return tst;
	
		case 's':
			tst = va_arg(ptr, int);
			// NEED TO FIGURE OUT HOW TO DO STRINGS

		default:
			return NULL;
	}
}

int	ft_printf(const char *foo, ...)
{
	va_list vars_ptr;
	int i;
	char * tstReturn;
	va_start(vars_ptr, foo);

	i = 0;

	while (foo[i])
	{
		tstReturn = interpret_type(foo[i], vars_ptr);
		printf("%s\n", tstReturn); // Careful if value is not null terminated!
		i++;
	}


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
	ft_printf("c",'z');
	// printf("%10d \n", 'c');

	return 0;
}
