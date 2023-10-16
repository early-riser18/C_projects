#include "libft.h"

static int	ft_power(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent > 0)
	{
		result *= base;
		exponent--;
	}
	return (result);
}

int	ft_atoi(const char *string)
{
	char	sign;
	char	parsed_str[12] = {0};
	size_t	str_len;
	size_t	it;
	int		sum;
	size_t	i;

	it = 0;
	sum = 0;
	sign = 1;
	i = 0;
	while (!ft_isdigit(*string) && (*string != '-' || *string == '+'))
	{
		string++;
	}
	if (*string == '-')
	{
		sign *= -1;
		string++;
	}
	while (*string && sizeof(parsed_str) > 0)
	{
		if (ft_isdigit(*string))
		{
			parsed_str[it] = *string;
			it++;
			string++;
		}
		else
		{
			break ;
		}
	}
	str_len = ft_strlen(parsed_str);
	while (parsed_str[i])
	{
		sum += (parsed_str[i] - 48) * ft_power(10, str_len - 1 - i);
		i++;
	}
	return (sum * sign);
}
