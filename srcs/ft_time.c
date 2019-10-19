#include "ft_ls.h"

void	get_m_time(const char *path, t_info *m_time)
{
	int			x;
	int			y;
	struct stat	buf;
	char		*mtime;
	char		*trim;

	x = 4;
	y = 0;
	trim = ft_strnew(15);
	stat(path, &buf);
	mtime = ctime(&buf.st_mtime);
	while (mtime[x] && x <= 14)
	{
		trim[y] = mtime[x];
		y++;
		x++;
	}
	m_time->m_time = ft_strdup(trim);
	free(trim);
}

void	get_m_time_reg(const char *path)
{
	int			x;
	int			y;
	struct stat	buf;
	char		*mtime;
	char		*trim;

	x = 4;
	y = 0;
	trim = ft_strnew(15);
	stat(path, &buf);
	mtime = ctime(&buf.st_mtime);
	while (mtime[x] && x <= 14)
	{
		trim[y] = mtime[x];
		y++;
		x++;
	}
	ft_putstr(trim);
	ft_putchar(' ');
	free(trim);
}

//see what the difference between the top two functions are
