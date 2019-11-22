#include "raycast.h"

static int		validate(double radius)
{
	if (radius <= 0.0)
		return (RT_FAIL);
	return (RT_SUCCESS);
}

static void		set_axis(t_mat3 *axis_mat)
{
	static double	axis[9] = {
		-1.0, 0.0, 0.0,
		0.0, -1.0, 0.0,
		0.0, 0.0, -1.0
	};

	ft_memcpy(axis_mat, axis, sizeof(t_mat3));
}

int				set_sphere(t_ol *ol, t_vec3 cen, double radius)
{
	t_sphere	*sphere;

	if (validate(radius) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_sp2;
	ol->get_normal = &normal_sphere;
    ol->uv_mapping = &sphere_uv_mapping;
	sphere = (t_sphere *)ol->object;
	sphere->cen = cen;
	sphere->radius = radius;
	set_axis(&ol->axis_mat);
	return (RT_SUCCESS);
}
