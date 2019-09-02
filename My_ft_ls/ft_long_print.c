#include "../includes/ft_ls.h"

void long_print(int argc, char **argv)
{
   //  if(argc != 2)    
   //     return 1;

    struct stat fileStat;
   //  if(stat(argv[1],&fileStat) < 0)    
   //     return 1;
    (S_ISDIR(fileStat.st_mode)) ? ft_putchar('d') : ft_putchar('-');
    (fileStat.st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
    (fileStat.st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
    (fileStat.st_mode & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
    (fileStat.st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
    (fileStat.st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
    (fileStat.st_mode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
    (fileStat.st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
    (fileStat.st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
    (fileStat.st_mode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
   //  printf("\n\n");
    ft_putchar('\n');

   //  printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");

   //  return 0;
}