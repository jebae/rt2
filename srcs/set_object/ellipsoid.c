#include "rt.h"

static int		validate(t_arg_ellipsoid *arg)
{
	if (v3_norm2(arg->axis) < RT_APPROX_0)
		return (handle_fail("set_ellipsoid : axis's length almost 0"));
	if (arg->d < 0.0)
		return (handle_fail("set_ellipsoid : d below 0"));
	if (arg->sum <= 0.0)
		return (handle_fail("set_ellipsoid : sum 0 or below 0"));
	return (RT_SUCCESS);
}

int				set_ellipsoid(t_ol *ol, t_arg_ellipsoid *arg)
{
	t_ellipsoid	*ellipsoid;

	if (validate(arg) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_ellipsoid;
	ol->get_normal = &normal_ellipsoid;
	ol->uv_mapping = NULL;
	ol->translate = &ellipsoid_translate;
	ol->rotate = &ellipsoid_rotate;
	ellipsoid = (t_ellipsoid *)ol->object;
	ellipsoid->cen = arg->cen;
	ellipsoid->axis = v3_normalise(arg->axis);
	ellipsoid->d = arg->d;
	ellipsoid->sum = arg->sum;
	pick_axis_from_plane(&ellipsoid->axis, &ol->axis_mat);
	return (RT_SUCCESS);
}
