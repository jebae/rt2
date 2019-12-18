#include "rt.test.h"

static t_arg_sphere	arg;

static void		setup_case1(t_ol *ol)
{
    arg.cen = (t_vec3){0.0, -1.0, 2.0};
    arg.radius = 1.0;

	set_sphere(ol, &arg);
}

static void		setup_case2(t_ol *ol)
{
    arg.cen = (t_vec3){0.0, 0.0, 15.0};
    arg.radius = 1.0;

	set_sphere(ol, &arg);
}

int				setup_sphere(const char *cast_num, t_ol *ol)
{
	static void (*setup[])(t_ol *ol) = {
		&setup_case1,
		&setup_case2
	};

	if (*cast_num - '0' > (int)(sizeof(setup) / sizeof(void *)))
	{
		printf(KRED "Error : case not exist\n" KNRM);
		return (RT_FAIL);
	}
    ol->object = ft_memalloc(sizeof(t_sphere));
	setup[*cast_num - '0' - 1](ol);
	return (RT_SUCCESS);
}
