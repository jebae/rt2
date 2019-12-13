#include "rt.h"

int		handle_fail(const char *msg)
{
	ft_putstr(KRED);
	ft_putstr("Failed : ");
	ft_putendl(msg);
	ft_putstr(KNRM);
	return (RT_FAIL);
}
