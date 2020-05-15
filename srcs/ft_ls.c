/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:52:57 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/15 19:41:53 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**	This is the method where we take in the contents 
**	from the directory we would like to list 
**	store it in a list and do what needs to be done 
**	based on the flags that are given
*/

void	ft_ls(char *d_path, unsigned char flags)
{
	DIR				*dire;
	struct dirent	*entries;
	t_dir			*content;

	content = NULL;
	entries = NULL;
	dire = opendir(d_path);
	if (error_handle(d_path, dire, errno) == 1)
		return ;
	while ((entries = readdir(dire)))
	{
		if (!content)
			content = list_init(entries, d_path);
		else
			list_add(&content, entries, d_path);
	}
	closedir(dire);
	print_output(content, flags, d_path);
	delete_list(&content);
}


/*
**		confirm args is a method used to confirm what was
**		given in,  there are 3 return values. If the method 
**		returns 0 we didn't encounter any issues. If the method 
**		returns 1 then we are not using a valid option. If the method
**		returns 2 then we have passed no flags after the - 
*/

int		confirm_args(int ac, char *av[], unsigned char flags)
{
	int i;
	int check;

	i = 1;
	check = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			ft_ls(av[i], flags);
			check = 1;
		}
		if (av[i][0] == '-' && av[i][1] == '\0')
			check = 2;
		i++;
	}
	return (check);
}





int		main(int ac, char *av[])
{
	unsigned char	flags;
	int				check;

	check = 0;
	flags = inspect_flags(ac, av);
	if (ac == 1)
		ft_ls(".", flags);
	else
	{
		check = confirm_args(ac, av, flags);
		if (check == 0)
			ft_ls(".", flags);
	}
	return (0);
}