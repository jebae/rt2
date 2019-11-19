#include "raycast.h"

double			v_intersect_triangle(t_ray ray, void *object)
{
	t_triangle		*triangle;
	double			det_m;
	double			t;
	double			u;
	double			v;

	triangle = (t_triangle *)object;
	ray.dir = v3_scalar(ray.dir, -1.0);
	ray.ori = v3_sub(ray.ori, triangle->a);
	det_m = v3_dotpdt(ray.dir,
		v3_cross(triangle->ab, triangle->ac));
	if (det_m == 0.0)
		return (FAR);
	t = v3_dotpdt(ray.ori,
		v3_cross(triangle->ab, triangle->ac)) / det_m;
	u = v3_dotpdt(ray.dir,
		v3_cross(ray.ori, triangle->ac)) / det_m;
	v = v3_dotpdt(ray.dir,
		v3_cross(triangle->ab, ray.ori)) / det_m;
	if (t < 0.0 || u < 0.0 || v < 0.0 || u + v > 1.0)
		return (FAR);
	return (t);
}

t_vec3			normal_triangle(t_ray ray, void *object)
{
	t_triangle		*triangle;

	triangle = object;
	if (v3_dotpdt(ray.dir, triangle->normal) <= 0)
		return (triangle->normal);
	else 
		return (v3_scalar(triangle->normal, -1));
}

int				set_triangle(t_triangle *triangle, t_arg_triangle *arg)
{
	if (v3_norm2(arg->ab) == 0.0 || v3_norm2(arg->ac) == 0.0)
		return (RT_FAIL);
	triangle->normal = v3_cross(arg->ab, arg->ac);
	if (ft_abs_double(v3_norm2(triangle->normal)) < APPROX_0)
		return (RT_FAIL);
	triangle->a = arg->a;
	triangle->ab = arg->ab;
	triangle->ac = arg->ac;
	triangle->normal = v3_normalise(triangle->normal);
	return (RT_SUCCESS);
}
