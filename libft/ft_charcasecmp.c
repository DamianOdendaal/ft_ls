/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:58:35 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/10 17:01:39 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charcasecmp(const char char1, const char char2)
{
	if ((unsigned char)char1 - (unsigned char)char2 > 0)
		return (1);
	else if ((unsigned char)char1 - (unsigned char)char2 < 0)
		return (-1);
	else
		return (0);
}   