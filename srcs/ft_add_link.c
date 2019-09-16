#include "../includes/ft_ls.h"

// add a struct in your .h file that has a pointer to next and to prev for doubly linked list 

t_dlink		ft_add_node(t_dlink *list, char *name)
{
	t_dlink	*temp;
	temp = (t_dlink *)malloc(sizeof(t_dlink));
	if (temp)
	{
		temp = name;
		temp->next = list;
	}
	return (temp);
}
