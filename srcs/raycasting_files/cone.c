#include "raycast.h"

int		set_cone(t_cone *cone, t_arg_cone *arg)
{
	if (arg->angle <= 0 || arg->angle >= 90 ||
		v3_norm2(arg->axis) == 0.0)
		return (RT_FAIL);
	cone->cen = arg->cen;
	cone->axis = v3_normalise(arg->axis);
	cone->angle = arg->angle;
	return (RT_SUCCESS);
}
