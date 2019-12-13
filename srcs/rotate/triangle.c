#include "rt.h"

void		triangle_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	t_triangle		*triangle;

	triangle = (t_triangle *)object;
	rotate_object_axis(q, axis_mat);
	triangle->ab = rotate(&q[0], &triangle->ab, &q[1]);
	triangle->ac = rotate(&q[0], &triangle->ac, &q[1]);
	ft_memcpy(&triangle->normal, axis_mat->arr[1], sizeof(t_vec3));
}
