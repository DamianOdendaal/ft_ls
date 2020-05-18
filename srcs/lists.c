/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:30 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 12:58:08 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"



/*
**	list init is the method that allows us to create a 
**	new list so that we are able to store the contents that we 
**	will use to perform operations later in the task
*/

t_dir	*create_ls_node(struct dirent *de, char *path)
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

	new->time = sb.st_mtime;
	new->ntime = sb.dodoTime;
	new->block = sb.st_blocks;
	new->next = NULL;
	free(tmp);
	free(path2);
	return (new);
}

/*
**		After creating a list and using malloc to allocate memory 
**		for name to be stored in the list we are going to need to 
**		deallocate the memory. We create a method that free's all of the 
**		name in the list then make it point to null
*/

// 
static void node_del(t_dir *scanner)
{
        ft_strdel(&scanner->name);
        scanner->nlink = 0;
        scanner->block = 0;
        ft_strdel(&scanner->uid);
        ft_strdel(&scanner->gid);
        scanner->size = 0;
        scanner->time = 0;
        scanner->ntime = 0;
        scanner->type = 0;
        scanner->next = NULL;
        free(scanner);
}


void    lst_del(t_dir **head)
{
    t_dir *scanner;
    t_dir *next;

    scanner = (*head)->next;
	node_del(*head);

    while (scanner != NULL)
    {
        next = scanner->next;
		node_del(scanner);
		scanner = next;
    }

}


/*
**	List add allows us to initialize a new node
**	and add it to an existing list
*/

void	list_add(t_dir **alst, struct dirent *de, char *path)
{
	t_dir *new;

	new = create_ls_node(de, path);
	new->next = *alst;
	*alst = new;
}
