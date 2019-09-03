#include "../includes/ft_ls.h"

int isFile(const char* name)
{
    DIR* directory = opendir(name);

    if (directory != NULL)
    {
        closedir(directory);
        return (2);
    }

    if (errno == ENOTDIR)
        return (1);

    return (-1);
}

// int main(int ac, char **av)
// {
//     if (ac > 1)
//     {
//         printf("Is %s a file? %s.\n", av[1], ((isFile(av[1]) == 1) ? "Yes" : "No"));
//         printf("Is %s a directory? %s.\n", av[1], ((isFile(av[1]) == 2) ? "Yes" : "No"));
//     }
//     return 0;
// }