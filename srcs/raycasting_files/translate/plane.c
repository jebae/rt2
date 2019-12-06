#include "raycast.h"

void		plane_translate(t_vec3 *v_translate, void *object)
{
	t_plane	*plane;

	plane = (t_plane *)object;
	plane->d = v3_dotpdt(plane->normal, *v_translate) + plane->d;
}
