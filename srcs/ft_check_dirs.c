/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:42 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/12 11:04:18 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_bool isFile(const char* name)
{
    DIR* directory = opendir(name);

    if (directory != NULL)
    {
        closedir(directory);
        return (FALSE);
    }
    return (errno == ENOTDIR);
}

long long	ft_file_size(char **av)
{
	char *filename = av[1];
	struct stat st;
	stat(filename, &st);
	return (st.st_size);		
}