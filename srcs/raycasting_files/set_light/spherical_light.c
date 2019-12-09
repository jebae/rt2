#include "rt.h"

int			set_spherical_light(t_ll *ll, t_arg_spherical_light *arg)
{
	t_spherical_light		*sl;

	sl = (t_spherical_light *)ll->light;
	sl->pos = arg->pos;
	sl->tra = arg->tra;
	ll->get_dir = &spherical_light_dir;
	ll->get_distance = &spherical_light_distance;
	return (RT_SUCCESS);
}
