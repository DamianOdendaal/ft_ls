// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   extra.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/05/17 14:16:27 by dodendaa          #+#    #+#             */
// /*   Updated: 2020/05/17 14:18:49 by dodendaa         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/ft_ls.h"


// /*
// **		This is a method for the -1 flag where we put every file 
// **		on its own line 
// */

// void file_per_line(t_dir *head, unsigned char flags) 
// {
//     t_dir *current = head;

//     while (current != NULL) 
// 	{
	
// 		if ((flags & 2))
// 		{
// 			ft_putstr(current->name);
// 			ft_putchar('\n');
// 			current = current->next;
// 		}
// 		else
// 		{
// 			if (current->name[0] != '.')
// 			{
// 				ft_putstr(current->name);
// 				if (current->next != NULL)
// 					ft_putchar('\n');
// 			}
// 		}
// 		current = current->next;
//     }
// 	ft_putchar('\n');
// }