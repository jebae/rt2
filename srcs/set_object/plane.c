#include "rt.h"

static int		validate(t_arg_plane *arg)
{
	if (v3_norm2(arg->normal) < RT_APPROX_0)
		return (handle_fail("set_plane : normal's length almost 0"));
	return (RT_SUCCESS);
}

int				set_plane(t_ol *ol, t_arg_plane *arg)
{
	t_plane		*plane;

	if (validate(arg) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_pl;
	ol->get_normal = &normal_plane;
	ol->translate = &plane_translate;
	ol->rotate = &plane_rotate;
	plane = (t_plane *)ol->object;
	plane->normal = v3_normalise(arg->normal);
	plane->d = arg->d;
	pick_axis_from_plane(&plane->normal, &ol->axis_mat);
	return (RT_SUCCESS);
}
