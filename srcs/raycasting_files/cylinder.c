#include "raycast.h"

int		set_cyl(t_cyl *cyl, t_arg_cyl *arg)
{
	if (arg->radius <= 0 || v3_norm2(arg->axis) == 0.0)
		return (RT_FAIL);
	cyl->cen = arg->cen;
	cyl->axis = v3_normalise(arg->axis);
	cyl->radius = arg->radius;
	return (RT_SUCCESS);
}
