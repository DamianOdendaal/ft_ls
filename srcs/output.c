/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:19 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 20:32:34 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


/*
**	Link print is for the special memebers of the list
**	the ones that are symbolic links, This method is 
**	used to get the path to the link 
*/

void	ft_linkprint(char *path, t_list *ptr)
{
	char		buffer[65];
	char		*tpath;
	char		*tmp;
	t_dir 		*pointer;

	pointer = (t_dir *)ptr->content;

	ft_bzero(&buffer, 65);
	tmp = ft_strjoin(path, "/");
	tpath = ft_strjoin(tmp, pointer->name);
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

void	show_block(t_list *ptr, unsigned char flags)
{
	int i;
	t_dir *stuff;
	t_dir *next;
	

	stuff = (t_dir *)ptr->content;
	next = (t_dir *)ptr->next;
	i = 0;
	ft_putstr("total ");
	while (ptr)
	{
		if ((stuff->name[0] == '.' && flags & 2) || stuff->name[0] != '.')
			i += stuff->block;
		stuff = next;
	}
	ft_putnbr(i/2);
	ft_putstr("\n");
	
}