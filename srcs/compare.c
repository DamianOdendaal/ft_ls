/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:13:10 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 19:33:15 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"




int		filetime_compare(void *a, void *b)
{
	t_dir *first;
	t_dir *second;
    int time;
    int ntime;

	first = (t_dir *)a;
	second = (t_dir *)b;

    time = second->time - first->time;
    ntime = second->ntime - first->time;

    if (time != 0)
        return (time);
    return (ntime);

}


int		reverse_filetime_compare(void *a, void *b)
{
	return (-filetime_compare(a, b));
}


int		filename_compare(void *a, void *b)
{
	t_dir *first;
	t_dir *second;

	first = (t_dir *)a;
	second = (t_dir *)b;
	return (ft_strcmp(first->name, second->name));
	
}


int 	reverse_filenameCmp(void *a, void *b)
{
	return (-filename_compare(a, b));
}

t_compfunc 	choose_compare(unsigned char flags)
{
	if (flags & FLAG_r)
	{
		if (flags & FLAG_t)
			return (&reverse_filetime_compare);
		return (&reverse_filenameCmp);
	}
	if (flags & FLAG_t)
		return (&filetime_compare);
	return (&filename_compare);
}

