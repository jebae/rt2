#include "rt.h"

static int		validate(t_arg_camera *arg)
{
	if (v3_norm2(arg->dir) < RT_APPROX_0)
		return (handle_fail("set_camera : dir's length almost 0"));
	if (v3_norm2(arg->right) < RT_APPROX_0)
		return (handle_fail("set_camera : right's length almost 0"));
	return (RT_SUCCESS);
}

int				set_camera(t_camera *cam, t_arg_camera *arg)
{
	if (validate(arg) == RT_FAIL)
		return (RT_FAIL);
	cam->pos = arg->pos;
	cam->dir = v3_normalise(arg->dir);
	cam->right = v3_normalise(arg->right);
	cam->down = v3_cross(arg->dir, arg->right);
	return (RT_SUCCESS);
}
