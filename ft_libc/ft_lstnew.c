#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*out_ptr;

	out_ptr = malloc(sizeof(t_list));
	if (out_ptr)
	{
		out_ptr->content = content;
		out_ptr->next = NULL;
	}
	else
	{
		return (NULL);
	}
	return (out_ptr);
}
