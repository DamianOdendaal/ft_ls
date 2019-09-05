/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:54:04 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/03 12:54:07 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"

void	ft_print_bits(int c)
{
	int out;
	int i;

	out = 0;
	i = 32;
	while (i--)
	{
		out = (c >> i & 1) + '0';
		ft_putchar(out);
		if (i % 8 == 0 && i != 0)
			ft_putchar(' ');
	}
}



int main(int ac, char **av)
{
	int i;
	t_flags	flags;

	flags = 0;
	ft_print_bits(flags);
	ft_putendl("");


	i = 0;
	if (ac == 1)
		currdir(&flags);
	if (ac > 1)
		i = check_flags(av, &flags);
	ft_putendl("");
	if (!av[i])
		currdir(&flags);
 	// ft_print_bits(flags);
	ft_putendl("");
	if (flags & f_a)
	{
		ft_putstr("flag a is set");
		ft_putendl("");
	}
	if (flags & f_l)
	{
		// ft_putstr("flag l is set");
		long_print();
		ft_putendl("");
	}
	if (flags & f_r)
	{
		ft_putstr("flag r is set");
		ft_putendl("");
	}
	if (flags & f_R)
	{
		ft_putstr("flag R is set");
		ft_putendl("");
	}
	if (flags & f_t)
	{
		ft_putstr("flag t is set");
		ft_putendl("");
	}
	if (flags & f_1)
	{
		dash1(&flags);
		ft_putendl("");
	}




























	// parsing:
	// 	- flags -> set flags
	// 	- error/file/dir -> print errors, the files, the dirs

	// data:
	// 	- create data structure based on dirs
	
	// sort:
	// 	- lex if no sort flags 
	// 	- time if -t
	
	// print:
	// 	- 1 of no -l flag
	// 	- l if -l
	// 	- a if -a
	
	// clean:
	// 	- freee yo shit - EVERY FUCKING ITME

	// RECURSIVE: OPEN DIRS IN CURRENT DIR
	
	// struct stat { /* when _DARWIN_FEATURE_64_BIT_INODE is NOT defined */
    //      dev_t    st_dev;    /* device inode resides on */
    //      ino_t    st_ino;    /* inode's number */
         
	// 	 mode_t   st_mode;   /* inode protection mode */
         
	// 	 nlink_t  st_nlink;  /* number of hard links to the file */
    //      uid_t    st_uid;    /* user-id of owner */
    //      gid_t    st_gid;    /* group-id of owner */
    //      dev_t    st_rdev;   /* device type, for special file inode */
    //      struct timespec st_atimespec;  /* time of last access */
    //      struct timespec st_mtimespec;  /* time of last data modification */
    //      struct timespec st_ctimespec;  /* time of last file status change */
    //      off_t    st_size;   /* file size, in bytes */
    //      quad_t   st_blocks; /* blocks allocated for file */
    //      u_long   st_blksize;/* optimal file sys I/O ops blocksize */
    //      u_long   st_flags;  /* user defined flags for file */
    //      u_long   st_gen;    /* file generation number */
    //  };

	//  #define S_IFMT 0170000           /* type of file */
    //  #define        S_IFIFO  0010000  /* named pipe (fifo) */
    //  #define        S_IFCHR  0020000  /* character special */
    //  #define        S_IFDIR  0040000  /* directory */
    //  #define        S_IFBLK  0060000  /* block special */
    //  #define        S_IFREG  0100000  /* regular */
    //  #define        S_IFLNK  0120000  /* symbolic link */
    //  #define        S_IFSOCK 0140000  /* socket */
    //  #define        S_IFWHT  0160000  /* whiteout */
    //  #define S_ISUID 0004000  /* set user id on execution */
    //  #define S_ISGID 0002000  /* set group id on execution */
    //  #define S_ISVTX 0001000  /* save swapped text even after use */
    //  #define S_IRUSR 0000400  /* read permission, owner */
    //  #define S_IWUSR 0000200  /* write permission, owner */
    //  #define S_IXUSR 0000100  /* execute/search permission, owner */













	// struct stat	s_stat;

	// lstat(path, &s_stat);

	// if ((s_stat.st_mode & IS_FMT) == S_IFDIR)
	// 	// file is a dir
	// if ((s_stat.st_mode & IS_FMT) == S_IFREG)
	// 	// file is a regualr file

	// if (S_IFDIR(s_stat))
	// 	// file is a dir
	return (0);
}
