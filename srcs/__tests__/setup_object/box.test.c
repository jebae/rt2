#include "rt.test.h"

static t_arg_box	arg;

static void		setup_case1(t_ol *ol)
{
	arg.vmin = (t_vec3){-1.0, 1.0, 1.0};
	arg.a = (t_vec3){2.0, 0.0, 2.0};
	arg.b = (t_vec3){0.0, 0.5, 0.0};
	arg.norm_c = 1.0;

	set_box(ol, &arg);
}

static void		setup_case2(t_ol *ol)
{
	arg.vmin = (t_vec3){-1.0, 1.0, 1.0};
	arg.a = (t_vec3){2.0, -0.6, 2.0};
	arg.b = (t_vec3){0.0, 0.5, 0.15};
	arg.norm_c = 1.0;

	set_box(ol, &arg);
}

static void		setup_case3(t_ol *ol)
{
	arg.vmin = (t_vec3){-1.0, 1.0, 5.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, -2.0, 0.0};
	arg.norm_c = 1.0;

	set_box(ol, &arg);
}

int				setup_box(const char *cast_num, t_ol *ol)
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
    ol->object = ft_memalloc(sizeof(t_box));
	setup[*cast_num - '0' - 1](ol);
	return (RT_SUCCESS);
}
