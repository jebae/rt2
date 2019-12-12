#include "rt.h"

void		sphere_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	(void)object;
	rotate_object_axis(q, axis_mat);
}
