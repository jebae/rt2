#include "rt.h"

void		rotate_object_axis(t_vec4 *q, t_mat3 *axis_mat)
{
	int			i;
	t_vec3		*v;

	i = 0;
	while (i < 3)
	{
		v = (t_vec3 *)axis_mat->arr[i];
		*v = rotate(&q[0], v, &q[1]);
		i++;
	}
}