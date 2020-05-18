/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:30 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 15:24:00 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**	list init is the method that allows us to create a 
**	neow list so that we are able to store the contents that we 
**	will use to perform operations later in the task
*/

void 	get_file_data(t_dir *direct, struct dirent *de, char *path)
{

	char *tmp;
	char *full_path;
	struct stat statt;

	tmp = ft_strjoin(path, "/");
	full_path = ft_strjoin(tmp, de->d_name);
	lstat(full_path, &statt);
	
	direct->name = ft_strdup(de->d_name);
	direct->uid = username_to_string(statt.st_uid);
	direct->gid = groupName_to_string(statt.st_gid);

	direct->nlink = statt.st_nlink;
	direct->size = statt.st_size;
	direct->type = de->d_type;
	direct->mode = statt.st_mode;
	direct->time = statt.st_mtime;
	direct->ntime = statt.dodoTime;
	direct->block = statt.st_blocks;
	free(tmp);
	free(full_path);

}
