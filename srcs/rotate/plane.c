#include "rt.h"

void		plane_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	t_plane		*plane;

	plane = (t_plane *)object;
	rotate_object_axis(q, axis_mat);
	ft_memcpy(&plane->normal, axis_mat->arr[1], sizeof(t_vec3));
}
