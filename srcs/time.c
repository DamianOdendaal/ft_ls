/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:26:41 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/15 20:44:48 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



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
**      -t flag
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
	if (lst->next && (lst->time < lst->next->time))
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

int	        sort_list(t_dir **begin, short flags)
{
	*begin = sort(*begin);
	if (flags & 16)
		*begin = sort_time(*begin);
	return (1);
}


