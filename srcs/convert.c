/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:52:44 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/16 16:54:40 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**		Method used to convert something that is 
**		of type struct passwd into a string
*/

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

/*
**		Method used to convert something that is 
**		of type struct group into a string
*/

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

/*
**	Method that is used to convert the 
**	full date and time o
*/

void		convert_date(char *str)
{
	char	ret[14];
	int		i;
	int		j;

	j = 0;
	i = 4;
	ft_strcpy(ret, "000  0 00:00 ");
	while (i < 16)
		ret[j++] = str[i++];
	ft_putstr(ret);
}
