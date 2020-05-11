/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:33 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/11 21:34:57 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


/*
	Helper function for our sort ascii method to swap values 
	based on their ascii value 
*/

t_dir	*lst_swap(t_dir *value_1, t_dir *value_2)
{
	value_1->next = value_2->next;
	value_2->next = value_1;
	return (value_2);
}


/*
	Method to sort values in accending order according to their 
	ascii values 
*/

static t_dir	*sort_ascii(t_dir *list)
{
	if (!list)
		return (NULL);
	if (list->next && ft_charcasecmp(ft_tolower(list->name[0]), ft_tolower(list->next->name[0])) > 0)
		list = lst_swap(list, list->next);
	list->next = sort_ascii(list->next);
	if (list->next && ft_charcasecmp(ft_tolower(list->name[0]), ft_tolower(list->next->name[0])) > 0)
	{
		list = lst_swap(list, list->next);
		list->next = sort_ascii(list->next);
	}
	return (list);
}

t_dir		*sort(t_dir *unsorted)
{
	t_dir	*sorted;

	sorted = sort_ascii(unsorted);
	return (sorted);
}

/*
	Method used to get the value of the names in our list and 
	store them within a string 
*/

char		*get_name(t_dir *list)
{
	char *name;

	name = list->name;
	return (name);
}

/*
	Method used to take in a list and reverse it,  a helper function for 
	when we use -r with ft_ls
*/

// draw a pic here of how this works
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


//see where i use this and how it works
// this method we sort but we sort the modified time
t_dir		*sort_merge_time(t_dir *a, t_dir *b, unsigned int flag)
{
	t_dir *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->mtime > b->mtime && !(flag & 8))
	{
		result = a;
		result->next = sort_merge_time(a->next, b, flag);
	}
	else if (a->mtime < b->mtime && flag & 8)
	{
		result = a;
		result->next = sort_merge_time(a->next, b, flag);
	}
	else
	{
		result = b;
		result->next = sort_merge_time(a, b->next, flag);
	}
	return (result);
}

//see where i use this and how it works



void		merge_sort(t_dir **head_ref, unsigned char flags)
{
	t_dir *head;
	t_dir *a;
	t_dir *b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	inverse_split(head, &a, &b);
	merge_sort(&a, flags);
	merge_sort(&b, flags);

	if (flags & 16)
		*head_ref = sort_merge_time(a, b, flags);
	else
		*head_ref = sort_merge_list(a, b, flags);
}



t_dir		*sort_merge_list(t_dir *a, t_dir *b, unsigned char flags)
{
	t_dir *result;

	result = NULL;
	if (a == NULL)
		return (b);
	
	else if (b == NULL)
		return (a);
	if (!(flags & 8) && ((ft_strcmp(a->name, b->name)) < 0))
	{
		result = a;
		result->next = sort_merge_list(a->next, b, flags);
	}
	else if ((flags & 8) && ((ft_strcmp(a->name, b->name)) > 0))
	{
		result = a;
		result->next = sort_merge_list(a->next, b, flags);
	}
	else
	{
		result = b;
		result->next = sort_merge_list(a, b->next, flags);
	}
	return (result);
}

/*
	A method where we
*/

//ask , when we do this are we just getting the values of the first and last index?
// change name to get halves
void		inverse_split(t_dir *source, t_dir **front_ref, t_dir **back_ref)
{
	t_dir *fast;
	t_dir *slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}
