#include "rt.h"

void		cone_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	t_cone		*cone;

	cone = (t_cone *)object;
	rotate_object_axis(q, axis_mat);
	ft_memcpy(&cone->axis, axis_mat->arr[1], sizeof(t_vec3));
}
