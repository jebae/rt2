#include "rt.h"

void		sphere_translate(t_vec3 *v_translate, void *object)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object;
	sphere->cen = v3_add(sphere->cen, *v_translate);
}
