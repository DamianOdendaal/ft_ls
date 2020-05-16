/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:19 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/16 20:19:24 by dodendaa         ###   ########.fr       */
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

void	display_blocks(t_dir *ptr, unsigned char flags)
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
	ft_putnbr(i);
	ft_putstr("\n");
}


/*
**		Long print format with no owner is the method called for the -g flag
** 		here we check the permissions of the file , then the owners,
** 		the only difference here is we dont print the list owner , only group
*/

void	long_print_no_owner(t_dir *lst, char *path)
{
	if ((S_ISLNK(lst->mode)))
		ft_putstr("l");
	else
		ft_putstr((S_ISDIR(lst->mode)) ? "d" : "-");

	ft_putstr((lst->mode & S_IRUSR) ? "r" : "-");
	ft_putstr((lst->mode & S_IWUSR) ? "w" : "-");
	ft_putstr((lst->mode & S_IXUSR) ? "x" : "-");
	ft_putstr((lst->mode & S_IRGRP) ? "r" : "-");
	ft_putstr((lst->mode & S_IWGRP) ? "w" : "-");
	ft_putstr((lst->mode & S_IXGRP) ? "x" : "-");
	ft_putstr((lst->mode & S_IROTH) ? "r" : "-");
	ft_putstr((lst->mode & S_IWOTH) ? "w" : "-");
	ft_putstr((lst->mode & S_IXOTH) ? "x " : "- ");
	ft_putnbr(lst->nlink);
	ft_putstr("\t");
	ft_putstrTab(lst->gid);
	ft_putnbr(lst->size);
	ft_putstr("\t");
	convert_date(ctime(&lst->ntime));
	ft_putstr(lst->name);
	if ((S_ISLNK(lst->mode)))
		ft_linkprint(path, lst);
	ft_putchar('\n');
}

/*
**		Long print format is the method called for the -l flag
** 		here we check the permissions of the file , then the owners,
**		the number of links the file has. The file size in bytes and then
** 		we print the name of the file after printing all of these details
*/

void	long_print_format(t_dir *lst, char *path)
{
	if ((S_ISLNK(lst->mode)))
		ft_putstr("l");
	else
		ft_putstr((S_ISDIR(lst->mode)) ? "d" : "-");
	ft_putstr((lst->mode & S_IRUSR) ? "r" : "-");
	ft_putstr((lst->mode & S_IWUSR) ? "w" : "-");
	ft_putstr((lst->mode & S_IXUSR) ? "x" : "-");
	ft_putstr((lst->mode & S_IRGRP) ? "r" : "-");
	ft_putstr((lst->mode & S_IWGRP) ? "w" : "-");
	ft_putstr((lst->mode & S_IXGRP) ? "x" : "-");
	ft_putstr((lst->mode & S_IROTH) ? "r" : "-");
	ft_putstr((lst->mode & S_IWOTH) ? "w" : "-");
	ft_putstr((lst->mode & S_IXOTH) ? "x " : "- ");
	ft_putnbr(lst->nlink);
	ft_putstr("\t");
	ft_putstrTab(lst->uid);
	ft_putstrTab(lst->gid);
	ft_putnbr(lst->size);
	ft_putstr("\t");
	convert_date(ctime(&lst->ntime));
	ft_putstr(lst->name);
	if ((S_ISLNK(lst->mode)))
		ft_linkprint(path, lst);
	ft_putchar('\n');
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
		display_blocks(ptr2, flags);
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
		display_blocks(ptr2, flags);
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
**		This is a method for the -1 flag where we put every file 
**		on its own line 
*/

void file_per_line(t_dir *head, unsigned char flags) 
{
    t_dir *current = head;

    while (current != NULL) 
	{
	
		if ((flags & 2))
		{
			ft_putstr(current->name);
			ft_putchar('\n');
			current = current->next;
		}
		else
		{
			if (current->name[0] != '.')
			{
				ft_putstr(current->name);
				if (current->next != NULL)
					ft_putchar('\n');
			}
		}
		current = current->next;
    }
	ft_putchar('\n');
}


/*
**		A method to iterate over a given list and print it back to 
**		the standard output
*/

void quick_print_list(t_dir *head, unsigned char flags) 
{
    t_dir *current = head;

    while (current != NULL) 
	{
		if (!(flags & 2) && (current->name[0] == '.'))
		{
			current = current->next;
			continue;
		}
      	ft_putstr(current->name);
		ft_putchar('\t');
        current = current->next;
		if (current->next == NULL)
		{
			ft_putchar('\n');
			break;
		}
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
**		Node count is our version of strlen but for a list
**		we count the number of nodes and return that int value
*/

int node_count(t_dir* head) 
{ 
    int count;   
    
    t_dir* current = head; 
    count = 0; 
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; 
} 

/*
**		A method that calls our time sorting function
**		on a list and returns the sorted list
*/

t_dir	    *quick_sort_time(t_dir **begin, short flags)
{
	*begin = sort(*begin);
	if (flags & 16)
		*begin = sort_time(*begin);
	return (*begin);
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
		display_blocks(ptr2, flags);
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
		result = sort(list);
		sort_list(&result, flags);
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
