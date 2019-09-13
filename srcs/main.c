/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:54:04 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/12 13:59:25 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"

void	ft_print_bits(int c)
{
	int out;
	int i;

	out = 0;
	i = 32;
	while (i--)
	{
		out = (c >> i & 1) + '0';
		ft_putchar(out);
		if (i % 8 == 0 && i != 0)
			ft_putchar(' ');
	}
}



int main(int ac, char **av)
{
	int i;
	t_flags	flags;

	i = 0;
	if (ac == 1)
		currdir(&flags);
	if (ac > 1)
		i = check_flags(av, &flags);
	if (!av[i])
		currdir(&flags);
	if (flags & f_l)
		ft_print_long(av[1],av[2] );
	if (flags & f_t)
	{
		ft_putstr("flag t is set");
		ft_putendl("");
	}



	// parsing:
	// 	- flags -> set flags
	// 	- error/file/dir -> print errors, the files, the dirs

	// data:
	// 	- create data structure based on dirs
	
	// sort:
	// 	- lex if no sort flags 
	// 	- time if -t
	
	// print:
	// 	- 1 of no -l flag
	// 	- l if -l
	// 	- a if -a
	
	// clean:
	// 	- freee yo shit - EVERY FUCKING ITME
	// RECURSIVE: OPEN DIRS IN CURRENT DIR
	// struct stat	s_stat;
	// lstat(path, &s_stat);
	return (0);
}
