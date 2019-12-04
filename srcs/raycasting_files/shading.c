#include "raycast.h"

t_vec3			find_point_from_ray(t_ray ray)
{
	t_vec3		point;

	point.x = ray.ori.x + ray.dir.x * ray.t;
	point.y = ray.ori.y + ray.dir.y * ray.t;
	point.z = ray.ori.z + ray.dir.z * ray.t;
	return (point);
}

t_col			diffuse_color(t_vec3 light_dir, t_trace_record *rec)
{
	t_col		col;
	double		it;
	double		kd;
	t_ol		*ol;

	ol = rec->obj;
	kd = 1;
	it = kd * v3_dotpdt(light_dir, rec->normal);
	it = it < 0 ? 0 : it;
	it = it > 1.0 ? 1.0 : it;
	col.r = it * ol->dif.x;
	col.g = it * ol->dif.y;
	col.b = it * ol->dif.z;
	return (col);
}

t_col			specular_color(t_vec3 light_dir, t_trace_record *rec, t_ll *ll)
{
	double		tmp;
	t_vec3		r;
	t_vec3		v;
	t_col		c;
	t_ol		*ol;

	ol = rec->obj;
	v = v3_scalar(rec->ray.dir, -1);
	tmp = v3_dotpdt(rec->normal, light_dir);
	tmp = tmp < 0 ? 0 : tmp;
	r = v3_scalar(rec->normal, 2 * tmp);
	r = v3_sub(r, light_dir);
	tmp = v3_dotpdt(r, v);
	tmp = tmp < 0 ? 0 : tmp;
	tmp = pow(tmp, ol->specpower) * ol->specvalue / 100;
	c.r = tmp * ll->its.x;
	c.g = tmp * ll->its.y;
	c.b = tmp * ll->its.z;
	return (c);
}

double			send_shadow_ray(t_vec3 point, t_vec3 light_dir, t_env *e)
{
	int			i;
	double		r;
	t_ray		shadow_ray;

	r = 0;
	shadow_ray.ori = point;
	shadow_ray.dir = light_dir;
	shadow_ray.t = FAR;
	i = 0;
	while (i < num_objs)
	{
		r = e->ll_obj[i].intersect(shadow_ray, e->ll_obj[i].object);
		if (r > 0.00001 && r < shadow_ray.t)
			shadow_ray.t = r;
		i++;
	}
	return (shadow_ray.t);
}

t_shader		compute_color(t_trace_record *rec, t_ll *ll, t_env *e)
{
	t_shader	shader;
	t_vec3		point;
	t_vec3		light_dir;

	light_dir = ll->get_dir(&rec->point, ll->light);
	shader = init_shader();
	if (send_shadow_ray(rec->point, light_dir, e) <
		ll->get_distance(&rec->point, ll->light))
		return (shader);
	shader.diff = color_add(shader.diff, diffuse_color(light_dir, rec));
	shader.spec = color_add(shader.spec, specular_color(light_dir, rec, ll));
	return (shader);
}
