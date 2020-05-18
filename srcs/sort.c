// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   sort.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/05/18 21:39:26 by dodendaa          #+#    #+#             */
// /*   Updated: 2020/05/18 21:47:01 by dodendaa         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/ft_ls.h"

// static t_list	*sort_ascii(t_list *list)
// {
//     t_dir *content;
//     t_dir *next;

//     content = (t_dir *)list->content;
//     next = (t_dir *)list->next;

// 	if (!content)
// 		return (NULL);
// 	if (next && ft_charcasecmp(content->name[0], next->name[0]) > 0)
// 		content = lst_swap(list, next);
// 	next = sort_ascii(list->next);
// 	if (next && ft_charcasecmp(content->name[0], next->name[0]) > 0)
// 	{
// 		content = lst_swap(list, next);
// 		next = sort_ascii(next);
// 	}
// 	return (content);
// }

// /*
// **		A method used to help sort ascii, the method returns a static variable.
// **		We need the value that is returned between invocations of the method
// **		to be kept so that the list can be sorted successfully
// */

// t_list		*sort(t_list *unsorted)
// {
// 	t_dir	*sorted;

//     sorted = (t_dir *)unsorted->content;

// 	sorted = sort_ascii(unsorted);
// 	return (sorted);
// }