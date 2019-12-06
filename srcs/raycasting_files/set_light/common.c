#include "raycast.h"

void		init_ll(t_ll *ll)
{
	ll->light = NULL;
	ll->get_dir = NULL;
	ll->get_distance = NULL;
}
