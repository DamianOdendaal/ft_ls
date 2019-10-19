// header here bruh

void	get_group(const char *path, t_info *group)
{
	struct stat		buf;
	struct group	*g_info;
	gid_t			gid;

	stat(path, &buf);
	gid = buf.st_gid;
	g_info = getgrgid(gid);
	group->group = g_info->gr_name;
}


void	get_group_reg(const char *path)
{
	struct stat		buf;
	struct group	*g_info;
	gid_t			gid;

	stat(path, &buf);
	gid = buf.st_gid;
	g_info = getgrgid(gid);
	ft_putstr(g_info->gr_name);
	ft_putchar(' ');
} 										//try and understand the diff between the two abovementioned functions

void	get_links(const char *path, t_info *link)
{
	struct stat links;

	stat(path, &links);
	link->links = links.st_nlink;
}

void	get_links_reg(const char *path)
{
	struct stat links;

	stat(path, &links);
	ft_putnbr(links.st_nlink);
	ft_putchar(' ');
}
