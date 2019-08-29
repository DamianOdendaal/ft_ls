/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:30:51 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/22 10:26:18 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LS_H
# define FT_LS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct	s_dir
{
	char	*dirname;
	struct s_dir	*next;
}	t_dir;

typedef	struct s_ls_flags
{
	int f_a;
	int f_l;
	int f_r;
	int f_R;
	int f_time;
}		t_ls_flags;


void	currdir();
void	print_hidden();
void	flag_activate(char c, t_ls_flags **fs);
void	init_flags(t_ls_flags *flags);
void	check_flags(char **s, t_ls_flags *flg);


#endif
