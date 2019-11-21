#include "rt.test.h"

static void		pyramid_case1(t_ol *ol)
{
	t_arg_pyramid	arg;

	ol->intersect = &v_intersect_pyramid;
	ol->get_normal = &normal_pyramid;
    ol->object = ft_memalloc(sizeof(t_pyramid));
	arg.a = (t_vec3){-0.5, 0.5, 0.7};
	arg.u = (t_vec3){1.0, -0.5, 1.0};
	arg.v = (t_vec3){-1.0, 0.0, 1.0};
	arg.height = 1.0;

	test(
		set_pyramid(ol, &arg) == RT_SUCCESS,
		"set_pyramid : return value"
	);
}

void			test_pyramid_intersect_case1(void)
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

	pyramid_case1(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void			test_pyramid_normal_case1(void)
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

	pyramid_case1(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void		pyramid_case2(t_ol *ol)
{
	t_arg_pyramid	arg;

	ol->intersect = &v_intersect_pyramid;
	ol->get_normal = &normal_pyramid;
    ol->object = ft_memalloc(sizeof(t_pyramid));
	arg.a = (t_vec3){-0.5, 1.5, 0.7};
	arg.u = (t_vec3){1.0, 0.0, 0.0};
	arg.v = (t_vec3){0.0, -0.3, 0.5};
	arg.height = 1.0;

	test(
		set_pyramid(ol, &arg) == RT_SUCCESS,
		"set_pyramid : return value"
	);
}

void			test_pyramid_intersect_case2(void)
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

	pyramid_case2(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void			test_pyramid_normal_case2(void)
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

	pyramid_case2(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void		pyramid_case3(t_ol *ol)
{
	t_arg_pyramid	arg;

	ol->intersect = &v_intersect_pyramid;
	ol->get_normal = &normal_pyramid;
    ol->object = ft_memalloc(sizeof(t_pyramid));
	arg.a = (t_vec3){-0.5, 1.0, 1.5};
	arg.u = (t_vec3){1.0, 0.0, 0.0};
	arg.v = (t_vec3){0.0, -1.0, 0.0};
	arg.height = 1.0;

	test(
		set_pyramid(ol, &arg) == RT_SUCCESS,
		"set_pyramid : return value"
	);
}

void			test_pyramid_intersect_case3(void)
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

	pyramid_case3(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void			test_pyramid_normal_case3(void)
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

	pyramid_case3(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}
