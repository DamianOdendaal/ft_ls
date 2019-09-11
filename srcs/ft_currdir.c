/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_currdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:56 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/10 11:36:56 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../includes/ft_ls.h"

void currdir(t_flags *flags)
{

    DIR *curdir;
    struct dirent *files;

    curdir = opendir(".");
    if (!curdir)
    {
        ft_putstr("No such directory");
        exit(1);
    }
    while ((files = readdir(curdir)) != NULL)
    {
        if (!(*flags & f_a) && files->d_name[0] == '.')
            continue;
        else if (*flags & f_1)
            ft_putendl(files->d_name);
        else if (*flags & f_a)
		{
            ft_putstr(files->d_name);
            ft_putchar('\t');
       }
	   else
			return ;
    }
    closedir(curdir);
}
