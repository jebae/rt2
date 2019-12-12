#include "rt.h"

void		cyl_translate(t_vec3 *v_translate, void *object)
{
	t_cyl	*cyl;

	cyl = (t_cyl *)object;
	cyl->cen = v3_add(cyl->cen, *v_translate);
}
