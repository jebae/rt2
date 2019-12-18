#include "rt.test.h"

static t_arg_ring	arg;

static void		setup_case1(t_ol *ol)
{
	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = v3_normalise((t_vec3){0.0, -1.0, -0.3});
	arg.r1 = 0.4;
	arg.r2 = 0.5;

	set_ring(ol, &arg);
}

static void		setup_case2(t_ol *ol)
{
	arg.center = (t_vec3){1.0, 0.5, 3.0};
	arg.normal = v3_normalise((t_vec3){-0.5, -1.5, -0.1});
	arg.r1 = 1.0;
	arg.r2 = 1.5;

	set_ring(ol, &arg);
}

static void		setup_case3(t_ol *ol)
{
	arg.center = (t_vec3){1.0, 0.5, 3.0};
	arg.normal = v3_normalise((t_vec3){-0.5, -1.5, -0.1});
	arg.r1 = 0.0;
	arg.r2 = 1.5;

	set_ring(ol, &arg);
}

int				setup_ring(const char *cast_num, t_ol *ol)
{
	static void (*setup[])(t_ol *ol) = {
		&setup_case1,
		&setup_case2,
		&setup_case3
	};

	if (*cast_num - '0' > (int)(sizeof(setup) / sizeof(void *)))
	{
		printf(KRED "Error : case not exist\n" KNRM);
		return (RT_FAIL);
	}
    ol->object = ft_memalloc(sizeof(t_ring));
	setup[*cast_num - '0' - 1](ol);
	return (RT_SUCCESS);
}
