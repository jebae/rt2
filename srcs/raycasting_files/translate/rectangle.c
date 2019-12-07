#include "rt.h"

void		rectangle_translate(t_vec3 *v_translate, void *object)
{
	t_rectangle		*rect;

	rect = (t_rectangle *)object;
	rect->p = v3_add(rect->p, *v_translate);
	rect->d = v3_dotpdt(rect->p, rect->normal);
}
