#include "raycast.h"

t_vec2			rectangle_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	t_texture *texture,
	void *object
)
{
	double			int_part;
	t_vec2			uv;
	t_rectangle		*rect;

	rect = (t_rectangle *)object;
	point = v3_sub(point, rect->p);
	point = m_mult(*axis_mat, point);
	uv.x = point.x / rect->norm_a * texture->repeat;
	uv.y = point.z / rect->norm_b * texture->repeat;
	uv.x = modf(uv.x, &int_part);
	uv.y = modf(uv.y, &int_part);
	return (uv);
}
