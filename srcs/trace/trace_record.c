#include "rt.h"

t_vec3			find_point_from_ray(t_ray ray)
{
	t_vec3		point;

	point.x = ray.ori.x + ray.dir.x * ray.t;
	point.y = ray.ori.y + ray.dir.y * ray.t;
	point.z = ray.ori.z + ray.dir.z * ray.t;
	return (point);
}

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

void			set_origin_trace_record(t_env *e, t_trace_record *rec)
{
	rec->ray = cast_ray(e->x, e->y, e);
	rec->ray.ior = 1.0;
	rec->depth = 0;
	rec->prev = NULL;
}
