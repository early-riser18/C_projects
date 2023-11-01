#include <stdio.h>
#include <libc.h>

static char get_hex_digit(unsigned int decimal, int uppercase)
{
	if (decimal > 15)
	{
		return (0);
	}
	else if (decimal < 10)
	{
		return (decimal + '0');
	}
	else
	{
		if (uppercase == 1)
		{
			return (decimal + 55);
		}
		else
		{
			return (decimal + 87);
		}
	}
}
char *ft_printf_itoh(unsigned long long num, int uppercase, int hex_prefix)
{
	int r;
	int i;
	int j;
	char hex_str[19] = {0};
	char *output;

	output = malloc(sizeof(char) * 19);
	if (!output)
	{
		printf("Allocation failed");
		return (NULL);
	}
	i = 0;
	j = 0;
	if (hex_prefix)
	{
		output[0] = '0';
		output[1] = 'x';
		if (uppercase == 1)
		{
			output[1] = 'X';
		}
		j = 2;
	}
	do
	{
		r = num % 16;
		num = (num - r) / 16;
		hex_str[i] = get_hex_digit(r, uppercase);
		i++;
	} while (num > 0);
	while (i >= 0)
	{
		i--;
		output[j] = hex_str[i];
		j++;
	}
	return (output);
}
