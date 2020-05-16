/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:26:41 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/16 17:02:26 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



/*
**		Method used to get the last name index of a linked list 
*/

char		*get_last_name(t_dir *list)
{
	if (list == NULL)
		return NULL;
	  while(list->next != NULL)
            list = list->next;
		return (list->name);
}

/*
**  Helper function for sorting to swap values that are
**  passed in
*/

t_dir	*lst_swap(t_dir *value1, t_dir *value2)
{
	value1->next = value2->next;
	value2->next = value1;
	return (value2);
}


/*
**      Method to sort list according to time , Method used for the
**      -t flag using a recursive bubble sort 
*/

t_dir	*sort_time(t_dir *lst)
{
	if (!lst)
		return (NULL);

	if (lst->next && (lst->time < lst->next->time))
		lst = lst_swap(lst, lst->next);

	if (lst->next && (lst->ntime < lst->next->ntime))
		lst = lst_swap(lst, lst->next);

	lst->next = sort_time(lst->next);

	if (lst->next && (lst->next && lst->time < lst->next->time))
	{
		lst = lst_swap(lst, lst->next);
		lst->next = sort_time(lst->next);
	}
	else if (lst->next && lst->time == lst->next->time)
	{
		if (lst->next && (lst->ntime < lst->next->ntime))
		{
			lst = lst_swap(lst, lst->next);
			lst->next = sort_time(lst->next);
		}
	}
	return (lst);
}

void    ft_thelstadd(t_dir **alst, t_dir *new)
{
    
    if (new)
    {
        new->next = *alst;
        *alst = new;
    }
}

void	sort_list(t_dir **begin, short flags)
{
	char 	*content_name;

	t_dir *newNode;

	newNode = (t_dir *)malloc(sizeof(newNode));

	if (flags & 16)
	{

		*begin = sort_time(*begin);
		content_name = get_last_name(*begin);
    	newNode->name = content_name; 
		newNode->next = NULL; 
		// printf("this is the content name ->%s\n", content_name);
		ft_thelstadd(begin, newNode);
	}
}


