/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:19:04 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/22 13:30:48 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

typedef	struct s_ls_flags
	{
		int f_a;
		int f_l;
		int f_r;
		int f_R;
		int f_t;
	} t_ls_flags;

void	init_flags(t_ls_flags *flags)
{
	flags->f_R = 0;
	flags->f_r = 0;
	flags->f_t = 0;
	flags->f_l = 0;
	flags->f_a = 0;

}

void	check_flags(char *s, t_ls_flags *flg)
{
	char *s2;
	int i;
	int i2;

	i = 0;// we start at 0 because we arent gonna cater for the - when we do the ls
	i2 = 0;
	s2 = "Rlart";
	while(s[++i])
	{
		while(s2[i2])
		{
			if (s[i] == s2[i2])
			{

			}
			i2++;
		}
	}
}

int main (int argc, char **argv)
{
	


}
