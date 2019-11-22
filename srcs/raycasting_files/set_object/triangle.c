#include "raycast.h"

static int		validate(t_arg_triangle *arg)
{
	t_vec3		v;

	if (v3_norm2(arg->ab) < APPROX_0 || v3_norm2(arg->ac) < APPROX_0)
		return (RT_FAIL);
	v = v3_cross(arg->ab, arg->ac);
	if (v3_norm2(v) < APPROX_0)
		return (RT_FAIL);
	return (RT_SUCCESS);
}

static void		set_axis(t_arg_triangle *arg, t_mat3 *axis_mat)
{
	t_vec3		v;

	v = v3_normalise(arg->ab);
	ft_memcpy(axis_mat->arr[0], &v, sizeof(t_vec3));
	v = v3_normalise(v3_cross(arg->ab, arg->ac));
	ft_memcpy(axis_mat->arr[1], &v, sizeof(t_vec3));
	v = v3_cross(*(t_vec3 *)(axis_mat->arr[0]), *(t_vec3 *)(axis_mat->arr[1]));
	ft_memcpy(axis_mat->arr[2], &v, sizeof(t_vec3));
}

int				set_triangle(t_ol *ol, t_arg_triangle *arg)
{
	t_triangle	*triangle;

	if (validate(arg) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_triangle;
	ol->get_normal = &normal_triangle;
	triangle = (t_triangle *)ol->object;
	triangle->a = arg->a;
	triangle->ab = arg->ab;
	triangle->ac = arg->ac;
	set_axis(arg, &ol->axis_mat);
	triangle->normal = *(t_vec3 *)(ol->axis_mat.arr[1]);
	return (RT_SUCCESS);
}
