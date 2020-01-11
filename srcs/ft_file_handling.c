/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:54:31 by dodendaa          #+#    #+#             */
/*   Updated: 2020/01/07 10:48:14 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"

// function that checks if something is a file or a dir

int	is_reg(const char *path)
{
	struct stat buf;

	stat(path, &buf);
	if (S_ISDIR(buf.st_mode))
		return (1);
	else if (S_ISREG(buf.st_mode))
		return (0);
	else
		return (2);
}

void	file_collector(char **argv, t_info *info) // change from collector to like store files or something for dirs too
{
	// int		x;
	int		index;
	int		arguments;
	char	*tmp;

	// x = 0;
	index = 0;
	arguments = 1;
	while (argv[arguments])
	{
		tmp = ft_strdup(argv[arguments]);
		if (is_reg(tmp) == 0)
		{
			info[index].directory_name = ft_strdup(tmp);
			info[index].directory_path = ft_strdup(tmp);
			index++;
		}
		free(tmp);
		arguments++;
	}
}

void	file_size_bytes(const char *path, t_info *bytes)
{
	struct stat buf;

	stat(path, &buf);
	bytes->bytes = buf.st_size;
}

void	file_size_bytes_reg(const char *path)// try and see the diff between this funtion and the one before
{
	int			x;
	struct stat	buf;

	stat(path, &buf);
	x = buf.st_size;
	ft_putnbr(x);
	ft_putchar(' ');
}
