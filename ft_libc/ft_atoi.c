#include "libft.h"

int	ft_atoi(const char *string)
{
	char	sign;
	int		sum;
	size_t	i;

	sum = 0;
	sign = 1;
	i = 0;
	while (string[i] && !ft_isdigit(string[i]) && string[i] != '\e')
	{
		if (string[i] == '-')
		{
			sign *= -1;
			i++;
			break ;
		}
		else if (string[i] == '+')
		{
			i++;
			break ;
		}
		i++;
	}
	while (string[i] && ft_isdigit(string[i]))
	{
		sum = sum * 10 + string[i] - '0';
		i++;
	}
	return (sum * sign);
}
