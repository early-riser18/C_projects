#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*last;

	new_list = NULL;
	last = NULL;
	while (lst)
	{
		if (!new_list)
		{
			new_list = malloc(sizeof(t_list));
			if (!new_list)
				return (NULL);
			new_list->content = f(lst->content);
			new_list->next = NULL;
			last = new_list;
		}
		else
		{
			last->next = malloc(sizeof(t_list));
			if (!last->next)
			{
				ft_lstclear(&new_list, del);
				return (NULL);
			}
			last = last->next;
			last->content = f(lst->content);
			last->next = NULL;
		}
		lst = lst->next;
	}
	return (new_list);
}
