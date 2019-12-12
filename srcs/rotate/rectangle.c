#include "rt.h"

void		rectangle_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	t_rectangle		*rect;

	rect = (t_rectangle *)object;
	rotate_object_axis(q, axis_mat);
	rect->a = *(t_vec3 *)(axis_mat->arr[0]);
	rect->b = *(t_vec3 *)(axis_mat->arr[2]);
	rect->normal = *(t_vec3 *)(axis_mat->arr[1]);
	rect->d = v3_dotpdt(rect->p, rect->normal);
}
