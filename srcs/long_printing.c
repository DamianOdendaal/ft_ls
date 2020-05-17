/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 14:02:59 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/17 14:14:15 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**		Similar to print list, this is the method for the -g 
**		flag where we do the long print but we do not include 
**		the list owner
*/ 

void	supress_owner_print_list(t_dir *list, unsigned char flags, char *path)
{
	t_dir *ptr;
	t_dir *ptr2;

	ptr = sort(list);
	ptr2 = sort(list);
	if (flags & 32)
		show_block(ptr2, flags);
	while (ptr != NULL)
	{
		if (flags & 2)
			long_print_no_owner(ptr, path);
		else if (ft_strncmp(ptr->name, ".", 1) != 0)
			long_print_no_owner(ptr, path);
		ptr = ptr->next;
	}
}

/*
**		The method that will be called to do the long print format 
**		with permissions, user and group owner , file size in 
**		bytes , the time the content that is being listed was 
**		last modified and finally the name of the file
*/

void	print_list(t_dir *list, unsigned char flags, char *path)
{
	t_dir *ptr;
	t_dir *ptr2;

	ptr = sort(list);
	ptr2 = sort(list);
	if (flags & 1)
		show_block(ptr2, flags);
	while (ptr != NULL)
	{
		if (flags & 2)
			long_print_format(ptr, path);
		else if (ft_strncmp(ptr->name, ".", 1) != 0)
			long_print_format(ptr, path);
		ptr = ptr->next;
	}
}
