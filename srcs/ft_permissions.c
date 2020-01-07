/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permissions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:07 by dodendaa          #+#    #+#             */
/*   Updated: 2020/01/07 10:57:19 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void 	ft_print_perms(char *perm, struct stat st)
{
  perm[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
  perm[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
  perm[3] = (st.st_mode & S_IXUSR) ? 'x' : '-';
  perm[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
  perm[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
  perm[6] = (st.st_mode & S_IXGRP) ? 'x' : '-';
  perm[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
  perm[8] = (st.st_mode & S_IWUSR) ? 'w' : '-';
  perm[9] = (st.st_mode & S_IXUSR) ? 'x' : '-';
     
}

void	ft_print_mode(struct stat st)
{
	char perm[10];
	ft_memset(perm, '-', 10);
	if ((st.st_mode & S_IFMT) == S_IFDIR)
		perm[0] = 'd';
	else if ((st.st_mode & S_IFMT) == S_IFREG)
		perm[0] = '-';
	else if ((st.st_mode & S_IFMT) == S_IFCHR)
		perm[0] = 'c';
	else if ((st.st_mode & S_IFMT) == S_IFBLK)
		perm[0] = 'b';
	else if ((st.st_mode & S_IFMT) == S_IFSOCK)
		perm[0] = 's';
	else if (st.st_mode & S_IFLNK)
		perm[0] = 'l';
	ft_print_perms(perm, st);
	ft_putstr(perm);
	
}
