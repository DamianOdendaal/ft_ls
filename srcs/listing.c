/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:13 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/11 20:12:27 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// change file name from listing to list options

#include "../includes/ft_ls.h"

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

void	list_add(t_dir **alst, struct dirent *de, char *path)
{
	t_dir *new;

	new = list_init(de, path);
	new->next = *alst;
	*alst = new;
}
