/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:19 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/14 09:02:20 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"



// when do we use this method?
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


// changw this method to only take in the t_dir and print the name
// take out the flags parameter here and alll other places then make it putstr only
void	out_a(t_dir *lst, unsigned char flags)
{
	// create a method that sprts alphabetically 
	if (flags & 2)
		ft_putstr(lst->name);
	else
		ft_putstr(lst->name);
}

// the method used for -g flag
void	long_print_no_owner(t_dir *lst, char *path, unsigned char flags)
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
	// ft_putstrTab(lst->uid);
	ft_putstrTab(lst->gid);
	ft_putnbr(lst->size);
	ft_putstr("\t");
	convert_date(ctime(&lst->mtime));
	out_a(lst, flags);

	// TODO: What is link print
	if ((S_ISLNK(lst->mode)))
		ft_linkprint(path, lst);
	ft_putchar('\n');
}

// change to ft_print_long_format
void	long_print_format(t_dir *lst, char *path, unsigned char flags)
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
	convert_date(ctime(&lst->mtime));
	out_a(lst, flags);

	// TODO: What is link print
	if ((S_ISLNK(lst->mode)))
		ft_linkprint(path, lst);
	ft_putchar('\n');
}

// see where i use this and see display blocks
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
			long_print_format(ptr, path, flags);
		else if (ft_strncmp(ptr->name, ".", 1) != 0)
			long_print_format(ptr, path, flags);
		ptr = ptr->next;
	}
}


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
			long_print_no_owner(ptr, path, flags);
		else if (ft_strncmp(ptr->name, ".", 1) != 0)
			long_print_no_owner(ptr, path, flags);
		ptr = ptr->next;
	}
}


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


void quick_print_list(t_dir *head) 
{
    t_dir *current = head;

    while (current != NULL) 
	{
	
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


void	standard_out(t_dir *list, unsigned char flags)
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

void	print_output(t_dir *list, unsigned char flags, char *path)
{
	t_dir	*result;
	size_t 	len;
	if (flags & 1)
	// do a check that if long and r are on then we must reverse then pass that list to this method
		print_list(list, flags, path);

	else if (flags & 8)
	{
		result = sort(list);
		reverse_list(&result, flags);
		quick_print_list(result);
	}
	else if (flags & 32)
		supress_owner_print_list(list, flags, path);

		// test if this works when you get back 
	else if (flags & 16)
	{
		len = node_count(list);
		sort_time(list, len);
	}
		// t_sorting(list);
	// merge_sort(&list, flags);

	else if (flags & 64)
	{
		result = sort(list);
		file_per_line(result, flags);
	}

	else
		standard_out(list, flags);
	
}
