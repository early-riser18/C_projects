#include "libft.h"
#include <libc.h>
#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	char		**split_ar;
	char		**tmp_ptr;
	char		*occu;
	int			len_split;
	long int	actual_alloc;
	char		**resized_arr;
	
	split_ar = (char **)malloc(sizeof(char *) * ft_strlen(s));
	tmp_ptr = split_ar;
	while (*s)
	{
		occu = ft_memchr(s, c, ft_strlen(s));
		len_split = (occu == NULL ? ft_strlen(s) : occu - s);
		if (len_split < 1)
		{
			s++;
			continue ;
		}
		*tmp_ptr = (char *)malloc(len_split + 1);
		if (tmp_ptr == NULL)
		{
			printf("Allocation failed\n");
			return (NULL);
		}
		ft_strlcpy(*tmp_ptr, s, len_split + 1);
		s += (occu == NULL ? len_split : len_split + 1);
		tmp_ptr++;
	}
	actual_alloc = (tmp_ptr - split_ar);
	resized_arr = (char **)malloc(sizeof(char *) * (actual_alloc + 1));
	if (resized_arr == NULL)
	{
		printf("Allocation failed\n");
		return (NULL);
	}
	for (int i = 0; i < actual_alloc; i++)
	{
		resized_arr[i] = split_ar[i];
	}
	resized_arr[(actual_alloc)] = NULL;
	free(split_ar);
	return (resized_arr);
}
