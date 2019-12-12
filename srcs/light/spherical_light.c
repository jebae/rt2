#include "rt.h"

t_vec3		spherical_light_dir(t_vec3 *point, void *light)
{
	t_spherical_light		*sl;

	sl = (t_spherical_light *)light;
	return (v3_normalise(v3_frompoints(*point, sl->pos)));
}

double		spherical_light_distance(t_vec3 *point, void *light)
{
	t_spherical_light		*sl;

	sl = (t_spherical_light *)light;
	return (v3_norm(v3_frompoints(*point, sl->pos)));
}
