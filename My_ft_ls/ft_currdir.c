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


#include "ft_ls.h"

int currdir (int argc, char **argv)
{

    DIR *curdir;
    struct dirent *files;

    curdir = opendir(".");

    while ((files = readdir(mydir)) != NULL)
    {
        if(files->d_name[0] != '.')
		{
            ft_putstr(files->d_name);
            ft_putchar('\t');
        }
    }
    closedir(mydir);
    return (1);
}
