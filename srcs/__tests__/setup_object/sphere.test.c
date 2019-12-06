#include "rt.test.h"

static t_arg_sphere	arg;
static t_vec3		velocity;

static void		setup_case1(t_ol *ol)
{
	velocity = (t_vec3){-1.0, 1.0, 0.0};
    arg.cen = (t_vec3){0.0, 0.0, 2.0};
    arg.radius = 1.0;

	ol->has_velocity = 1;
	ol->v_translate = v3_normalise(velocity);
	ol->init_speed = 2.0 * v3_norm(velocity);
	set_sphere(ol, &arg);
}

static void		setup_case2(t_ol *ol)
{
	velocity = (t_vec3){-1.0, 0.5, -2.0};
    arg.cen = (t_vec3){0.0, 0.0, 15.0};
    arg.radius = 1.0;

	ol->has_velocity = 1;
	ol->v_translate = v3_normalise(velocity);
	ol->init_speed = 10.0 * v3_norm(velocity);
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
