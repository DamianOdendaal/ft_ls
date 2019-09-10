/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permissions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:07 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/10 16:29:29 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ft_perm(t_ls_info *t_info, struct stat st)
{ 
	if ((st.st_mode & S_IFMT) == S_IFDIR)
		t_info->perm[0] = 'd';
	if ((st.st_mode & S_IFMT) == S_IFREG)
  		t_info->perm[0] = '-';
	if ((st.st_mode & S_IFMT) == S_IFCHR)
  		t_info->perm[0] = 'c';
	if ((st.st_mode & S_IFMT) == S_IFBLK)
		t_info->perm[0] = 'b';
	if (st.st_mode & S_IFLNK)
  		t_info->perm[0] = 'l';
  t_info->perm[1] = (st.st_mode & S_IRUSR) ? 'r' : 0;
  t_info->perm[2] = (st.st_mode & S_IWUSR) ? 'w' : 0;
  t_info->perm[3] = (st.st_mode & S_IXUSR) ? 'x' : 0;
  t_info->perm[4] = (st.st_mode & S_IRGRP) ? 'r' : 0;
  t_info->perm[5] = (st.st_mode & S_IWGRP) ? 'w' : 0;
  t_info->perm[6] = (st.st_mode & S_IXGRP) ? 'x' : 0;
  t_info->perm[7] = (st.st_mode & S_IROTH) ? 'r' : 0;
  t_info->perm[8] = (st.st_mode & S_IWUSR) ? 'w' : 0;
  t_info->perm[9] = (st.st_mode & S_IXUSR) ? 'x' : 0;
     
}
