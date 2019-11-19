#include "raycast.h"

int		set_plane(t_plane *plane, t_vec3 normal, double d)
{
	if (v3_norm2(normal) == 0.0)
		return (RT_FAIL);
	plane->normal = v3_normalise(normal);
	plane->d = d;
	return (RT_SUCCESS);
}
