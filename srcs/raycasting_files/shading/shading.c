#include "rt.h"

static t_col	shade_per_lights(t_env *e, t_trace_record *rec)
{
	int			i;
	t_vec3		light_dir;
	t_col		sh;
	t_ll		*ll;

	i = 0;
	ft_bzero(&sh, sizeof(t_col));
	while (i < e->num_lights)
	{
		ll = &e->ll_lit[i];
		light_dir = ll->get_dir(&rec->point, ll->light);
		/*
		if (!(e->mask & RT_ENV_MASK_NO_SHADOW) &&
			send_shadow_ray(rec, light_dir, e) <
			ll->get_distance(&rec->point, ll->light))
			return ((t_col){0, 0, 0}); // need to get real shadow color
		*/
		sh = color_add(sh, diffuse_specular(light_dir, ll, rec, e));
		i++;
	}
	return (sh);
}

t_col			calc_shade(t_env *e, t_trace_record *rec, double coeff)
{
	t_col		sh;

	if (rec->depth >= RT_MAX_TRACE_DEPTH - 1)
		return ((t_col){0, 0, 0});
	sh = color_scalar(shade_per_lights(e, rec),
		coeff * (1.0 - rec->obj->reflectivity) * (1.0 - rec->obj->transparency));
	sh = color_add(sh, reflection_shade(e, rec, coeff));
	sh = color_add(sh, refraction_shade(e, rec, coeff));
	return (sh);
}
