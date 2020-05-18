/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:26 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 16:18:20 by dodendaa         ###   ########.fr       */
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

void 	recurse(t_list *list, void *path_data)
{
	t_dir *dir;
	t_recurse_data path;
	char *slash_path;
	char 	*ls_path;


	(void)list;
	path = *(t_recurse_data *)path_data;
	dir = (t_dir *)list->content;
	

	if ((dir->type == 4) && (ft_strcmp(dir->name, ".") != 0)
	&& (ft_strcmp(dir->name, "..") != 0))
	{
		if (!(path.flags & 2) && (dir->name[0] == '.'))
			return ;
		slash_path = ft_strjoin("/", dir->name);
		ls_path = ft_strjoin(path.path, slash_path);

		free(slash_path);
		ft_ls(ls_path, path.flags);
		free(ls_path);
	}

	
}