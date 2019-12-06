#include "rt.h"

void		box_translate(t_vec3 *v_translate, void *object)
{
	t_box	*box;

	box = (t_box *)object;
	box->vmin = v3_add(box->vmin, *v_translate);
}
