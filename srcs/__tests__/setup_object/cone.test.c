#include "rt.test.h"

static t_arg_cone	arg;
static t_vec3		velocity;

static void		setup_case1(t_ol *ol)
{
	velocity = (t_vec3){-1.0, -1.0, 0.2};
    arg.cen = (t_vec3){0.0, -1.0, 2.0};
    arg.axis = (t_vec3){0.0, 1.0, 0.0};
	arg.angle = 30;
	arg.upper_height = 2.0;
	arg.lower_height = 1.0;

	ol->has_velocity = 1;
	ol->v_translate = v3_normalise(velocity);
	ol->init_speed = 2.0 * v3_norm(velocity);
	set_cone(ol, &arg);
}

static void		setup_case2(t_ol *ol)
{
    arg.cen = (t_vec3){0.0, -1.0, 5.0};
    arg.axis = (t_vec3){1.0, 1.0, 0.0};
	arg.angle = 30;
	arg.upper_height = INFINITY;
	arg.lower_height = 2.0;

	set_cone(ol, &arg);
}

int				setup_cone(const char *cast_num, t_ol *ol)
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
    ol->object = ft_memalloc(sizeof(t_cone));
	setup[*cast_num - '0' - 1](ol);
	return (RT_SUCCESS);
}
