#include "rt.h"

static int		validate(t_arg_cyl *arg)
{
	if (arg->radius <= 0 || v3_norm2(arg->axis) < RT_APPROX_0 ||
		arg->height <= 0)
		return (RT_FAIL);
	return (RT_SUCCESS);
}

int				set_cyl(t_ol *ol, t_arg_cyl *arg)
{
	t_cyl	*cyl;

	if (validate(arg) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_cy;
	ol->get_normal = &normal_cylinder;
	ol->uv_mapping = &cyl_uv_mapping;
	ol->translate = &cyl_translate;
	cyl = (t_cyl *)ol->object;
	cyl->cen = arg->cen;
	cyl->axis = v3_normalise(arg->axis);
	cyl->radius = arg->radius;
	cyl->height = arg->height;
	pick_axis_from_plane(&cyl->axis, &ol->axis_mat);
	return (RT_SUCCESS);
}
