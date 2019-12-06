#include "rt.h"

void		pick_axis_from_plane(t_vec3 *normal, t_mat3 *axis_mat)
{
	static t_vec3	xw = (t_vec3){1.0, 0.0, 0.0};
	static t_vec3	yw = (t_vec3){0.0, 1.0, 0.0};
	t_vec3			x;
	t_vec3			z;

	x = v3_cross(*normal, xw);
	if (v3_norm2(x) < RT_APPROX_0)
		x = v3_cross(*normal, yw);
	x = v3_normalise(x);
	z = v3_cross(x, *normal);
	ft_memcpy(axis_mat->arr[0], &x, sizeof(t_vec3));
	ft_memcpy(axis_mat->arr[1], normal, sizeof(t_vec3));
	ft_memcpy(axis_mat->arr[2], &z, sizeof(t_vec3));
}

// not using in production
void		init_ol(t_ol *ol)
{
	ol->object = NULL;
	ol->texture.buffer = NULL;
	ol->bump_map.buffer = NULL;
	ol->intersect = NULL;
	ol->get_normal = NULL;
	ol->uv_mapping = NULL;
	ol->translate = NULL;
	ol->has_velocity = RT_FALSE;
}
