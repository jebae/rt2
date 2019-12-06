#include "rt.test.h"

static t_arg_cyl	arg;
static t_vec3		velocity;

static void		setup_case1(t_ol *ol)
{
	velocity = (t_vec3){-1.0, 0.8, -2.0};
    arg.cen = (t_vec3){-1.0, 0.0, 10.0};
    arg.axis = (t_vec3){1.0, 1.0, 0.0};
	arg.radius = 0.5;
	arg.height = 10.0;

	ol->has_velocity = 1;
	ol->v_translate = v3_normalise(velocity);
	ol->init_speed = 2.0 * v3_norm(velocity);
	set_cyl(ol, &arg);
}

static void		setup_case2(t_ol *ol)
{
    arg.cen = (t_vec3){0.0, -1.0, 10.0};
    arg.axis = (t_vec3){1.0, 1.0, 0.0};
	arg.radius = 1.0;
	arg.height = INFINITY;

	set_cyl(ol, &arg);
}

int				setup_cylinder(const char *cast_num, t_ol *ol)
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
    ol->object = ft_memalloc(sizeof(t_cyl));
	setup[*cast_num - '0' - 1](ol);
	return (RT_SUCCESS);
}
