// header here bruh 

#include "ft_ls.h"

int		do_stuff(t_info *info, const char *path, int y, int t)
{
	if (t == 0)
		while (t < y)
			t++;
	open_dir(path, info);
	return (t);
}

int		check_null(t_info *info, int *z)
{
	*z = -1;
	if (info[0].direct_n == NULL)
	{
		free(info);
		return (1);
	}
	else
		return (0);
}

void	free_info(t_info *info)
{
	int z;

	z = 0;
	while (info[z].n_direct_n && info[z].n_direct_n != NULL)
	{
		free(info[z].n_direct_n);
		free(info[z].direct_n);
		z++;
	}
	free(info);
}

int		recursion(const char *path, t_dir *d, t_flags *flags, int y)
{
	static int	t = 0;
	int			z;
	char		*temp;
	t_info		*info;

	info = (t_info *)malloc(sizeof(t_info) * 4294967295);
	t = do_stuff(info, path, y, t);
	if (check_null(info, &z) == 1)
		return (t);
	else
	{
		info_sort(flags, info);
		while (info[++z].n_direct_n && info[z].n_direct_n != NULL)
			if (is_dir(info[z].n_direct_n) == 1 && dot(info[z].direct_n) == 1)
			{
				d[t].direct_o = ft_strnew(ft_strlen(info[z].n_direct_n));
				temp = ft_strdup(info[z].n_direct_n);
				ft_strcpy(d[t].direct_o, temp);
				t++;
				recursion(temp, d, flags, y);
				free(temp);
			}
	}
	free_info(info);
	return (t);
}
