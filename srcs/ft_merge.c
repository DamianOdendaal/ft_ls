/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:21:20 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 19:37:09 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


static t_list *SortedMerge(t_list *a, t_list *b, int (*compare)(void *a, void *b)) 
{ 
    t_list *result = NULL; 
    int comp;
    

    
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 

    comp = (*compare)(a->content, b->content);
    if (comp <= 0) 
    { 
        result = a; 
        result->next = SortedMerge(a->next, b, compare); 
    } 
    else 
    { 
        result = b; 
        result->next = SortedMerge(a, b->next, compare); 
    } 
    return (result); 
} 

static void ft_FrontBackSplit(t_list *source, 
                    t_list ** frontRef, t_list **backRef) 
{ 
    t_list *fast; 
    t_list *slow; 
    slow = source; 
    fast = source->next; 
    while (fast != NULL)
    { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
}

void ft_MergeSort(t_list ** headRef,  int (*compare)(void *a, void *b)) 
{ 
    t_list * head = *headRef; 
    t_list * a; 
    t_list * b; 
    if ((head == NULL) || (head->next == NULL))
    { 
        return; 
    } 
    ft_FrontBackSplit(head, &a, &b); 
    ft_MergeSort(&a, compare); 
    ft_MergeSort(&b, compare); 
    *headRef = SortedMerge(a, b, compare); 
} 


