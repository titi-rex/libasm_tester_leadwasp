#include "_write.h"

int	write_10(void)
{
	const char	*str = "\n\n\n\t\the\n\r\r\tjei";
	size_t		len = strlen(str);
	ssize_t		r_exp = write(STDOUT_FILENO, str, len);
	ssize_t		r_got = ft_write(STDOUT_FILENO, str, len);

	if (r_exp == r_got)
		return (0);
	else
		return (-1);
}
