#include "rt.h"

void		triangle_translate(t_vec3 *v_translate, void *object)
{
	t_triangle	*triangle;

	triangle = (t_triangle *)object;
	triangle->a = v3_add(triangle->a, *v_translate);
}
