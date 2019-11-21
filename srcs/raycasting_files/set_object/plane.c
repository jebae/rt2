#include "raycast.h"

static int		validate(t_vec3 *normal)
{
	if (v3_norm2(*normal) < APPROX_0)
		return (RT_FAIL);
	return (RT_SUCCESS);
}

int				set_plane(t_ol *ol, t_vec3 normal, double d)
{
	t_plane		*plane;

	if (validate(&normal) == RT_FAIL)
		return (RT_FAIL);
	plane = (t_plane *)ol->object;
	plane->normal = v3_normalise(normal);
	plane->d = d;
	pick_axis_from_plane(&plane->normal, &ol->axis_mat);
	return (RT_SUCCESS);
}
