/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:12 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/10 16:35:18 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list *insertion_sorter(t_list* head_n)
{
    t_list *x;
    t_list *y;
    t_list *after;
 
    x = head_n; // making x the head node so we dont lose the list
    head_n = NULL;
 
    while(x != NULL)
    {
        after = x;
        x = x->next;
        if (head_n != NULL)
        {
            if(after->content > head_n->content)
            {
                y = head_n;
                while ((y->next != NULL) && (after->content > y->next->content))
                    y = y->next;
                after->next = y->next;
                y->next = after;
            }
            else
            {
                after->next = head_n;
                head_n = after;
            }
        }
        else
        {
            after->next = NULL;
            head_n = after;
        }
    }
    return (head_n);
}