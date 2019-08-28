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
	flags->f_t = 0;
	flags->f_l = 0;
	flags->f_a = 0;

}

void	flag_activate(char c, t_ls_flags **fs)
{
	if (c == 'a')
		(*flags)->f_a = 1;
	if (c == 'l')
		(*flags)->f_l = 1;
	if (c == 'r')
		(*flags)->f_r = 1;
	if (c == 'R')
		(*flags)->f_R = 1;
	if (c == 't')
		(*flags)->f_t = 1;
}

void	check_flags(char *s, t_ls_flags *flg)
{
	char *s2;
	int i;
	int j;

	i = 0;
	j = 0;
	s2 = "Rlart";
	while(s[++i])
	{
		while(s2[++j])
		{
			if (s[i] == s2[j])
			{
				flag_activate(s[i],&flg);
				break;
			}
			if (ft_strlen(s2) == j)
			{
			    ft_putstr_fd("ls: invalid option -- ", 2);
			    ft_putchar_fd(s[i], 2);
			    ft_putstr_fd("\n", 2);
			    return (0);
			}
			j = -1;
		}
	}
}