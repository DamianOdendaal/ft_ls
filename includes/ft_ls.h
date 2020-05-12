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
# include <sys/types.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include "../libft/libft.h"

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
	time_t			mtime;
	struct s_dir	*next;
}					t_dir;

// typedef	enum e_flags
// {
// 	f_0 = 0,
// 	f_a = 1,
// 	f_l = 2,
// 	f_r = 4,
// 	f_R = 8,
// 	f_t = 16,
// 	f_1 = 32, 
// }			t_flags;



int					error_handle(char *path, DIR *d_path, int ierrno);
void				convert_date(char *str);
void				delete_list(t_dir **list);
void				list_add(t_dir **alst, struct dirent *de, char *path);
void				root_out(struct dirent *de, unsigned char flags,
						DIR *dr);
void				recursive_print(struct dirent *de, unsigned char flags,
						char *path);
unsigned char		obtain_flags(int ac, char *av[]);
void				ft_ls(char *d_path, unsigned char flags);
void				recursion(t_dir *list, unsigned char flags, char *path);
char				*username_to_string(int uid);
char				*groupName_to_string(int gib);
void				print_list(t_dir *list, unsigned char flags, char *path);
void				standard_out(t_dir *list, unsigned char flags);
void				print_output(t_dir *list, unsigned char flags, char *path);
void				inverse_split(t_dir *source, t_dir **front_ref,
						t_dir **back_ref);
void				merge_sort(t_dir **head_ref, unsigned char flags);

void				dirfile_error(char *path);
void				ft_linkprint(char *path, t_dir *ptr);
void				display_blocks(t_dir *ptr, unsigned char flags);
void				reverse_list(struct s_dir	**head_ref,  unsigned char flags);
t_dir				*sort_merge_list(t_dir *a, t_dir *b, unsigned char flags);
t_dir				*list_init(struct dirent *de, char *path);
void				long_print_no_owner(t_dir *lst, char *path, unsigned char flags);
t_dir				*sort(t_dir *unsorted);
t_dir				*ft_alpha_sort(t_dir *list, unsigned char flags);
int 				get_list_length(t_dir *list);




#endif
