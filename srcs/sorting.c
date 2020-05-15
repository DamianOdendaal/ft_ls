/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:33 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/15 09:01:10 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


/*
**	Method to sort values in accending order according to their 
**	ascii values 
*/

static t_dir	*sort_ascii(t_dir *list)
{
	if (!list)
		return (NULL);
	if (list->next && ft_charcasecmp(list->name[0], list->next->name[0]) > 0)
		list = lst_swap(list, list->next);
	list->next = sort_ascii(list->next);
	if (list->next && ft_charcasecmp(list->name[0], list->next->name[0]) > 0)
	{
		list = lst_swap(list, list->next);
		list->next = sort_ascii(list->next);
	}
	return (list);
}

/*
**		A method used to help sort ascii, the method returns a static variable.
**		We need the value that is returned between invocations of the method
**		to be kept so that the list can be sorted successfully
*/

t_dir		*sort(t_dir *unsorted)
{
	static t_dir	*sorted;

	sorted = sort_ascii(unsorted);
	return (sorted);
}


/*
	Method used to take in a list and reverse it,  a helper function for 
	when we use -r with ft_ls
*/

void		reverse_list(struct s_dir **head_ref, unsigned char flags)
{
	struct s_dir *prev;
	struct s_dir *current;
	struct s_dir *next;

	prev = NULL;
	current = *head_ref;
	next = NULL;
	while (current != NULL)
	{
		if (current->name[0] == '.' && !(flags & 2))
		{
			if (current->name[0] == 'a')
				continue;
			else
				current = current->next;
		}
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}









