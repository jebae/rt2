#include "rt.test.h"

static void	cone_case1(t_ol *ol)
{
	t_arg_cone	arg;

	ol->intersect = &v_intersect_co;
	ol->get_normal = &normal_cone;
    ol->object = ft_memalloc(sizeof(t_cone));
    arg.cen = (t_vec3){0.0, -1.0, 2.0};
    arg.axis = (t_vec3){0.0, 1.0, 0.0};
	arg.angle = 30;

	test(
		set_cone(ol, &arg) == RT_SUCCESS,
		"set_cone : return value"
	);
}

void		test_cone_intersect_case1(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){-1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	cone_case1(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_cone_normal_case1(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){-1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	cone_case1(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}
