#include "ft_printf.h"
#include <libc.h>

static char	*fract_part_to_str(double num)
{
	int		i;
	int		extract_digit;
	char	*output;

	i = 0;
	num -= (int)num;
	output = malloc(11);
	if (!output)
	{
		printf("Allocation failed;");
		return (NULL);
	}
	if (num < 0)
	{
		num *= -1;
	}
	while (i < 10 && (num + 0.0001) > 0.0001)
	{
		num *= 10;
		extract_digit = (int)(num + 0.01);
		num -= extract_digit;
		output[i] = extract_digit + 48;
		i++;
	}
	output[i] = 0;
	return (output);
}

static int	my_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

static size_t	ft_strlcat(char *to, const char *from, size_t size)
{
	size_t	to_len;
	size_t	from_len;
	size_t	i;

	to_len = my_strlen(to);
	from_len = my_strlen((char *)from);
	if (size <= to_len)
	{
		return (from_len + size);
	}
	to += to_len;
	i = to_len + 1;
	while (*from && i < size)
	{
		*to = *from;
		from++;
		to++;
		i++;
	}
	*to = 0;
	return (to_len + from_len);
}

char *ft_printf_dtoa(double num)
{

	long	int_part;
	char	*output;
	char	*int_str;
	char	*frac_str;

	frac_str = 0;
	int_part = (long)num;
	int_str = ft_printf_itoa(int_part, 0);
	output = malloc(19);
	if (output == NULL)
	{
		printf("Allocation failed");
		return (NULL);
	}
	if (int_part != num)
	{
		frac_str = fract_part_to_str(num);
		ft_strlcat(output, int_str, my_strlen(int_str) + 1);
		output[my_strlen(int_str)] = '.';
		ft_strlcat(&output[my_strlen(int_str) + 1], frac_str, my_strlen(frac_str) + 1);
		free(frac_str);
	}
	else
	{
		ft_strlcat(output, int_str, my_strlen(int_str) + 1);
	}
	free(int_str);
	return (output);
}
