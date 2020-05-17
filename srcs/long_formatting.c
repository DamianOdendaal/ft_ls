/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_formatting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 14:13:46 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/17 14:15:57 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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

void	long_print_format(t_dir *lst, char *path)
{
	if ((S_ISLNK(lst->mode)))
		ft_putstr("l");
	else
		ft_putstr((S_ISDIR(lst->mode)) ? "d" : "-");
	ls_permissions(lst);
	content_details(lst, path);
	ft_putchar('\n');
}

/*
**		Method to get the permissions of the contents
**		that we have stored in our list and to make 
**		code more modular
*/

void	ls_permissions(t_dir *lst)
{
	ft_putstr((lst->mode & S_IRUSR) ? "r" : "-");
	ft_putstr((lst->mode & S_IWUSR) ? "w" : "-");
	ft_putstr((lst->mode & S_IXUSR) ? "x" : "-");
	ft_putstr((lst->mode & S_IRGRP) ? "r" : "-");
	ft_putstr((lst->mode & S_IWGRP) ? "w" : "-");
	ft_putstr((lst->mode & S_IXGRP) ? "x" : "-");
	ft_putstr((lst->mode & S_IROTH) ? "r" : "-");
	ft_putstr((lst->mode & S_IWOTH) ? "w" : "-");
	ft_putstr((lst->mode & S_IXOTH) ? "x " : "- ");
}

/*
**		A helper method for the -l flag. This is a 
**		method used to print all of the details of the 
**		content we have ,  the content printed is the
**		content after the permissions of the file
*/

void 	content_details(t_dir *lst, char *path)
{
	ft_putnbr(lst->nlink);
	ft_putstr("\t");
	ft_putstrTab(lst->gid);
	ft_putnbr(lst->size);
	ft_putstr("\t");
	convert_date(ctime(&lst->ntime));
	ft_putstr(lst->name);
	
	if ((S_ISLNK(lst->mode)))
		ft_linkprint(path, lst);
}