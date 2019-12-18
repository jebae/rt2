#include "rt.test.h"

static t_arg_plane	arg;

static void		setup_case1(t_ol *ol)
{
    arg.normal = (t_vec3){0.0, 1.0, 0.0};
	arg.d = -2;

	set_plane(ol, &arg);
}

static void		setup_case2(t_ol *ol)
{
    arg.normal = (t_vec3){0.0, 0.0, 1.0};
	arg.d = -2;

	set_plane(ol, &arg);
}

int				setup_plane(const char *cast_num, t_ol *ol)
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
    ol->object = ft_memalloc(sizeof(t_plane));
	setup[*cast_num - '0' - 1](ol);
	return (RT_SUCCESS);
}
