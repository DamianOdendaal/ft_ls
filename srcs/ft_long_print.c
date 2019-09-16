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


//int		t_print_long(char *dir)
//{
//	struct stat		s_stat;
//	struct password *user;
//	struct group	*group;
//	t_ls_info		*t_info;
//	
//
//	t_info = NULL;
//	ft_print_mode( s_stat);
//	ft_print_perm(perm, s_stat);
//	t_info->hard_links = s_stat.st_nlink;
//	*user = getuuid(s_stat.st_uid);
//	t_info->owner = user->pw_uid;
//	*group = getgroup(s_stat.st_gid);
//	t_info->group = group->gr_gid;
//	bytes = ft_file_size(name);
//	ft_mod_time(curtime);
//	t_info->name = dir;
//	
//	// then printing 
//
//	ft_putstr(t_info->perm);
//	ft_space();
//
//
//	return (1);
//}

int		ft_print_long(char *name, char *dir)
{
	struct passwd 	*pw;
	struct group	*gw;
	t_info			*t_info;
	struct stat 	sbuf;

	if (!(t_info = malloc(sizeof(t_info))))
		perror("t_info: ");
	stat(ft_strjoin(ft_strjoin(name, "/"), dir), &sbuf);
	ft_ls_perm(sbuf, t_info);
	t_info->hlinks = sbuf.st_nlink;
	pw = getpwuid(sbuf.st_uid);
	t_info->owner = pw->pw_name;
	gw = getgrgid(sbuf.st_gid);
	t_info->group = gw->gr_name;
	t_info->bytes = sbuf.st_size;
	t_info->mod_time = ft_ctime(ctime(&sbuf.st_mtime));
	t_info->name = dir;
	

	ft_putstr(t_info->perm);
	ft_putchar(' ');
	ft_putshort(t_info->hlinks);
	ft_putchar(' ');
	ft_putstr(t_info->owner);
	ft_putchar(' ');
	ft_putstr(t_info->group);
	ft_putchar(' ');
	ft_putlongl(t_info->bytes);
	ft_putchar(' ');
	ft_putstr(t_info->mod_time);
	ft_putchar(' ');
	ft_putstr(t_info->name);
	ft_putchar('\n');
	return (1);
}
