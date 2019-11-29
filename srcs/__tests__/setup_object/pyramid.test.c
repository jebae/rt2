#include "rt.test.h"

static t_arg_pyramid	arg;
static t_vec3			velocity;

static void		setup_case1(t_ol *ol)
{
	velocity = (t_vec3){1.0, -1.0, 0.2};
	arg.a = (t_vec3){-0.5, 0.5, 0.7};
	arg.u = (t_vec3){1.0, -0.5, 1.0};
	arg.v = (t_vec3){-1.0, 0.0, 1.0};
	arg.height = 1.0;

	ol->has_velocity = 1;
	ol->v_translate = v3_normalise(velocity);
	ol->init_speed = 2.0 * v3_norm(velocity);
	set_pyramid(ol, &arg);
}

static void		setup_case2(t_ol *ol)
{
	arg.a = (t_vec3){-0.5, 1.5, 0.7};
	arg.u = (t_vec3){1.0, 0.0, 0.0};
	arg.v = (t_vec3){0.0, -0.3, 0.5};
	arg.height = 1.0;

	set_pyramid(ol, &arg);
}

static void		setup_case3(t_ol *ol)
{
	arg.a = (t_vec3){-0.5, 1.0, 1.5};
	arg.u = (t_vec3){1.0, 0.0, 0.0};
	arg.v = (t_vec3){0.0, -1.0, 0.0};
	arg.height = 1.0;

	set_pyramid(ol, &arg);
}

int				setup_pyramid(const char *cast_num, t_ol *ol)
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
    ol->object = ft_memalloc(sizeof(t_pyramid));
	setup[*cast_num - '0' - 1](ol);
	return (RT_SUCCESS);
}
