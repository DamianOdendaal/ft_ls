/*header here*/
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
/* #include "libft/libft.h" */
#include <stdio.h>


int main (int argc, char *argv[])
{
	DIR *dir;
	struct dirent *sd;

	dir = opendir(".");
	if (dir == NULL)
	{
		printf("Sorry this is not a valid directory\n");
		exit(1);
	}

	while (sd=readdir(dir) != NULL)
		printf(">>%s\n", sd->d_name);
	closedir(dir);
	return(0);
}
