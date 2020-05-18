/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 12:41:56 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 20:43:17 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_data(t_list *lst, void *data , t_iterdata_func f)
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst , data, lst->flags);
			lst = lst->next;
		}
	}
}