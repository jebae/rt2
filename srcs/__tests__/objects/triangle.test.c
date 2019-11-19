#include "rt.test.h"

static void		triangle_case1(t_ol *ol)
{
	t_triangle		*triangle;
	t_arg_triangle	arg;

	ol->intersect = &v_intersect_triangle;
	ol->get_normal = &normal_triangle;
    ol->object = ft_memalloc(sizeof(t_triangle));
	triangle = (t_triangle *)ol->object;
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){0.5, 0.5, 1.5};
	arg.ac = (t_vec3){-0.5, 0.5, 0.0};

	test(
		set_triangle(triangle, &arg) == RT_SUCCESS,
		"set_triangle : return value"
	);
}

void			test_triangle_intersect_case1(void)
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

	triangle_case1(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void			test_triangle_normal_case1(void)
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

	triangle_case1(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void		triangle_case2(t_ol *ol)
{
	t_triangle		*triangle;
	t_arg_triangle	arg;

	ol->intersect = &v_intersect_triangle;
	ol->get_normal = &normal_triangle;
    ol->object = ft_memalloc(sizeof(t_triangle));
	triangle = (t_triangle *)ol->object;
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){1.0, 0.0, 1.5};
	arg.ac = (t_vec3){-0.5, 1.0, 0.0};

	test(
		set_triangle(triangle, &arg) == RT_SUCCESS,
		"set_triangle : return value"
	);
}

void			test_triangle_intersect_case2(void)
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

	triangle_case2(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void			test_triangle_normal_case2(void)
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

	triangle_case2(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}
