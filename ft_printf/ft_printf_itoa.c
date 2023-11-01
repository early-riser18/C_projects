#include <stdio.h>
#include <libc.h>

static long int	power(int base, int exponent)
{
	long int	result;

	result = 1;
	while (exponent > 0)
	{
		result *= base;
		exponent--;
	}
	return (result);
}

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

static size_t	ft_strlcpy(char *to, const char *from, size_t size)
{
	size_t	from_len;
	size_t	i;

	from_len = ft_strlen(from);
	i = 0;
	if (size > 0)
	{
		while ((i + 1) < size && *from)
		{
			*to = *from;
			from++;
			to++;
			i++;
		}
		*to = 0;
	}
	return (from_len);
}

char	*ft_printf_itoa(long int n, int un_signed)
{
	short int	exponent;
	char		str_nbr[12] = {0};
	int			rm;
	float		r;
	char		*outptr; 
	
	if (un_signed == 1 && n < 0)
	{
		n = 4294967296 + n;
	}
	exponent = 9;
	if (n < 0)
	{
		str_nbr[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		ft_strlcpy(str_nbr, "0", 2);
	}
	else if (n == -2147483648)
	{
		ft_strlcpy(str_nbr, "-2147483648", 12);
	}
	else
	{
		while (exponent >= 0)
		{
			r = (float)n / power(10, exponent);
			if (r >= 1)
			{
				rm = n % power(10, exponent);
				str_nbr[ft_strlen(str_nbr)] = (char)(r - (rm / power(10, exponent)) + 48);
				n = rm;
			}
			else if (str_nbr[0] && str_nbr[ft_strlen(str_nbr) - 1] != '-')
			{
				str_nbr[ft_strlen(str_nbr)] = (char)48;
			}
			exponent--;
		}
	}
	outptr = malloc(sizeof(char) * ft_strlen(str_nbr) + 1);
	ft_strlcpy(outptr, str_nbr, ft_strlen(str_nbr) + 1);
	return (outptr);
}
