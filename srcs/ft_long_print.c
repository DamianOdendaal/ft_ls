/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:35:45 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/12 15:07:25 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


void	ft_print_long(t_ls_info *info, char **av, struct stat *st)
{
	uid_t		uid;
	gid_t		gid;
	t_llong		bytes;
	time_t		curtime;
	
	curtime = 0;
	info = NULL;
	uid = 0;
	gid = 0;
	ft_print_mode(info, *st);
	ft_print_perm(info, *st);
	ft_space(); 
	ft_putnbr(st->st_nlink);
	ft_space();
	ft_putstr(getuuid(uid));
	ft_space();
	ft_putstr(getgroup(gid));
	ft_space();
	bytes = ft_file_size(av);
	ft_putnbr(bytes);
	ft_space();
	ft_mod_time(curtime);
	ft_space();
	// 7.) file/dir name
	// ft_putstr();
	// ft_putchar('\n');
}

