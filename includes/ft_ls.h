/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:30:51 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/09 16:46:50 by dodendaa         ###   ########.fr       */
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

typedef struct	s_ls_info
{
	char		*name;
	char		perm[10];
	short		hard_links;
	char		*owner;
	char		*group;
	long long	bytes;
	char	*time_modified;
}	t_ls_info;


void	ft_mod_time(time_t curtime);
long long	ft_file_size(char **av);
char  	*getuuid(uid_t uid);
char	*getgroup(gid_t gid);
void	currdir(t_flags *flags);
void	flag_activate(char c, t_flags *flags);
int		check_flags(char **argv, t_flags *flags);
void	ft_print_bits(int c);						//not gonna need this in a while
t_bool 	isFile(const char* name);
void	ft_print_long(char *name, char *dir);
t_list	*insertion_sorter(t_list* head_n);
void 	ft_print_perm(t_ls_info *t_info, struct stat st);
void	ft_print_mode(t_ls_info *t_info, struct stat st);


#endif
