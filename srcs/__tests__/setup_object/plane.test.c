#include "rt.test.h"

static t_vec3		normal;
static double		d;

static void		setup_case1(t_ol *ol)
{
    normal = (t_vec3){0.0, 1.0, 0.0};
	d = -2;

	set_plane(ol, normal, d);
}

int				setup_plane(const char *cast_num, t_ol *ol)
{
	static void (*setup[])(t_ol *ol) = {
		&setup_case1
	};

	if (*cast_num - '0' > (int)(sizeof(setup) / sizeof(void *)))
	{
		printf(KRED "Error : case not exist\n" KNRM);
		return (RT_FAIL);
	}
    ol->object = ft_memalloc(sizeof(t_plane));
	setup[*cast_num - '0' - 1](ol);
	return (RT_SUCCESS);
}