#include "_atoi_base.h"

int	atoi_base_07(void)
{
	char	*str = "0101";
	int		exp = atoi_base_ref(str, BAD_BASE_SIGN4);
	int		got = ft_atoi_base(str, BAD_BASE_SIGN4);

	if (exp == got)
		return (0);
	else
		return (-1);
}
