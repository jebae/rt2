#include "raycast.h"

t_vec2			cyl_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	t_texels *texels,
	void *object
)
{
	double		int_part;
	t_vec2		uv;
	t_cyl		*cyl;

	cyl = (t_cyl *)object;
	point = v3_sub(point, cyl->cen);
	point = m_mult(*axis_mat, point);
	uv.x = acos(point.x / cyl->radius) / (2.0 * M_PI) * texels->repeat;
	if (ft_is_inf(cyl->height))
		uv.y = point.y / (texels->height * 2.0 * M_PI / texels->width)
			* texels->repeat;
	else
		uv.y = point.y / cyl->height * texels->repeat;
	uv.x = modf(uv.x, &int_part);
	uv.y = modf(uv.y, &int_part);
	return (uv);
}
