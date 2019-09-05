#include "../includes/ft_ls.h"

t_bool isFile(const char* name)
{
    DIR* directory = opendir(name);

    if (directory != NULL)
    {
        closedir(directory);
        return (FALSE);
    }

    return (errno == ENOTDIR);// ? TRUE : FALSE;
}

// #include "limits.h"

// int main(int ac, t_strArray av)
// {

//     // printf("%d\n%d\n", MININT, MAXINT);

//     // #define MAXLONG ~(1L << 63)
//     // #define MINLONG (1L << 63)

//     // printf("%ld\n%ld\n", LONG_MAX, MAXLONG);
//     // printf("%ld\n%ld\n", LONG_MIN, MINLONG);
//     // printf("%d\n", (1 << 4));

//     if (ACOUNT(ac))
//         printf("%s Is a %s\n", av[1], isFile((const char *)av[1]) ? "FILE" : "FOLDER/DIR");
//     return 0;
// }