/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:32:28 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/12 10:40:25 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"


void	flag_activate(char c, t_flags *flags)
{
	if (c == 'a')
		*flags |= f_a;
	else if (c == 'l')
		*flags |= f_l;
	else if (c == 'r')
		*flags |= f_r;
	else if (c == 'R')
		*flags |= f_R;
	else if (c == 't')
		*flags |= f_t;
	else if (c == '1')
		*flags |= f_1;
	else if (c == ' ')
		*flags |= f_0;
	else if (c == 'X')
		*flags = (*flags & ~(f_a + f_t)) | (f_R);
	else
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(c);
		ft_putendl("");
	}
}

int	check_flags(char **argv, t_flags *flags)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while(argv[i])
	{
		if (argv[i][0] == '-')
		{
			j = 1;
			if (argv[i][j] == '-')
				return (i + 1);
			else
			{
				while(argv[i][j])
					flag_activate(argv[i][j++], flags);
			}
		}
		i++;
	}
	//ft_print_bits(*flags);
	return (i);
}
