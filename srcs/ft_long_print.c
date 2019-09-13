/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:35:45 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/12 15:07:25 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


int		t_print_long(char *dir, char *name)
{
	struct stat		s_stat;
	struct password	uid;
	struct group	gid;
	t_ls_info		*t_info;
	

	ft_print_mode(t_info, *st);
	ft_print_perm(t_info, *st);
	t_info->hard_links = st->st_nlink;
	uid = getuuid(s_stat.st_uid);
	t_info->owner = uid.pw_uid;
	gid = getgroup(s_stat.st_gid);
	t_info->group = gid.pw_gid;
	bytes = ft_file_size(name);
	//ft_mod_time(curtime);
	t_info->name = dir;
	
	// then printing 

	ft_putstr(t_info->perm);
	ft_space();


	return (1);
}

