/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:55:00 by dodendaa          #+#    #+#             */
/*   Updated: 2020/01/08 16:47:23 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_ls.h"


void	swap(t_info *d_name, int z)
{
	char *temp;
	char *temp2;

    // storing the path and the name of a dir in vars 

	temp = ft_strnew(ft_strlen(d_name[z].directory_path));   // directory path 
	temp2 = ft_strnew(ft_strlen(d_name[z].directory_name));     // dir name here 
	ft_strcpy(temp, d_name[z].directory_path);              // copy the path of the file into the first temp value  
	free(d_name[z].directory_path);
	ft_strcpy(temp2, d_name[z].directory_name);
	free(d_name[z].directory_name);

    

	d_name[z].directory_path = ft_strnew(ft_strlen(d_name[z + 1].directory_path));
	d_name[z].directory_name = ft_strnew(ft_strlen(d_name[z + 1].directory_name));
	ft_strcpy(d_name[z].directory_path, d_name[z + 1].directory_path);
	free(d_name[z + 1].directory_path);
	ft_strcpy(d_name[z].directory_name, d_name[z + 1].directory_name);
	free(d_name[z + 1].directory_name);
	d_name[z + 1].directory_path = ft_strnew(ft_strlen(temp));
	d_name[z + 1].directory_name = ft_strnew(ft_strlen(temp2));
	ft_strcpy(d_name[z + 1].directory_path, temp);
	ft_strcpy(d_name[z + 1].directory_name, temp2);
	free(temp);
	free(temp2);
}

void	reverse_sorting(t_info *directory_nameame)
{
	int index;
	int arg;
	int res;

	res = 0;
	index = 0;
	while (directory_nameame[index].directory_name && directory_nameame[index].directory_name != NULL)
		index++;
	index--;
	while (index)
	{
		arg = 0;
		while (arg < index)
		{
			res = ft_strcmp(directory_nameame[arg].directory_name, directory_nameame[arg + 1].directory_name);
			if (res < 0)
				swap(directory_nameame, arg);
			arg++;
		}
		index--;
	}
}

void	info_sort(t_flags *flags, t_info *info)
{
	if (*flags & f_r)
	{
		reverse_sorting(info);
		t_sorting(info);
	}
	else
		sorting(info);
	if (flags->r_flag == 1)
		r_sort(info);
}

void	info_sort_2(t_flags *flags, t_info *info, int a)
{
	if (*flags & f_t)
	{
		reverse_sorting_2(info, a);
		t_sorting_2(info, a);
	}
	else
		sorting_2(info, a);
	if (flags & f_r)
		r_sort_2(info, a);
}

void	r_sort(t_info *directory_nameame)
{
	int		index;
	int		sec_index;
	t_info	temp;

	index = 0;
	sec_index = 0;
	while (directory_nameame[index].directory_path)
		index++;
	index--;
	while (directory_nameame[sec_index].directory_path && sec_index < index)
	{
		temp = directory_nameame[sec_index];
		directory_nameame[sec_index] = directory_nameame[index];
		directory_nameame[index] = temp;
		sec_index++;
		index--;
	}
}

void	r_sort_2(t_info *directory_nameame, int y)
{
	int		x;
	t_info	temp;

	x = 0;
	y--;
	while (directory_nameame[x].directory_path && x < y)
	{
		temp = directory_nameame[x];
		directory_nameame[x] = directory_nameame[y];
		directory_nameame[y] = temp;
		x++;
		y--;
	}
}
