#include "raycast.h"

int		set_sphere(t_sphere *sphere, t_vec3 cen, double radius)
{
	if (radius <= 0.0)
		return (RT_FAIL);
	sphere->cen = cen;
	sphere->radius = radius;
	return (RT_SUCCESS);
}
