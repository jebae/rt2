#include "rt.test.h"

static t_arg_cone	arg;

static void		setup_case1(t_ol *ol)
{
    arg.cen = (t_vec3){0.0, -1.0, 2.0};
    arg.axis = (t_vec3){0.0, 1.0, 0.0};
	arg.angle = 30;

	set_cone(ol, &arg);
}

int				setup_cone(const char *cast_num, t_ol *ol)
{
	static void (*setup[])(t_ol *ol) = {
		&setup_case1
	};

	if (*cast_num - '0' > (int)(sizeof(setup) / sizeof(void *)))
	{
		printf(KRED "Error : case not exist\n" KNRM);
		return (RT_FAIL);
	}
    ol->object = ft_memalloc(sizeof(t_cone));
	setup[*cast_num - '0' - 1](ol);
	return (RT_SUCCESS);
}
