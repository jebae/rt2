#include "rt.test.h"

static void	box_case1(t_ol *ol)
{
	t_box		*box;
	t_arg_box	arg;

	ol->intersect = &v_intersect_box;
	ol->get_normal = &normal_box;
    ol->object = ft_memalloc(sizeof(t_box));
	box = ol->object;
	arg.vmin = (t_vec3){-1.0, 1.0, 1.0};
	arg.a = (t_vec3){2.0, 0.0, 2.0};
	arg.b = (t_vec3){0.0, 0.5, 0.0};
	arg.norm_c = 1.0;

	test(
		set_box(box, &arg) == RT_SUCCESS,
		"set_box : return value"
	);
}

void		test_box_intersect_case1(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	box_case1(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_box_normal_case1(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	box_case1(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void	box_case2(t_ol *ol)
{
	t_box		*box;
	t_arg_box	arg;

	ol->intersect = &v_intersect_box;
	ol->get_normal = &normal_box;
    ol->object = ft_memalloc(sizeof(t_box));
	box = ol->object;
	arg.vmin = (t_vec3){-1.0, 1.0, 1.0};
	arg.a = (t_vec3){2.0, -0.6, 2.0};
	arg.b = (t_vec3){0.0, 0.5, 0.15};
	arg.norm_c = 1.0;

	test(
		set_box(box, &arg) == RT_SUCCESS,
		"set_box : return value"
	);
}

void		test_box_intersect_case2(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	box_case2(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_box_normal_case2(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	box_case2(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void	box_case3(t_ol *ol)
{
	t_box		*box;
	t_arg_box	arg;

	ol->intersect = &v_intersect_box;
	ol->get_normal = &normal_box;
    ol->object = ft_memalloc(sizeof(t_box));
	box = ol->object;
	arg.vmin = (t_vec3){-1.0, 1.0, 5.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, -2.0, 0.0};
	arg.norm_c = 1.0;

	test(
		set_box(box, &arg) == RT_SUCCESS,
		"set_box : return value"
	);
}

void		test_box_intersect_case3(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	box_case3(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_box_normal_case3(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	box_case3(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}
