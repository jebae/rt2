#include "raycast.h"

static void		set_pyramid_sides(t_pyramid *pyramid, t_arg_pyramid *arg)
{
	t_vec3			top;
	t_triangle		*sides;
	t_arg_triangle	arg_tri;

	sides = pyramid->sides;
	top = v3_add(v3_add(arg->a, v3_scalar(v3_add(arg->u, arg->v), 0.5)),
		v3_scalar(v3_cross(pyramid->u, pyramid->v), arg->height));
	arg_tri.a = arg->a;
	arg_tri.ab = arg->u;
	arg_tri.ac = v3_sub(top, arg->a);
	set_triangle(&(sides[0]), &arg_tri);
	arg_tri.a = v3_add(arg->a, arg->u);
	arg_tri.ab = arg->v;
	arg_tri.ac = v3_sub(top, arg_tri.a);
	set_triangle(&(sides[1]), &arg_tri);
	arg_tri.a = arg->a;
	arg_tri.ab = arg->v;
	arg_tri.ac = sides[0].ac;
	set_triangle(&(sides[2]), &arg_tri);
	arg_tri.a = v3_add(arg->a, arg->v);
	arg_tri.ab = arg->u;
	arg_tri.ac = v3_sub(top, arg_tri.a);
	set_triangle(&(sides[3]), &arg_tri);
}

int				set_pyramid(t_pyramid *pyramid, t_arg_pyramid *arg)
{
	if (v3_norm2(arg->u) == 0.0 || v3_norm2(arg->v) == 0.0 ||
		ft_abs_double(v3_dotpdt(arg->u, arg->v)) > APPROX_0 ||
		arg->height <= 0.0)
		return (RT_FAIL);
	pyramid->u = v3_normalise(arg->u);
	pyramid->v = v3_normalise(arg->v);
	pyramid->norm_u = v3_norm(arg->u);
	pyramid->norm_v = v3_norm(arg->v);
	set_pyramid_sides(pyramid, arg);
	return (RT_SUCCESS);
}
