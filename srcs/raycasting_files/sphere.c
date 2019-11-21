#include "raycast.h"

int				set_sphere(t_sphere *sphere, t_vec3 cen, double radius)
{
	if (radius <= 0.0)
		return (RT_FAIL);
	sphere->cen = cen;
	sphere->radius = radius;
	return (RT_SUCCESS);
}

t_vec2			sphere_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	void *object
)
{
	t_vec2		uv;
	t_sphere	*sphere;

	sphere = (t_sphere *)object;
	point = v3_sub(point, sphere->cen);
	point = m_mult(*axis_mat, point);
	uv.x = atan2(point.z, point.x) / (2.0 * M_PI);
	uv.y = acos(point.y / sphere->radius) / M_PI;
	return (uv);
}
