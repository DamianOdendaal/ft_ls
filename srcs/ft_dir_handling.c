/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:42 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/12 11:04:18 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
t_bool isFile(const char* name)
{
    DIR* directory = opendir(name);

    if (directory != NULL)
    {
        closedir(directory);
        return (FALSE);
    }
    return (errno == ENOTDIR);
}

long long	ft_file_size(char **av)
{
	char *filename = av[1];
	struct stat st;
	stat(filename, &st);
	return (st.st_size);		
}
*/
int	dir_or_not(const char *path, char *temp)
{
	int			x;
	struct stat	buf;

	x = 0;
	stat(path, &buf);
	if (S_ISDIR(buf.st_mode))
		temp[x++] = 'd';
	else
		temp[x++] = '-';
	return (x);
}

int	is_dir(char *path)
{
	struct stat	buf;

	lstat(path, &buf);
	if (S_ISDIR(buf.st_mode))
		return (1);
	else if (S_ISREG(buf.st_mode))
		return (2);
	else 
		return (0);
}

int	directory_counter(char **argv)
{
	int		x;
	int		y;
	char	*tmp;

	x = 1;
	y = 0;
	while (argv[x])
	{
		tmp = ft_strdup(argv[x]);
		if (is_dir(tmp) == 1)
		{
			if (tmp[0] != '-')
				y++;
		}
		x++;
		free(tmp);
	}
	return (y);
}

int	directory_collector(char **argv, t_dir *direct_o)
{
	int		x;
	int		y;
	int		z;
	char	*temp;

	x = 1;
	y = 0;
	z = 0;
	while (argv[x])
	{
		if (is_dir(argv[x]) == 1)
		{
			if (argv[x][0] != '-')
			{
				temp = ft_strnew(ft_strlen(argv[x]));
				ft_strcpy(temp, argv[x]);
				direct_o[y].direct_o = ft_strnew(ft_strlen(temp));
				ft_strcpy(direct_o[y].direct_o, temp);
				free(temp);
				y++;
			}
		}
		x++;
	}
	return (y);
}

int	get_dir_size(char *path, int x)
{
	DIR				*dir;
	struct dirent	*dirp;
	char			*temp;

	dir = opendir(path);
	if (dir == NULL)
		return (x);
	else
		while ((dirp = readdir(dir)))
			if (dirp != NULL)
			{
				temp = ft_strnew(255);
				ft_strcpy(temp, path);
				ft_strcat(temp, "/");
				ft_strcat(temp, dirp->d_name);
				if (is_dir(temp) == 1 && dot(dirp->d_name) == 1) // try to replicate what the code is doing and understand what you are doing
				{
					x++;
					x = get_dir_size(temp, x);
				}
				free(temp);
			}
	closedir(dir);void	combine(char *str, const char *path, t_info *info, int x)
{
	char	*dir_str;
	char	*dirp_str;

	dir_str = ft_strnew(255);
	dirp_str = ft_strnew(ft_strlen(str));
	ft_strcpy(dir_str, path);
	ft_strcpy(dirp_str, str);
	ft_strcat(dir_str, "/");
	ft_strcat(dir_str, dirp_str);
	info[x].directory_path = ft_strdup(dir_str);
	info[x].directory_name = ft_strdup(str);
	free(dir_str);
	free(dirp_str);
}

void	open_dir(const char *path, t_info *info)
{
	int				x;
	struct dirent	*dirp;
	DIR				*dir;

	x = 0;
	dir = opendir(path);
	if (dir == NULL)
	{
		ft_putstr("ls: ");
		ft_putstr(path);
		ft_putstr(": ");
		ft_putstr(strerror(13));
		ft_putchar('\n');
		return ;
	}
	else
		while ((dirp = readdir(dir)))
		{
			combine(dirp->d_name, path, info, x);
			x++;
		}
	closedir(dir);
}
	return (x);
}


