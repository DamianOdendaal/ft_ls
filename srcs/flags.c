/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:50:39 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/12 22:14:16 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


// change from inspect to set 
int				inspect_flags(char c)
{

	if (c == 'l')
		return (1);
	else if (c == 'a')
		return (2);
	else if (c == 'R')
		return (4);
	else if (c == 'r')
		return (8);
	else if (c == 't')
		return (16);
	else if (c == 'g')
		return (32);
	else if (c == '1')
		return (64);
	return (0);
}

unsigned char	get_flags(unsigned char flags)
{
	//what is diffile_error
	// change method name according to what dirfile error does
	dirfile_error("-");
	return (flags);
}

void			illegal_options(char ch)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(ch);
	ft_3t_printer("\n", "usage: ft_ls [-Ralrt] [file ...]", "\n");
	exit(1);
}

int				inspect(char ch)
{
	if (inspect_flags(ch) != 0)
		return (1);
	else
		return (0);
}




unsigned char	obtain_flags(int ac, char *av[])
{
	int				i;
	int				j;
	unsigned char	flags;

	i = 1;
	flags = '\0';
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '-')
		{
			j++;
			if (av[i][1] == '\0')
				return (get_flags(flags));
			while (inspect(av[i][j]) == 1)
				flags |= inspect_flags(av[i][j++]);
			if (inspect_flags(av[i][j]) == 0 && av[i][j] != '\0')
				illegal_options(av[i][j]);
		}
		else
			return (flags);
		i++;
	}
	return (flags);
}
