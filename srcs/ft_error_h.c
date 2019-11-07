/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:54:39 by dodendaa          #+#    #+#             */
/*   Updated: 2019/11/07 12:55:26 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void	error_mess(char *tmp)
{
	ft_putstr("ls: ");
	ft_putstr(tmp);
	ft_putstr(": ");
	ft_putstr(strerror(2));
	ft_putchar('\n');
}

void	error_mess_01(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ls [-Ralrt] [file ...]");
}

