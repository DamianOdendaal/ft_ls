#include "../includes/ft_ls.h"

char	*getuuid(uid_t uid)
{
	struct passwd *pswd;
	pswd = getpwuid(uid);
	return (pswd->pw_name);
}

char	*getggrgid(gid_t gid)
{
	struct group *pswd;
	pswd = getgrgid(gid);
	return (pswd->gr_name);
}