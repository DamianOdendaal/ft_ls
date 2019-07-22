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
	int i2;

	i = 0;// we start at 0 because we arent gonna cater for the '-' when we do the ls
	j = 0;
	s2 = "Rlart";
	while(s[++i])
	{
		while(s2[++i2])
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
// when you get home separate your functions accordingly 

/*  int main (int argc, char **argv)
{
	t_ls_flags *flags;
	if (argc < 2)
	{
		if (argc == 1)
		{
			//you need to list what ever is in the current dir, because there are no arguments that have followed my ls
			currdir()
		}
		else
		{
			check_flags(argv[1], flags);
		}
		//parse valuse to your flags once you know they are actually flags  
		return (0);
	}
} 
*/
