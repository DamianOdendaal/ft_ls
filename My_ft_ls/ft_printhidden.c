/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhidden.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:05:35 by dodendaa          #+#    #+#             */
/*   Updated: 2019/08/29 13:05:37 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void print_hidden()
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
        ft_putstr(files->d_name);
        ft_putchar('\t');
    }
    closedir(curdir);
}