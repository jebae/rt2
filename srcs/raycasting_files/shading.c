#include "rt.h"

t_col			diffuse_color(
	t_vec3 light_dir,
	t_trace_record *rec,
	int round_n_dot_l_bit
)
{
	t_col		col;
	double		it;
	double		kd;

	kd = 1;
	it = v3_dotpdt(light_dir, rec->normal);
	if (round_n_dot_l_bit)
		it = round_n_dot_l(it);
	it *= kd;
	it = it < 0 ? 0 : it;
	it = it > 1.0 ? 1.0 : it;
	col.r = it * rec->color.x;
	col.g = it * rec->color.y;
	col.b = it * rec->color.z;
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

double			send_shadow_ray(t_trace_record *rec, t_vec3 light_dir, t_env *e)
{
	int			i;
	double		r;
	t_ray		shadow_ray;

	r = 0;
	shadow_ray.ori = rec->point;
	shadow_ray.dir = light_dir;
	shadow_ray.t = FAR;
	i = 0;
	while (i < e->num_objs)
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
	t_vec3		light_dir;

	light_dir = ll->get_dir(&rec->point, ll->light);
	shader = init_shader();
	if (!(e->mask & RT_ENV_MASK_NO_SHADOW) &&
		send_shadow_ray(rec, light_dir, e) <
		ll->get_distance(&rec->point, ll->light))
		return (shader);
	shader.diff = diffuse_color(light_dir, rec, e->mask & RT_ENV_MASK_ROUND_N_DOT_L);
	if (!(e->mask & RT_ENV_MASK_NO_SPECULAR))
		shader.spec = specular_color(light_dir, rec, ll);
	return (shader);
}
