#include "rt.test.h"

t_arg_triangle		arg;

static void		setup_case1(t_ol *ol)
{
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){0.5, 0.5, 1.5};
	arg.ac = (t_vec3){-0.5, 0.5, 0.0};

	set_triangle(ol, &arg);
}

static void		setup_case2(t_ol *ol)
{
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){1.0, 0.0, 1.5};
	arg.ac = (t_vec3){-0.5, 1.0, 0.0};

	set_triangle(ol, &arg);
}

int				setup_triangle(const char *cast_num, t_ol *ol)
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
    ol->object = ft_memalloc(sizeof(t_triangle));
	setup[*cast_num - '0' - 1](ol);
	return (RT_SUCCESS);
}
