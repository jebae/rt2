#include "rt.h"

void		box_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	t_box		*box;

	box = (t_box *)object;
	rotate_object_axis(q, axis_mat);
	/*
	box->vmax = v3_sub(box->vmax, box->vmin);
	box->vmax = rotate(&q[0], &box->vmax, &q[1]);
	box->vmax = v3_add(box->vmax, box->vmin);
	*/
}
