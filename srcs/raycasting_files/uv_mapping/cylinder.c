#include "raycast.h"

t_vec2			cyl_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	t_texture *texture,
	void *object
)
{
	double		int_part;
	t_vec2		uv;
	t_cyl		*cyl;

	cyl = (t_cyl *)object;
	point = v3_sub(point, cyl->cen);
	point = m_mult(*axis_mat, point);
	uv.x = acos(point.x / cyl->radius) / (2.0 * M_PI) * texture->repeat;
	if (ft_is_inf(cyl->height))
		uv.y = point.y / (texture->height * 2.0 * M_PI / texture->width)
			* texture->repeat;
	else
		uv.y = point.y / cyl->height * texture->repeat;
	uv.x = modf(uv.x, &int_part);
	uv.y = modf(uv.y, &int_part);
	return (uv);
}
