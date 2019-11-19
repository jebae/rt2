#include "raycast.h"

static double	get_plane_intersection_t(t_ray *ray, t_rectangle *rect)
{
	t_plane			plane;

	plane.normal = rect->normal;
	plane.d = rect->d;
	return (v_intersect_pl(*ray, &plane));
}

double			v_intersect_rectangle(t_ray ray, void *object)
{
	double			length;
	double			t;
	t_vec3			pp;
	t_rectangle		*rect;

	rect = (t_rectangle *)object;
	t = get_plane_intersection_t(&ray, rect);
	if (t == FAR)
		return (FAR);
	ray.t = t;
	pp = v3_sub(find_point_from_ray(ray), rect->p);
	length = v3_dotpdt(pp, rect->a);
	if (length < 0.0 || length > rect->norm_a)
		return (FAR);
	length = v3_dotpdt(pp, rect->b);
	if (length < 0.0 || length > rect->norm_b)
		return (FAR);
	return (t);
}

t_vec3			normal_rectangle(t_ray ray, void *object)
{
	t_rectangle		*rect;

	rect = (t_rectangle *)object;
	if (v3_dotpdt(ray.dir, rect->normal) <= 0)
		return (rect->normal);
	else 
		return (v3_scalar(rect->normal, -1));
}

int				set_rectangle(t_rectangle *rect, t_arg_rectangle *arg)
{
	if (v3_norm2(arg->a) == 0.0 || v3_norm2(arg->b) == 0 ||
		ft_abs_double(v3_dotpdt(arg->a, arg->b)) > APPROX_0)
		return (RT_FAIL);
	rect->p = arg->p;
	rect->a = v3_normalise(arg->a);
	rect->b = v3_normalise(arg->b);
	rect->normal = v3_cross(rect->a, rect->b);
	rect->norm_a = v3_norm(arg->a);
	rect->norm_b = v3_norm(arg->b);
	rect->d = v3_dotpdt(rect->p, rect->normal);
	return (RT_SUCCESS);
}
