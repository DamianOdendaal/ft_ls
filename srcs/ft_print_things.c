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

void	print_long(t_info *info, int z)
{
	ft_putstr(info[z].perm);
	ft_putchar(' ');
	ft_putnbr(info[z].links);
	ft_putchar(' ');
	ft_putstr(info[z].owner);
	ft_putchar(' ');
	ft_putstr(info[z].group);
	ft_putchar(' ');
	ft_putnbr(info[z].bytes);
	ft_putchar(' ');
	ft_putstr(info[z].m_time);
	ft_putchar(' ');
	ft_putstr(info[z].direct_n);
	ft_putchar('\n');
}
