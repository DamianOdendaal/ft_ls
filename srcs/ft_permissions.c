#include "../includes/ft_ls.h"

void ft_perm(t_ls_info *t_info, struct stat st)
{
   // (S_ISDIR(fileStat->st_mode)) ? ft_putchar('d') : ft_putchar('-');
  ((st.st_mode & S_IFMT) == S_IFDIR) ? t_info->perm[0] = 'd' : 0;
   // (fileStat->st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
   
  ((st.st_mode & S_IFMT) == S_IFREG) ? t_info->perm[0] = '-' : 0;
  //(fileStat->st_mode & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
  ((st.st_mode & S_IFMT) == S_IFCHR) ? t_info->perm[0] = 'c' : 0;
    (fileStat->st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
    (fileStat->st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
    (fileStat->st_mode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
    (fileStat->st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
    (fileStat->st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
    (fileStat->st_mode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
}
