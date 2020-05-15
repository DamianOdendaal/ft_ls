/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:52:37 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/15 18:29:21 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**		The permission error is for when we try
**		to list the contents of something we do not
**		have enough right to 
*/

void	permission_error(char *path)
{
	ft_3t_printer("ft_ls:", " ", NULL);
	if (path[ft_strlen(path) - 1] != '/')
		ft_3t_printer("cannot open directory ", path, ": Permission denied\n");
}

/*
**	When we try to list things we think are there
**  but they really arent 
*/

void	no_where_to_be_found(char *path)
{
	ft_3t_printer("ft_ls: cannot access ", path, ": No such file or directory\n");
}



/*
**		Error handle is a method that we use to call the 
**		error handling methods that check if the content 
**		that is being listed is valid content and if you have 
**		the valid permissions
*/

int		error_handle(char *path, DIR *dp, int ierrno)
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
		no_where_to_be_found(path);
		return (1);
	}
	return (0);
}
