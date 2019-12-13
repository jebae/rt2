#include "rt.h"

void		ring_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	t_ring		*ring;

	ring = (t_ring *)object;
	rotate_object_axis(q, axis_mat);
	ring->normal = *(t_vec3 *)(axis_mat->arr[1]);
	ring->d = v3_dotpdt(ring->center, ring->normal);
}
