/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:30:51 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/17 13:30:53 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LS_H
# define FT_LS_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
#include "../libft/libft.h"

typedef	struct		s_file
{
	char			*attributes;
	char			*file_name;
	unsigned int	links;
	long			blocks;
	char			*userid;
	char			*groupid;
	int				size;
	time_t			rawtime;
	char			*day;
	char			*month;
	char			*year;
	char			*time;
	struct s_file	*next;
	struct s_file	*previous;
}					t_file;
typedef struct	s_dir
{
	char	*dirname;
	struct s_dir	*next;
}	t_dir;

#endif
