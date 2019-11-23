#include "raycast.h"

static int		validate(t_arg_cone *arg)
{
	if (arg->angle <= 0.0 || arg->angle >= 90 ||
		v3_norm2(arg->axis) < APPROX_0 ||
		arg->upper_height < 0.0 || arg->lower_height < 0.0 ||
		(arg->upper_height < APPROX_0 && arg->lower_height < APPROX_0))
		return (RT_FAIL);
	return (RT_SUCCESS);
}

int				set_cone(t_ol *ol, t_arg_cone *arg)
{
	t_cone		*cone;

	if (validate(arg) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_co;
	ol->get_normal = &normal_cone;
	ol->uv_mapping = &cone_uv_mapping;
	cone = (t_cone *)ol->object;
	cone->cen = arg->cen;
	cone->axis = v3_normalise(arg->axis);
	cone->angle = arg->angle;
	cone->upper_height = arg->upper_height;
	cone->lower_height = arg->lower_height;
	pick_axis_from_plane(&cone->axis, &ol->axis_mat);
	return (RT_SUCCESS);
}
