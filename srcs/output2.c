/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:22 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/07 20:54:42 by dodendaa         ###   ########.fr       */
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
