/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 14:02:59 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 19:46:58 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


t_iterdata_func choose_print(unsigned char flags)
{
	if (flags & FLAG_l)
		return long_print_format;
	if (flags & FLAG_g)
		return long_print_no_owner;
	else
		return print_name;
}

