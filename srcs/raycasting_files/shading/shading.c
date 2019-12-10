#include "rt.h"

static t_col	calc_shade(t_env *e, t_trace_record *rec, double coeff)
{
	int			i;
	t_col		sh;
	t_vec3		light_dir;
	t_ll		*ll;

	(void)coeff;
	sh = (t_col){0, 0, 0};
	i = 0;
	while (i < e->num_lights)
	{
		ll = &e->ll_lit[i];
		light_dir = ll->get_dir(&rec->point, ll->light);
		if (!(e->mask & RT_ENV_MASK_NO_SHADOW) &&
			send_shadow_ray(rec, light_dir, e) <
			ll->get_distance(&rec->point, ll->light))
			return ((t_col){0, 0, 0}); // need to get real shadow color
		sh = color_add(sh, diffuse_specular(light_dir, ll, rec, e));
		i++;
	}
	// reflection
	// refraction
	return (sh);
}

t_col			get_shade(t_env *e, t_trace_record *rec)
{
	t_col		sh;

	sh.r = e->amb.x * rec->color.x;
	sh.g = e->amb.y * rec->color.y;
	sh.b = e->amb.z * rec->color.z;
	sh = color_add(sh, calc_shade(e, rec, 1.0));
	return (sh);
}
