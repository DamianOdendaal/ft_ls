/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:33:01 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/22 10:29:36 by dodendaa         ###   ########.fr       */
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
        else
		{
            ft_putstr(files->d_name);
            ft_putchar('\t');
       }
    }
    closedir(curdir);
}
