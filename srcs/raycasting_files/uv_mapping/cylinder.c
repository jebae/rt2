#include "raycast.h"
#include <stdio.h>

// need to discuss about center of cylinder
t_vec2			cyl_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	void *object
)
{
	t_vec2		uv;
	t_cyl		*cyl;
	double		temp;

	cyl = (t_cyl *)object;
	point = v3_sub(point, cyl->cen);
	point = m_mult(*axis_mat, point);
	uv.x = acos(point.x / cyl->radius) / (2.0 * M_PI);
	if (ft_is_inf(cyl->height))
		uv.y = ft_abs_double(modf(point.y, &temp));
	else
		uv.y = ft_abs_double(point.y) / cyl->height;
	return (uv);
}
