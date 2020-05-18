/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:52:44 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/18 12:52:47 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**		Method used to convert something that is 
**		of type struct passwd into a string
*/

char		*username_to_string(int uid)
{
	struct passwd	*pwd;

	pwd = getpwuid(uid);
	if (pwd == NULL)
		perror("An error has occured using getpwuid");
	else
		return (ft_strdup(pwd->pw_name));
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
		perror("An error has occured using getgid");
	else
		return (ft_strdup(grp->gr_name));
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
