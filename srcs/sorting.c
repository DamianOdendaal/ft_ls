/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:53:33 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/14 09:17:56 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


// static void		match_times(t_dir *names, time_t filetimes[])
// {
// 	int				i;
// 	struct stat		filestat;

// 	i = 0;
//     while (names->next != NULL)
// 	{
// 		lstat(names->name,  &filestat);
// 		filetimes[i++] = filestat.st_mtimespec.tv_sec;
// 		names = names->next;
// 	}
// }

// static void		swap_tsec(t_dir *none, t_dir *ntwo, time_t *tone, time_t *ttwo)
// {
// 	char			*temp;
// 	time_t			temptime;

// 	temp = none->name;
// 	none->name = ntwo->name;
// 	ntwo->name = temp;
// 	temptime = *tone;
// 	*tone = *ttwo;
// 	*ttwo = temptime;
// }

// static void		swap_tnsec(t_dir *name1, t_dir *name2)
// {
// 	char		*temp;
// 	struct stat	name1stat;
// 	struct stat	name2stat;

// 	lstat(name1->name, &name1stat);
// 	lstat(name2->name, &name2stat);
// 	if (name1stat.st_mtimespec.tv_nsec < name2stat.st_mtimespec.tv_nsec)
// 	{
// 		temp = name1->name;
// 		name1->name = name2->name;
// 		name2->name = temp;
// 	}
// }



// void			sort_time(t_dir *names, int len)
// {
// 	time_t			ftm[len];
// 	int				i;
// 	int				j;

// 	match_times(names, ftm);
// 	i = 0;
// 	j = 0;
// 	while (j++ < len)
// 	{
// 		while (i < len - 1)
// 		{
// 			if (ftm[i] < ftm[i + 1])
// 				swap_tsec(&names[i], &names[i + 1], &ftm[i], &ftm[i + 1]);
// 			else if (ftm[i] == ftm[i + 1])
// 				swap_tnsec(&names[i], &names[i + 1]);
// 			i++;
// 		}
// 		i = 0;
// 	}
// }


// void	swap(t_dir *d_name, int index)
// {
// 	char *temp;

// 	temp = ft_strnew(ft_strlen(d_name[index].name));
// 	ft_strcpy(temp, d_name[index].name);
// 	free(d_name[index].name);
// 	d_name[index].name = ft_strnew(ft_strlen(d_name[index + 1].name));
// 	ft_strcpy(d_name[index].name, d_name[index + 1].name);
// 	free(d_name[index + 1].name);
// 	d_name[index + 1].name = ft_strnew(ft_strlen(temp));
// 	ft_strcpy(d_name[index + 1].name, temp);
// 	free(temp);
// }

/*
**	Helper function for our sort ascii method to swap values 
**	based on their ascii value 
*/

t_dir	*lst_swap(t_dir *value_1, t_dir *value_2)
{
	value_1->next = value_2->next;
	value_2->next = value_1;
	return (value_2);
}


/*
**	Method to sort values in accending order according to their 
**	ascii values 
*/

static t_dir	*sort_ascii(t_dir *list)
{
	if (!list)
		return (NULL);
	if (list->next && ft_charcasecmp(ft_tolower(list->name[0]), ft_tolower(list->next->name[0])) > 0)
		list = lst_swap(list, list->next);
	list->next = sort_ascii(list->next);
	if (list->next && ft_charcasecmp(ft_tolower(list->name[0]), ft_tolower(list->next->name[0])) > 0)
	{
		list = lst_swap(list, list->next);
		list->next = sort_ascii(list->next);
	}
	return (list);
}

t_dir		*sort(t_dir *unsorted)
{
	t_dir	*sorted;

	sorted = sort_ascii(unsorted);
	return (sorted);
}

/*
	Method used to get the value of the names in our list and 
	store them within a string 
*/

char		*get_name(t_dir *list)
{
	char *name;

	name = list->name;
	return (name);
}

/*
	Method used to take in a list and reverse it,  a helper function for 
	when we use -r with ft_ls
*/

void		reverse_list(struct s_dir **head_ref, unsigned char flags)
{
	struct s_dir *prev;
	struct s_dir *current;
	struct s_dir *next;

	prev = NULL;
	current = *head_ref;
	next = NULL;
	while (current != NULL)
	{
		if (current->name[0] == '.' && !(flags & 2))
		{
			if (current->name[0] == 'a')
				continue;
			else
				current = current->next;
		}
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}









