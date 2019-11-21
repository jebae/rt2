#include "rt.test.h"

static void	ring_case1(t_ol *ol)
{
	t_arg_ring	arg;

	ol->intersect = &v_intersect_ring;
	ol->get_normal = &normal_ring;
    ol->object = ft_memalloc(sizeof(t_ring));

	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = v3_normalise((t_vec3){0.0, -1.0, -0.3});
	arg.r1 = 0.4;
	arg.r2 = 0.5;

	test(
		set_ring(ol, &arg) == RT_SUCCESS,
		"set_ring : return value"
	);
}

void		test_ring_intersect_case1(void)
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

	ring_case1(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_ring_normal_case1(void)
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

	ring_case1(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void	ring_case2(t_ol *ol)
{
	t_arg_ring	arg;

	ol->intersect = &v_intersect_ring;
	ol->get_normal = &normal_ring;
    ol->object = ft_memalloc(sizeof(t_ring));

	arg.center = (t_vec3){1.0, 0.5, 3.0};
	arg.normal = v3_normalise((t_vec3){-0.5, -1.5, -0.1});
	arg.r1 = 1.0;
	arg.r2 = 1.5;

	test(
		set_ring(ol, &arg) == RT_SUCCESS,
		"set_ring : return value"
	);
}

void		test_ring_intersect_case2(void)
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

	ring_case2(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_ring_normal_case2(void)
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

	ring_case2(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void	ring_case3(t_ol *ol)
{
	t_arg_ring	arg;

	ol->intersect = &v_intersect_ring;
	ol->get_normal = &normal_ring;
    ol->object = ft_memalloc(sizeof(t_ring));

	arg.center = (t_vec3){1.0, 0.5, 3.0};
	arg.normal = v3_normalise((t_vec3){-0.5, -1.5, -0.1});
	arg.r1 = 0.0;
	arg.r2 = 1.5;

	test(
		set_ring(ol, &arg) == RT_SUCCESS,
		"set_ring : return value"
	);
}

void		test_ring_intersect_case3(void)
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

	ring_case3(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_ring_normal_case3(void)
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

	ring_case3(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}
