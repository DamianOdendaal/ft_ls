/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:52:37 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/12 21:52:47 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// check what this putstrx# is 
void	error_handle2(char *path)
{
	if (ft_strcmp(path, ".") != 0)
		ft_3t_printer("\n", path, ":\n");
}

void	permission_error(char *path)
{
	ft_3t_printer("ft_ls: ", "\033[0;31m", NULL);
	if (path[ft_strlen(path) - 1] != '/')
		ft_3t_printer("cannot open directory ", path, ": Permission denied\n");
}

void	dirfile_error(char *path)
{
	ft_putstr("\033[0;33m");
	ft_3t_printer("ft_ls: cannot access ", path, ": No such file or directory\n");
}

int		error_handle(char *path, DIR *dp, int ierrno, unsigned int flag)
{
	if (ierrno == 20)
	{
		ft_putstr(path);
		return (1);
	}
	else if (!dp)
	{
		if (ierrno == 13)
		{
			permission_error(path);
			return (1);
		}
		dirfile_error(path);
		return (1);
	}
	if (flag & 4)
	{
		error_handle2(path);
	}
	return (0);
}
