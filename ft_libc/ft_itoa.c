#include "libft.h"
#include <libc.h>
#include <stdio.h>

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

char	*ft_itoa(int n)
{
	short int	exponent;
	char		str_nbr[12] = {0};
	int			rm;
	float		r;
	float		drm;

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
				drm = rm / power(10, exponent);
				str_nbr[ft_strlen(str_nbr)] = (char)(r - drm + 48);
				n = rm;
			}
			else if (str_nbr[0] && str_nbr[ft_strlen(str_nbr) - 1] != '-')
			{
				str_nbr[ft_strlen(str_nbr)] = (char)48;
			}
			exponent--;
		}
	}
	return (ft_strdup(str_nbr));
}
