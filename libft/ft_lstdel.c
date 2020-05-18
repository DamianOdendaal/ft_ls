/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:18:31 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 12:11:35 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && (*alst) && del)
	{
			ft_lstdel(&(*alst)->next, del);
			del((*alst)->content, (*alst)->content_size);
			free((*alst));
	}
	return ;
}
