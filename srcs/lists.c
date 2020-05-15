/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:30 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/15 19:47:21 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**	list init is the method that allows us to create a 
**	new list so that we are able to store the data that we 
**	will have to sort and later print back to the stdout 
*/

t_dir	*list_init(struct dirent *de, char *path)
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
	new->ntime = sb.st_mtime;
	new->block = sb.st_blocks;
	new->next = NULL;
	free(tmp);
	free(path2);
	return (new);
}

/*
**		After creating a list and using malloc to allocate memory 
**		for data to be stored in the list we are going to need to 
**		deallocate the memory. We create a method that free's all of the 
**		data in the list then make it point to null
*/

void	delete_list(t_dir **list)
{
	t_dir *content;
	t_dir *next;

	content = *list;
	while (content)
	{
		next = content->next;
		free(content->name);
		free(content);
		content = next;
	}
	*list = NULL;
}

/*
**	List add allows us to create a new list and store 
**	the needed data in the list if there was not a list that 
** 	was existent already
*/

void	list_add(t_dir **alst, struct dirent *de, char *path)
{
	t_dir *new;

	new = list_init(de, path);
	new->next = *alst;
	*alst = new;
}
