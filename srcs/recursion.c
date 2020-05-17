/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:26 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/17 13:39:01 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**		Our recursion method where we make use of mutual recursion
**		between our ls method and our recursion method here. We first check
**		what the type is. Under Unix, value 8 is a regular file and 4 is a directory.
**      There after we append a forward slash if we found that something is a dir
**      then we append the dir name and start the process over till we no longer can
*/

void	recursion(t_dir *list, unsigned char flags, char *path)
{
	t_dir	*ptr;
	char	*slash_path;
	char	*full_path;

	ptr = list;
	if (flags & 4)
		while (ptr != NULL)
		{
			if ((ptr->type == 4) && (ft_strcmp(ptr->name, ".") != 0)
			&& (ft_strcmp(ptr->name, "..") != 0))
			{
				if (!(flags & 2) && (ptr->name[0] == '.'))
				{
					ptr = ptr->next;
					continue ;
				}
				slash_path = ft_strjoin("/", ptr->name);
				full_path = ft_strjoin(path, slash_path);
				free(slash_path);
				ft_ls(full_path, flags);
				free(full_path);
			}
			ptr = ptr->next;
		}
}
