/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:32:28 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/17 13:32:29 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"


void	init_flags(t_ls_flags *flags)
{
	flags->f_R = 0;
	flags->f_r = 0;
	flags->f_time = 0;
	flags->f_l = 0;
	flags->f_a = 0;

}

void	flag_activate(char c, t_ls_flags **fs)
{
	if (c == 'a')
	{
		(*fs)->f_a = 1;
		ft_putstr("flag active");
	}
		
	if (c == 'l')
		(*fs)->f_l = 1;
	if (c == 'r')
		(*fs)->f_r = 1;
	if (c == 'R')
		(*fs)->f_R = 1;
	if (c == 't')
		(*fs)->f_time = 1;
}

void	check_flags(char **s, t_ls_flags *flg)
{
	char *s2;
	int i;
	int index;
	int j;

	i = 1;
	j = 0;
	index = 1;
	s2 = "artRl";
	while(s[i][index])
	{
		if (s[i][0] == '-')
		{
			while(s2[j] != '\0')
			{
				if (s[i][index++] == s2[j])
				{
					flag_activate(s[i][index],&flg);
					break;
				}
				j++;
			}
		}
		index++;
		i++;
	}
}