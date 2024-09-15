#include "_read.h"

int	read_08(void)
{
	char			buff[50];
	const size_t	len = 40;
	int				exp;
	int				got;

	errno = 0;
	exp = read(BADFDS, buff, len);
	if (exp != -1)
		return (-2);
	exp = errno;

	errno = 0;
	ft_read(BADFDS, buff, len);
	got = errno;

	if (exp == got)
		return (0);
	else
		return (-1);
}