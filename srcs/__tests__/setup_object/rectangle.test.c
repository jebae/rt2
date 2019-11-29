#include "rt.test.h"

static t_arg_rectangle	arg;
static t_vec3			velocity;

static void		setup_case1(t_ol *ol)
{
	velocity = (t_vec3){-1.0, -1.0, 0.2};
	arg.p = (t_vec3){-6.0, 3.0, 1.0};
	arg.a = (t_vec3){12.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 0.0, 12.0};

	ol->has_velocity = 1;
	ol->v_translate = v3_normalise(velocity);
	ol->init_speed = 4.0 * v3_norm(velocity);
	set_rectangle(ol, &arg);
}

static void		setup_case2(t_ol *ol)
{
	arg.p = (t_vec3){-1.0, 1.0, 1.0};
	arg.a = (t_vec3){2.0, -1.0, -1.0};
	arg.b = (t_vec3){0.0, -1.0, 1.0};

	set_rectangle(ol, &arg);
}

static void		setup_case3(t_ol *ol)
{
	arg.p = (t_vec3){-3.0, 3.0, 2.0};
	arg.a = (t_vec3){6.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, -6.0, 0.0};

	set_rectangle(ol, &arg);
}

int				setup_rectangle(const char *cast_num, t_ol *ol)
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
    ol->object = ft_memalloc(sizeof(t_rectangle));
	setup[*cast_num - '0' - 1](ol);
	return (RT_SUCCESS);
}
