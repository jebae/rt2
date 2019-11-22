#include "rt.test.h"

static t_vec3		center;
static double		radius;

static void		setup_case1(t_ol *ol)
{

    center = (t_vec3){0.0, 0.0, 2.0};
    radius = 1.0;

	set_sphere(ol, center, radius);
}

int				setup_sphere(const char *cast_num, t_ol *ol)
{
	static void (*setup[])(t_ol *ol) = {
		&setup_case1
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
