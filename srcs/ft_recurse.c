/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:54:56 by dodendaa          #+#    #+#             */
/*   Updated: 2019/11/07 12:55:26 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_ls.h"

int		do_stuff(t_info *info, const char *path, int y, int t)
{
	if (t == 0)
		while (t < y)
			t++;
	open_dir(path, info);
	return (t);
}

int		check_null(t_info *info, int *z)
{
	*z = -1;
	if (info[0].directory_name == NULL)
	{
		free(info);
		return (1);
	}
	else
		return (0);
}

void	free_info(t_info *info)
{
	int z;

	z = 0;
	while (info[z].directory_path && info[z].directory_path != NULL)
	{
		free(info[z].directory_path);
		free(info[z].directory_name);
		z++;
	}
	free(info);
}

int		recursion(const char *path, t_dir *d, t_flags *flags, int y)
{
	static int	t = 0;
	int			z;
	char		*temp;
	t_info		*info;

	info = (t_info *)malloc(sizeof(t_info) * 4294967295);
	t = do_stuff(info, path, y, t);
	if (check_null(info, &z) == 1)
		return (t);
	else
	{
		info_sort(flags, info);
		while (info[++z].directory_path && info[z].directory_path != NULL)
			if (is_dir(info[z].directory_path) == 1 && dot(info[z].directory_name) == 1)
			{
				d[t].direct_o = ft_strnew(ft_strlen(info[z].directory_path));
				temp = ft_strdup(info[z].directory_path);
				ft_strcpy(d[t].direct_o, temp);
				t++;
				recursion(temp, d, flags, y);
				free(temp);
			}
	}
	free_info(info);
	return (t);
}
