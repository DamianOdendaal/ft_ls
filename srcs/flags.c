/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:50:39 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/15 18:42:06 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


/*
**		Init flags is here to initialise a value to 
**		each individual flag and to allow us to make 
**		use of bit manipulation later in our code
*/  

int				init_flags(char c)
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


/*
**		Not found is a helper method for when we find 
**		a case where we dont give any options to our ls 
**		so we print the needed error and return the flags
*/

unsigned char	not_found(unsigned char flags)
{
	no_where_to_be_found("-");
	return (flags);
}


/*
**		This is for the cases when people try to 
**		enter values that our project does not 
**		cater for 
*/

void			illegal_options(char ch)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(ch);
	ft_3t_printer("\n", "usage: ft_ls [-Ralrt] [file ...]", "\n");
	exit(1);
}

/*
**		Method used to make sure that our flags
**		are set	
*/

int				inspect(char ch)
{
	return (init_flags(ch) != 0);
}


/*
**		Inspect flags is here so that we can know what was given in 
** 		as arguments and then according to the flag that was passed in
**		we will know what needs to be done
*/

unsigned char	inspect_flags(int ac, char *av[])
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
				return (not_found(flags));
			while (inspect(av[i][j]) == 1)
				flags |= init_flags(av[i][j++]);
			if (init_flags(av[i][j]) == 0 && av[i][j] != '\0')
				illegal_options(av[i][j]);
		}
		else
			return (flags);
		i++;
	}
	return (flags);
}
