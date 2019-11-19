#include "raycast.h"

int				set_box(t_box *box, t_arg_box *arg)
{
	t_vec3		c;

	if (v3_norm2(arg->a) == 0.0 || v3_norm2(arg->b) == 0.0 ||
		ft_abs_double(v3_dotpdt(arg->a, arg->b)) > APPROX_0 ||
		arg->norm_c <= 0.0)
		return (RT_FAIL);
	box->vmin = arg->vmin;
	box->vmax.x = v3_norm(arg->a);
	box->vmax.y = v3_norm(arg->b);
	box->vmax.z = arg->norm_c;
	arg->a = v3_normalise(arg->a);
	arg->b = v3_normalise(arg->b);
	c = v3_cross(arg->a, arg->b);
	ft_memcpy(box->mat.arr[0], &arg->a, sizeof(t_vec3));
	ft_memcpy(box->mat.arr[1], &arg->b, sizeof(t_vec3));
	ft_memcpy(box->mat.arr[2], &c, sizeof(t_vec3));
	return (RT_SUCCESS);
}
