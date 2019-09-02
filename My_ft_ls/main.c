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

int main(int ac, char **av)
{
	int i;
	int index;
	t_ls_flags	*flag;

	i = 0;
	index = 0;
	if (ac == 1)
		currdir();
	if (ac > 1)
		check_flags(av, flag);
	// if (ac < 1)
	// {
	// 	create a function to list first check what is being passed, a file or a dir
		
	// 	once you have that then you can create a function that lists what is in a spcecific dir 
	// }
	return (0);
}