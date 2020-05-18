/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:52:57 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 21:47:56 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_lstiteroptions(t_list *lst,  unsigned char option,void (*f)(t_list *elem, unsigned char option))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst, option);
			lst = lst->next;
		}
	}
}

void 	print_name(t_list *list, void *path, unsigned char fl)
{
	t_dir *dir;
	t_dir *next;	

	(void)path;
	dir = (t_dir *)list->content;
	next = (t_dir *)list->next;


	// if (!fl)
	// 	dir = sort(list);

	if (!(fl & FLAG_a) && dir->name[0] != '.')
	{
		ft_putstr(dir->name);
		ft_putchar('\t');
	}
	if (next == NULL)
		ft_putchar('\n');



}

void 	dir_del(void *dir_data, size_t dir_data_size)
{
	(void)dir_data_size;
	t_dir *dir;
	dir = (t_dir *)dir_data;
	free(dir->uid);
	free(dir->gid);
	free(dir->name);
	free(dir);
}


/*
**	This is the method where we take in the contents 
**	from the directory we would like to list 
**	store it in a list and do what needs to be done 
**	based on the flags that are given
*/

void	ft_ls(char *d_path, unsigned char flags)
{
	DIR				*dire;
	struct dirent	*entries;
	t_list			*content;
	t_dir 			data;
	t_recurse_data recurse_data;

	content = NULL;
	entries = NULL;
	dire = opendir(d_path);
	if (error_handle(d_path, dire, errno) == 1)
		return ;

	while ((entries = readdir(dire)))
	{
		get_file_data(&data, entries, d_path);
		ft_lstadd(&content, ft_lstnew(&data, sizeof(data)));
	}
	ft_MergeSort(&content,  choose_compare(flags));
	
	content->flags = flags;
	ft_lstiter_data(content, d_path, choose_print(flags));

	recurse_data.path = d_path;
	recurse_data.flags = flags;
	if (flags & 4)
		ft_lstiter_data(content, &recurse_data, recurse);
	ft_lstdel(&content, dir_del);
	closedir(dire);
}


/*
**		confirm args is a method used to confirm what was
**		given in,  there are 3 return values. If the method 
**		returns 0 we didn't encounter any issues. If the method 
**		returns 1 then we are not using a valid option. If the method
**		returns 2 then we have passed no flags after the - 
*/

int		confirm_args(int ac, char *av[], unsigned char flags)
{
	int i;
	int check;
	(void)flags;
	i = 1;
	check = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			ft_ls(av[i], flags);
			check = 1;
		}
		if (av[i][0] == '-' && av[i][1] == '\0')
			check = 2;
		i++;
	}
	return (check);
}





int		main(int ac, char *av[])
{
	unsigned char	flags;
	int				check;

	check = 0;
	flags = inspect_flags(ac, av);
	if (ac == 1)
		ft_ls(".", flags);
	else
	{
		check = confirm_args(ac, av, flags);
		if (check == 0)
			ft_ls(".", flags);
	}
	return (0);
}