#include "rt.h"

int				render(t_env *e)
{
	if ((e->mask & RT_ENV_MASK_CEL_SHADING) && cel_shading(e) == RT_FAIL)
		return (RT_FAIL);
	else
		multi_thread(e); // need to protect
	if (anti_aliasing(
		(unsigned int *)e->img_buf, (unsigned int *)e->data,
		e->width / 2, e->height / 2) == RT_FAIL);
		return (RT_FAIL);
	// need filter
	return (RT_SUCCESS);
}
