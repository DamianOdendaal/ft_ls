/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:55:00 by dodendaa          #+#    #+#             */
/*   Updated: 2019/11/07 12:55:26 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_ls.h"

void	info_sort(t_flags *flags, t_info *info)
{
	if (flags->t_flag == 1)
	{
		r_sorting(info);
		t_sorting(info);
	}
	else
		sorting(info);
	if (flags->r_flag == 1)
		r_sort(info);
}

void	info_sort_2(t_flags *flags, t_info *info, int a)
{
	if (flags->t_flag == 1)
	{
		r_sorting_2(info, a);
		t_sorting_2(info, a);
	}
	else
		sorting_2(info, a);
	if (flags->r_flag == 1)
		r_sort_2(info, a);
}

void	r_sort(t_info *direct_name)
{
	int		y;
	int		x;
	t_info	temp;

	y = 0;
	x = 0;
	while (direct_name[y].n_direct_n)
		y++;
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
