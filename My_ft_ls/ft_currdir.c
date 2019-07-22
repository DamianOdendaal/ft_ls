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

int currdir(char **str, t_ls_flags *flag)// fix parameters of yout current dir function
{

    DIR *curdir;
    struct dirent *files;

    curdir = opendir(".");
    if (!curdir)
    {
        perror(EXIT_FAILURE);
        exit(1);
    }
    while ((files = readdir(curdir)) != NULL)
    {
        if(files->d_name[0] != '.')
		{
            ft_putstr(files->d_name);
            ft_putchar('\t');
        }
    }
    closedir(curdir);
    return (1);
}
