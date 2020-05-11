/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:30 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/07 20:54:39 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// change to initialize list 

t_dir	*setting_lst(struct dirent *de, char *path)
{
	t_dir		*new;
	struct stat	sb;
	char		*path2;
	char		*tmp;

	if (!(new = (t_dir *)malloc(sizeof(*new))))
		return (NULL);
	tmp = ft_strjoin(path, "/");
	path2 = ft_strjoin(tmp, de->d_name);
	lstat(path2, &sb);
	new->name = ft_strdup(de->d_name);
	new->nlink = sb.st_nlink;
	new->uid = username_to_string(sb.st_uid);
	new->gid = groupName_to_string(sb.st_gid);
	new->size = sb.st_size;
	new->type = de->d_type;
	new->mode = sb.st_mode;
	new->mtime = sb.st_mtime;
	new->block = sb.st_blocks;
	new->next = NULL;
	free(tmp);
	free(path2);
	return (new);
}
