/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:35:45 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/11 16:40:43 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..includes/ft_ls.h"


void	ft_print_long(t_list *flags)  // check if you can take in the dir name as a parameter
{
	t_ls_info *info;
	struct stat st;
	uid_t uid;
	gid_t gid;
	
	// permissions
	ft_print_mode(info, st);
	ft_print_perm(info, st);

	// 2.) print number links
	ft_space(); 
	ft_putnbr(st->st_nlink);
	ft_space();

	// 3.) owner
	ft_putstr(getuuid(uid));
	ft_space();

	// 4.) group
	ft_putstr(getggrgid(gid));
	ft_space();

	// 5.) file size (in bytes)



	// 6.) time of last modification

	// 7.) file/dir name
}

