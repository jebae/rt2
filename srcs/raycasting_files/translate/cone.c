#include "raycast.h"

void		cone_translate(t_vec3 *v_translate, void *object)
{
	t_cone	*cone;

	cone = (t_cone *)object;
	cone->cen = v3_add(cone->cen, *v_translate);
}
