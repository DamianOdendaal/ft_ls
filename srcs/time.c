/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 18:25:16 by Mr_Ode            #+#    #+#             */
/*   Updated: 2020/05/14 09:06:30 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static void		match_times(t_dir *names, time_t filetimes[])
{
	int				i;
	struct stat		filestat;

	i = 0;
    while (names->next != null)
	{
		lstat(names->name,  &filestat);
		filetimes[i++] = filestat.st_mtimespec.tv_sec;
		names->next;
	}
}

static void		swap_tsec(char **none, char **ntwo, time_t *tone, time_t *ttwo)
{
	char			*temp;
	time_t			temptime;

	temp = *none;
	*none = *ntwo;
	*ntwo = temp;
	temptime = *tone;
	*tone = *ttwo;
	*ttwo = temptime;
}

static void		swap_tnsec(char **name1, char **name2)
{
	char		*temp;
	struct stat	name1stat;
	struct stat	name2stat;

	lstat(*name1, &name1stat);
	lstat(*name2, &name2stat);
	if (name1stat.st_mtimespec.tv_nsec < name2stat.st_mtimespec.tv_nsec)
	{
		temp = *name1;
		*name1 = *name2;
		*name2 = temp;
	}
}



void			sort_time(t_dir *names, int len)
{
	time_t			ftm[len];
	int				i;
	int				j;

	match_times(names, ftm);
	i = 0;
	j = 0;
	while (j++ < len)
	{
		while (i < len - 1)
		{
			if (ftm[i] < ftm[i + 1])
				swap_tsec(&names[i], &names[i + 1], &ftm[i], &ftm[i + 1]);
			else if (ftm[i] == ftm[i + 1])
				swap_tnsec(&names[i], &names[i + 1]);
			i++;
		}
		i = 0;
	}
}

// enrico


// int	*find_time(t_dir *direct_name)
// {
// 	int			x;
// 	int			y;
// 	int			time_len;
// 	int			*time;
// 	struct stat	buf;

// 	x = 0;
// 	y = 0;
// 	time_len = 0;
// 	while (direct_name[time_len].name)
// 		time_len++;
// 	time = (int *)malloc(sizeof(int) * time_len);
// 	while (direct_name[x].name)
// 	{
// 		stat(direct_name[x].name, &buf);
// 		time[y] = buf.st_mtimespec.tv_sec;
// 		y++;
// 		x++;
// 	}
// 	return (time);
// }


// void	t_sorting(t_dir *direct_name)
// {
// 	int d;
// 	int e;
// 	int *time;

// 	e = 0;
// 	time = find_time(direct_name);
// 	while (direct_name[e].name && direct_name[e].name != NULL)
// 		e++;
// 	e--;
// 	while (e)
// 	{
// 		d = 0;
// 		while (d < e)
// 		{
// 			if (time[d] < time[d + 1])
// 			{
// 				ft_swap(&time[d], &time[d + 1]);
// 				swap(direct_name, d);
// 			}
// 			d++;
// 		}
// 		e--;
// 	}
// 	free(time);
// }

// // where the method is being called
// // void	info_sort_2(t_flags *flags, t_info *info, int a)
// // {
// // 	if (flags->t_flag == 1)
// // 	{
// // 		r_sorting_2(info, a);
// // 		t_sorting_2(info, a);
// // 	}
// // 	else
// // 		sorting_2(info, a);
// // 	if (flags->r_flag == 1)
// // 		r_sort_2(info, a);
// // }


// void	info_sort_2(unsigned int flags, t_dir *info)
// {
// 	if (flags & 16)
// 	{
// 		// r_sorting_2(info, a);
// 		t_sorting_2(info);
// 	}
// 	// else
// 	// 	sorting_2(info, a);
// 	// if (flags & 8)
// 	// 	r_sort_2(info, a);
// }

// void	t_sorting_2(t_info *direct_name, int x)
// {
// 	int d;
// 	int *time;

// 	time = find_time(direct_name);
// 	x--;
// 	while (x)
// 	{
// 		d = 0;
// 		while (direct_name[d + 1].links != 1)
// 		{
// 			if (time[d] < time[d + 1])
// 			{
// 				ft_swap(&time[d], &time[d + 1]);
// 				swap(direct_name, d);
// 			}
// 			d++;
// 		}
// 		x--;
// 	}
// 	free(time);
// }