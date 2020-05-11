/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:52:44 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/07 20:54:49 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

//convert username
char		*username_to_string(int uid)
{
	// write out variables names
	struct passwd	*pwd;

	pwd = getpwuid(uid);
	if (pwd == NULL)
		perror("getpwuid");
	else
		return (pwd->pw_name);
	return (NULL);
}

// convert group name
char		*groupName_to_string(int gib)
{
	struct group *grp;

	grp = getgrgid(gib);
	if (grp == NULL)
		perror("getgid");
	else
		return (grp->gr_name);
	return (NULL);
}


//ask Anda bout this
// where do i use this --> output.c 
// add header
void		convert_date(char *str)
{
	char	ret[14];
	int		i;
	int		j;

	j = 0;
	i = 4;
	ft_strcpy(ret, "000  0 00:00 ");
	while (i < 16)
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	ft_putstr(ret);
}
