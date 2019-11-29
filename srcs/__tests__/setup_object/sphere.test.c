#include "rt.test.h"

static t_vec3		center;
static double		radius;
static t_vec3		velocity;

static void		setup_case1(t_ol *ol)
{
	velocity = (t_vec3){-1.0, 1.0, 0.0};
    center = (t_vec3){0.0, 0.0, 2.0};
    radius = 1.0;

	ol->has_velocity = 1;
	ol->v_translate = v3_normalise(velocity);
	ol->init_speed = 2.0 * v3_norm(velocity);
	set_sphere(ol, center, radius);
}

static void		setup_case2(t_ol *ol)
{
	velocity = (t_vec3){-1.0, 0.5, -2.0};
    center = (t_vec3){0.0, 0.0, 8.0};
    radius = 1.0;

	ol->has_velocity = 1;
	ol->v_translate = v3_normalise(velocity);
	ol->init_speed = 5.0 * v3_norm(velocity);
	set_sphere(ol, center, radius);
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
