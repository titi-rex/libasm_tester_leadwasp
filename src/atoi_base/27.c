#include "_atoi_base.h"

int	atoi_base_27(void)
{
	char	*str = "-ofv";
	int		exp = atoi_base_ref(str, BASE_OCTA_STR);
	int		got = ft_atoi_base(str, BASE_OCTA_STR);

	if (exp == got)
		return (0);
	else
		return (-1);
}
