/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:54:31 by dodendaa          #+#    #+#             */
/*   Updated: 2019/11/07 12:55:26 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/ft_ls.h"

void	file_collector(char **argv, t_info *info) // change from collector to like store files or something for dirs too
{
	int		x;
	int		y;
	int		z;
	char	*tmp;

	x = 0;
	y = 0;
	z = 1;
	while (argv[z])
	{
		tmp = ft_strdup(argv[z]);
		if (is_reg(tmp) == 0)
		{
			info[y].direct_n = ft_strdup(tmp);
			info[y].n_direct_n = ft_strdup(tmp);
			y++;
		}
		free(tmp);
		z++;
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
