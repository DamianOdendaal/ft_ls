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

	temp = ft_strnew(ft_strlen(d_name[z].n_direct_n));   // directory path 
	temp2 = ft_strnew(ft_strlen(d_name[z].direct_n));     // dir name here 
	ft_strcpy(temp, d_name[z].n_direct_n);              // copy the path of the file into the first temp value  
	free(d_name[z].n_direct_n);
	ft_strcpy(temp2, d_name[z].direct_n);
	free(d_name[z].direct_n);

    

	d_name[z].n_direct_n = ft_strnew(ft_strlen(d_name[z + 1].n_direct_n));
	d_name[z].direct_n = ft_strnew(ft_strlen(d_name[z + 1].direct_n));
	ft_strcpy(d_name[z].n_direct_n, d_name[z + 1].n_direct_n);
	free(d_name[z + 1].n_direct_n);
	ft_strcpy(d_name[z].direct_n, d_name[z + 1].direct_n);
	free(d_name[z + 1].direct_n);
	d_name[z + 1].n_direct_n = ft_strnew(ft_strlen(temp));
	d_name[z + 1].direct_n = ft_strnew(ft_strlen(temp2));
	ft_strcpy(d_name[z + 1].n_direct_n, temp);
	ft_strcpy(d_name[z + 1].direct_n, temp2);
	free(temp);
	free(temp2);
}

void	reverse_sorting(t_info *direct_name)
{
	int index;
	int arg;
	int res;

	res = 0;
	index = 0;
	while (direct_name[index].direct_n && direct_name[index].direct_n != NULL)
		index++;
	index--;
	while (index)
	{
		arg = 0;
		while (arg < index)
		{
			res = ft_strcmp(direct_name[arg].direct_n, direct_name[arg + 1].direct_n);
			if (res < 0)
				swap(direct_name, arg);
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

void	r_sort(t_info *direct_name)
{
	int		index;
	int		sec_index;
	t_info	temp;

	index = 0;
	sec_index = 0;
	while (direct_name[index].n_direct_n)
		index++;
	index--;
	while (direct_name[sec_index].n_direct_n && sec_index < index)
	{
		temp = direct_name[sec_index];
		direct_name[sec_index] = direct_name[index];
		direct_name[index] = temp;
		sec_index++;
		index--;
	}
}

void	r_sort_2(t_info *direct_name, int y)
{
	int		x;
	t_info	temp;

	x = 0;
	y--;
	while (direct_name[x].n_direct_n && x < y)
	{
		temp = direct_name[x];
		direct_name[x] = direct_name[y];
		direct_name[y] = temp;
		x++;
		y--;
	}
}
