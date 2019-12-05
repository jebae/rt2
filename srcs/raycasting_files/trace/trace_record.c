#include "raycast.h"

void			set_trace_record(t_trace_record *rec)
{
	t_vec2		uv;
	t_ol		*obj;

	obj = rec->obj;
	rec->point = find_point_from_ray(rec->ray);
	rec->normal = obj->get_normal(rec->ray, obj->object);
	if (obj->texture.buffer != NULL)
	{
		uv = obj->uv_mapping(
			rec->point, &obj->axis_mat, &obj->texture, obj->object);
		rec->color = get_texel_color(&uv, &obj->texture);
	}
	else
		rec->color = obj->dif;
	if (obj->bump_map.buffer != NULL)
	{
		uv = obj->uv_mapping(
			rec->point, &obj->axis_mat, &obj->bump_map, obj->object);
		rec->normal = get_bumped_normal(
			&uv, &obj->bump_map, &rec->normal, &obj->axis_mat);
	}
}
