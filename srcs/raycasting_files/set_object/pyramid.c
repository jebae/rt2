#include "raycast.h"

static int		validate(t_arg_pyramid *arg)
{
	if (v3_norm2(arg->u) < APPROX_0 || v3_norm2(arg->v) < APPROX_0 ||
		ft_abs_double(v3_dotpdt(arg->u, arg->v)) > APPROX_0 ||
		arg->height < APPROX_0)
		return (RT_FAIL);
	return (RT_SUCCESS);
}

static void		set_side(t_triangle *side, t_arg_triangle *arg)
{
	side->a = arg->a;
	side->ab = arg->ab;
	side->ac = arg->ac;
	side->normal = v3_normalise(v3_cross(side->ab, side->ac));
}

static void		set_pyramid_sides(
	t_pyramid *pyramid,
	t_arg_pyramid *arg,
	t_vec3 *y_axis
)
{
	t_vec3			top;
	t_triangle		*sides;
	t_arg_triangle	arg_tri;

	sides = pyramid->sides;
	top = v3_add(v3_add(arg->a, v3_scalar(v3_add(arg->u, arg->v), 0.5)),
		v3_scalar(*y_axis, -arg->height));
	arg_tri.a = arg->a;
	arg_tri.ab = arg->u;
	arg_tri.ac = v3_sub(top, arg->a);
	set_side(&(sides[0]), &arg_tri);
	arg_tri.a = v3_add(arg->a, arg->u);
	arg_tri.ab = arg->v;
	arg_tri.ac = v3_sub(top, arg_tri.a);
	set_side(&(sides[1]), &arg_tri);
	arg_tri.a = arg->a;
	arg_tri.ab = arg->v;
	arg_tri.ac = sides[0].ac;
	set_side(&(sides[2]), &arg_tri);
	arg_tri.a = v3_add(arg->a, arg->v);
	arg_tri.ab = arg->u;
	arg_tri.ac = v3_sub(top, arg_tri.a);
	set_side(&(sides[3]), &arg_tri);
}

static void		set_axis(t_arg_pyramid *arg, t_mat3 *axis_mat)
{
	t_vec3		v;

	v = v3_normalise(arg->u);
	ft_memcpy(axis_mat->arr[0], &v, sizeof(t_vec3));
	v = v3_normalise(arg->v);
	ft_memcpy(axis_mat->arr[2], &v, sizeof(t_vec3));
	v = v3_cross(*(t_vec3 *)(axis_mat->arr[2]), *(t_vec3 *)(axis_mat->arr[0]));
	ft_memcpy(axis_mat->arr[1], &v, sizeof(t_vec3));
}

int				set_pyramid(t_ol *ol, t_arg_pyramid *arg)
{
	t_pyramid		*pyramid;

	if (validate(arg) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_pyramid;
	ol->get_normal = &normal_pyramid;
	pyramid = (t_pyramid *)ol->object;
	set_axis(arg, &ol->axis_mat);
	pyramid->u = *(t_vec3 *)(ol->axis_mat.arr[0]);
	pyramid->v = *(t_vec3 *)(ol->axis_mat.arr[2]);
	pyramid->norm_u = v3_norm(arg->u);
	pyramid->norm_v = v3_norm(arg->v);
	set_pyramid_sides(pyramid, arg, (t_vec3 *)(ol->axis_mat.arr[1]));
	return (RT_SUCCESS);
}
