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


typedef	enum e_flags
{
	f_0 = 0,
	f_a = 1,
	f_l = 2,
	f_r = 4,
	f_R = 8,
	f_t = 16,
	f_1 = 32, 
}		t_flags;


void	currdir(t_flags *flags);
void	print_hidden();
void	flag_activate(char c, t_flags *flags);
void	init_flags(t_flags *flags);
int		check_flags(char **s, t_flags *flags);
void	long_print(int argc, char **argv);
void	dash1(t_flags *flags);
void	ft_print_bits(int c);
int 	isFile(const char* name);


#endif
