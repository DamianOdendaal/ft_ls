/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:19 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 12:55:46 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"




/*
**	Link print is for the special memebers of the list
**	the ones that are symbolic links, This method is 
**	used to get the path to the link 
*/

void	ft_linkprint(char *path, t_dir *ptr)
{
	char		buffer[65];
	char		*tpath;
	char		*tmp;

	ft_bzero(&buffer, 65);
	tmp = ft_strjoin(path, "/");
	tpath = ft_strjoin(tmp, ptr->name);
	ft_strdel(&tmp);

	readlink(tpath, buffer, 65);
	ft_putstr(" -> ");
	ft_putstr(buffer);
	ft_strdel(&tpath);
}


/*
**		Display blocks is a method used to help us when we call
**		long print and long print no owner,  The blocks are the first 
**		thing we see when we run these methods
*/

void	show_block(t_dir *ptr, unsigned char flags)
{
	int i;

	i = 0;
	ft_putstr("total ");
	while (ptr)
	{
		if ((ptr->name[0] == '.' && flags & 2) || ptr->name[0] != '.')
			i += ptr->block;
		ptr = ptr->next;
	}
	ft_putnbr(i/2);
	ft_putstr("\n");
	
}




/*
**		A method to iterate over a given list and print it back to 
**		the standard output
*/

 void	quick_print_list(t_dir *list, unsigned char flags)
{
	

	while (list != NULL)
	{
		if (flags & 2)
		{
			ft_putstr(list->name);
			ft_putchar('\t');
			if (list->next == NULL)
					ft_putchar('\n');
			list = list->next;
		}
		else
		{
			if (list->name[0] != '.')
			{
				ft_putstr(list->name);
				ft_putchar('\t');
				if (list->next == NULL)
					ft_putchar('\n');
			}
			list = list->next;
		}
	}
}


void quick_print_l(t_dir *head, unsigned char flags) 
{
    t_dir *current = head;

    while (current != NULL) 
	{
		if (!(flags & 2) && (current->name[0] == '.'))
		{
			current = current->next;
			continue;
		}
		if (current->next == NULL)
		{
			ft_putchar('\n');
			break;
		}
      	ft_putstr(current->name);
		ft_putchar('\t');
        current = current->next;
    }
}


/*
**		Normal print is the method that is called when 
**		no flags are passed and we only run ./ft_ls
*/

void	normal_print(t_dir *list, unsigned char flags)
{
	static t_dir 		*dir_ptr;

	dir_ptr = sort(list);
	while (dir_ptr != NULL)
	{
		if (flags & 2)
		{
			ft_putstr(dir_ptr->name);
			ft_putchar('\t');
			if (dir_ptr->next == NULL)
					ft_putchar('\n');
			dir_ptr = dir_ptr->next;
		}
		else
		{
			if (dir_ptr->name[0] != '.')
			{
				ft_putstr(dir_ptr->name);
				ft_putchar('\t');
				if (dir_ptr->next == NULL)
					ft_putchar('\n');
			}
			dir_ptr = dir_ptr->next;
		}
	}
}


/*
**		The method that will be called to do the long print format 
**		with permissions, user and group owner , file size in 
**		bytes , the time the content that is being listed was 
**		last modified and finally the name of the file
*/

void	time_print_list(t_dir *list, unsigned char flags, char *path)
{
	t_dir *ptr;
	t_dir *ptr2;

	ptr = quick_sort_time(&list, flags);
	ptr2 = quick_sort_time(&list, flags);
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

/*
**		A method used for the -a flag,  gets all values
**		sorts them lexographically and prints them
*/

void	all_printer(t_dir *list, unsigned char flags)
{
	t_dir *sorted;

	sorted = sort(list);
	quick_print_list(sorted, flags);
}


/*
**		Print output is a method that does the part that we see
**		we check what the value of the flags are and based on that 
**		we will call the needed sorting function then print
*/

void	print_output(t_dir *list, unsigned char flags, char *path)
{
	t_dir	*result;

	if ((flags & 1) && (flags & 16))
		time_print_list(list, flags, path);
	else if (flags & 1)
		print_list(list, flags, path);
	else if (flags & 2)
		all_printer(list, flags);
	else if (flags & 8)
	{
		result = sort(list);
		reverse_list(&result, flags);

		quick_print_list(result, flags);
	}
	else if (flags & 32)
		supress_owner_print_list(list, flags, path);
	else if (flags & 16)
	{
		sort_list(&list, flags);
		quick_print_list(list, flags);
	}
	else if (flags & 64)
	{
		result = sort(list);
		file_per_line(result, flags);
	}
	else
		normal_print(list, flags);
}
