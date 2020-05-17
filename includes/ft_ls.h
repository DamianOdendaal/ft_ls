/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
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
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include "../libft/libft.h"

# define dodoTime st_mtim.tv_nsec 

typedef struct		s_dir
{
	char			*name;
	char			*uid;
	char			*gid;
	int				type;
	int				block;
	mode_t			mode;
	nlink_t			nlink;
	off_t			size;
	long			ntime;
	time_t			time;
	struct s_dir	*next;
	struct s_dir	*prev;
}					t_dir;



void			long_print_no_owner(t_dir *lst, char *path);
void			long_print_format(t_dir *lst, char *path);
void			ls_permissions(t_dir *lst);
void 			content_details(t_dir *lst, char *path);
void			sort_list(t_dir **begin, short flags);
void    		ft_thelstadd(t_dir **alst, t_dir *new);
t_dir			*sort_time(t_dir *lst);
t_dir			*lst_swap(t_dir *value1, t_dir *value2);
char			*get_last_name(t_dir *list);
t_dir			*quick_sort_time(t_dir **begin, short flags);
void			recursion(t_dir *list, unsigned char flags, char *path);
void			supress_owner_print_list(t_dir *list, unsigned char flags, char *path);
void			print_list(t_dir *list, unsigned char flags, char *path);
t_dir			*create_ls_node(struct dirent *de, char *path);
void			lst_del(t_dir **list);
void			list_add(t_dir **alst, struct dirent *de, char *path);
char			*username_to_string(int uid);
char			*groupName_to_string(int gib);
void			convert_date(char *str);
void			permission_error(char *path);
void			no_where_to_be_found(char *path);
int				error_handle(char *path, DIR *dp, int ierrno);
void 			file_per_line(t_dir *head, unsigned char flags);
int				init_flags(char c);
unsigned char	not_found(unsigned char flags);
void			illegal_options(char ch);
int				inspect(char ch);
unsigned char	inspect_flags(int ac, char *av[]);
void			ft_ls(char *d_path, unsigned char flags);
int				confirm_args(int ac, char *av[], unsigned char flags);
void			ft_linkprint(char *path, t_dir *ptr);
void			show_block(t_dir *ptr, unsigned char flags);
void 			quick_print_list(t_dir *head, unsigned char flags);
void 			quick_print_l(t_dir *head, unsigned char flags);
void			normal_print(t_dir *list, unsigned char flags);
void			time_print_list(t_dir *list, unsigned char flags, char *path);
void			all_printer(t_dir *list, unsigned char flags);
void			print_output(t_dir *list, unsigned char flags, char *path);
t_dir			*sort(t_dir *unsorted);
void			reverse_list(struct s_dir **head_ref, unsigned char flags);


#endif