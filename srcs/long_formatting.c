/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_formatting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 14:13:46 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 21:33:54 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**		Long print format with no owner is the method called for the -g flag
** 		here we check the permissions of the file , then the owners,
** 		the only difference here is we dont print the list owner , only group
*/

void	long_print_no_owner(t_list *lst, void *path, unsigned char fl)
{

    t_dir *the_things;

    the_things = (t_dir *)lst->content;
	
	if (!(fl & FLAG_a) && the_things->name[0] == '.')
	{
		lst = lst->next;
	}
	// else if ((fl & FLAG_a) && the_things->name[0] == '.')
	// {
	// 	// ft_putstr(the_things->name);
	// 	// ft_putchar('\t');
	// }


	// if (lst->next == NULL)
	// 	ft_putchar('\n'); 


	if ((S_ISLNK(the_things->mode)))
		ft_putstr("l");
	else
		ft_putstr((S_ISDIR(the_things->mode)) ? "d" : "-");
	ls_permissions(lst);
	content_details(lst, path);
	ft_putchar('\n');
}

/*
**		Long print format is the method called for the -l flag
** 		here we check the permissions of the file , then the owners,
**		the number of links the file has. The file size in bytes and then
** 		we print the name of the file after printing all of these details
*/

void	long_print_format(t_list *lst, void *path, unsigned char fl)
{
    t_dir *the_things;

    the_things = (t_dir *)lst->content;

	if ((!(fl & FLAG_a) && the_things->name[0] == '.' ))
		the_things = lst->next->content;


	if ((S_ISLNK(the_things->mode)))
		ft_putstr("l");
	else
		ft_putstr((S_ISDIR(the_things->mode)) ? "d" : "-");
	ls_permissions(lst);
	content_details(lst, path);
	ft_putchar('\n');
}

/*
**		Method to get the permissions of the contents
**		that we have stored in our list and to make 
**		code more modular
*/

void	ls_permissions(t_list *lst)
{
    t_dir *the_things;

    the_things = (t_dir *)lst->content;

	ft_putstr((the_things->mode & S_IRUSR) ? "r" : "-");
	ft_putstr((the_things->mode & S_IWUSR) ? "w" : "-");
	ft_putstr((the_things->mode & S_IXUSR) ? "x" : "-");
	ft_putstr((the_things->mode & S_IRGRP) ? "r" : "-");
	ft_putstr((the_things->mode & S_IWGRP) ? "w" : "-");
	ft_putstr((the_things->mode & S_IXGRP) ? "x" : "-");
	ft_putstr((the_things->mode & S_IROTH) ? "r" : "-");
	ft_putstr((the_things->mode & S_IWOTH) ? "w" : "-");
	ft_putstr((the_things->mode & S_IXOTH) ? "x " : "- ");
}

/*
**		A helper method for the -l flag. This is a 
**		method used to print all of the details of the 
**		content we have ,  the content printed is the
**		content after the permissions of the file
*/

void 	content_details(t_list *lst, char *path)
{
    t_dir *the_things;

    the_things = (t_dir *)lst->content;

	ft_putnbr(the_things->nlink);
	ft_putstr("\t");
	ft_putstrTab(the_things->gid);
	ft_putnbr(the_things->size);
	ft_putstr("\t");
	convert_date(ctime(&the_things->ntime));
	ft_putstr(the_things->name);
	
	if ((S_ISLNK(the_things->mode)))
		ft_linkprint(path, lst);
}