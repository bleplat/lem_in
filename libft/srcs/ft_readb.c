#include "unistd.h"

#include "libft.h"

/*
** Same as read but with an internal buffer.
** buffer size is FT_READB_SIZE.
** Handle a single fd at once.
*/

int				ft_readb(int fd, char *buffer, size_t cnt)
{
	static char		buff[FT_READB_SIZE];
	static int		ri = 0;
	static int		rc = 0;
	int				readed;

	if (ri == 0)
		rc = read(fd, buff, cnt);
	readed = ft_min(rc - ri, cnt);
	ft_memcpy(buffer, buff + ri, readed);
	cnt -= readed;
	if (rc > 0)
		ri = (ri + readed) % rc;
	if (cnt)
		readed += read(fd, buffer + readed, cnt);
	return (readed);
}
