#include "rt.h"

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
