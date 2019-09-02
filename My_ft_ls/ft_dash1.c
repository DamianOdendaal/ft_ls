#include "../includes/ft_ls.h"

void dash1(t_flags *flags)
{

    DIR *curdir;
    struct dirent *files;

    curdir = opendir(".");
    if (!curdir)
    {
        ft_putstr("No such directory");
        exit(1);
    }
    while ((files = readdir(curdir)) != NULL)
    {
        if (!(*flags & f_a) && files->d_name[0] == '.')
            continue;
        else
		{
            ft_putendl(files->d_name);
       }
    }
    closedir(curdir);
}