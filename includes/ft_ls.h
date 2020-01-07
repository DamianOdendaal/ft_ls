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
// # include <stdio.h>
// # include <string.h>
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

typedef	struct s_dlink
{
	char			*content;
	struct s_link	*next;
	struct s_link	*prev;
}					t_dlink;

typedef struct	s_info
{
	char		*name;
	char		perm[11];
	short		hard_links;
	char		*owner;
	char		*group;
	long long	bytes;
	char		*time_modified;
	char		*direct_n;
	char		*n_direct_n;
}	t_info;


void 		currdir(t_flags *flags);
void		file_collector(char **argv, t_info *info);
void		file_size_bytes(const char *path, t_info *bytes);
void		file_size_bytes_reg(const char *path);
void 		ft_print_perms(char *perm, struct stat st);
void		ft_print_mode(struct stat st);
void		info_sort(t_flags *flags, t_info *info);
void		info_sort_2(t_flags *flags, t_info *info, int a);
void		r_sort(t_info *direct_name);
void		r_sort_2(t_info *direct_name, int y);
t_bool 		isFile(const char* name);				//have a look at how to mak the t_bool
long long	ft_file_size(char **av);
int			dir_or_not(const char *path, char *temp);
int			is_dir(char *path);
int			directory_counter(char **argv);
int			directory_collector(char **argv, t_dir *direct_o);
int			get_dir_size(char *path, int x);
void		open_dir(const char *path, t_info *info);
void		flag_activate(char c, t_flags *flags);
int			check_flags(char **argv, t_flags *flags);
void		l(const char *path, t_info *info);
void		l_reg(const char *path);
void		l_for_reg(const char *path, t_flags *f, t_info *info, int b);
void		no_args(t_flags *flags);
void		print_long(t_info *info, int z);
void		get_m_time(const char *path, t_info *m_time);
void		get_m_time_reg(const char *path);
void		error_mess(char *tmp);
void		error_mess_01(char c);
void		get_group(const char *path, t_info *group);
void		get_group_reg(const char *path);
void		get_links(const char *path, t_info *link);
void		get_links_reg(const char *path);
void		get_owner(const char *path, t_info *owner);
void		get_owner_reg(const char *path);
ssize_t		get_size(const char *path);
int			do_stuff(t_info *info, const char *path, int y, int t);
int			check_null(t_info *info, int *z);
void		free_info(t_info *info);
int			recursion(const char *path, t_dir *d, t_flags *flags, int y);





#endif
