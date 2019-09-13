/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permissions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:07 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/11 12:29:24 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_mode(t_ls_info *t_info, struct stat st)
{
	t_info = NULL;
	ft_strcpy(t_info->perm, "-");
	if (!t_info)
	 return ;
	else if ((st.st_mode & S_IFMT) == S_IFDIR)
	{
		//t_info->perm[0] = 'd';
		ft_strcpy(t_info->perm, "d");
	}
	else if ((st.st_mode & S_IFMT) == S_IFREG)
	{
  		//t_info->perm[0] = '-';
		ft_strcpy(t_info->perm, "-");
	}
	else if ((st.st_mode & S_IFMT) == S_IFCHR)
	{
  		//t_info->perm[0] = 'c';
		ft_strcpy(t_info->perm, "c");
	}
	else if ((st.st_mode & S_IFMT) == S_IFBLK)
	{
		//t_info->perm[0] = 'b';
		ft_strcpy(t_info->perm, "b");
	}
	else if (st.st_mode & S_IFLNK)
	{
  	//	t_info->perm[0] = 'l';
		ft_strcpy(t_info->perm, "l");
	}
}
void 	ft_print_perm(t_ls_info *t_info, struct stat st)
{
	t_info = NULL;
	ft_strcpy(t_info->perm, "---------");
  t_info->perm[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
  t_info->perm[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
  t_info->perm[3] = (st.st_mode & S_IXUSR) ? 'x' : '-';
  t_info->perm[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
  t_info->perm[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
  t_info->perm[6] = (st.st_mode & S_IXGRP) ? 'x' : '-';
  t_info->perm[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
  t_info->perm[8] = (st.st_mode & S_IWUSR) ? 'w' : '-';
  t_info->perm[9] = (st.st_mode & S_IXUSR) ? 'x' : '-';
     
}
