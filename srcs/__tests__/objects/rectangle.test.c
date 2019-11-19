#include "rt.test.h"

static void	rectangle_case1(t_ol *ol)
{
	t_rectangle			*rect;
	t_arg_rectangle		arg;

	ol->intersect = &v_intersect_rectangle;
	ol->get_normal = &normal_rectangle;
    ol->object = ft_memalloc(sizeof(t_rectangle));
	rect = ol->object;
	arg.p = (t_vec3){-1.0, 1.0, 1.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 0.0, 2.0};

	set_rectangle(rect, &arg);
}

void		test_rectangle_intersect_case1(void)
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

	rectangle_case1(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_rectangle_normal_case1(void)
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

	rectangle_case1(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void	rectangle_case2(t_ol *ol)
{
	t_rectangle			*rect;
	t_arg_rectangle		arg;

	ol->intersect = &v_intersect_rectangle;
	ol->get_normal = &normal_rectangle;
    ol->object = ft_memalloc(sizeof(t_rectangle));
	rect = ol->object;
	arg.p = (t_vec3){-1.0, 1.0, 1.0};
	arg.a = (t_vec3){2.0, -1.0, -1.0};
	arg.b = (t_vec3){0.0, -1.0, 1.0};

	set_rectangle(rect, &arg);
}

void		test_rectangle_intersect_case2(void)
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

	rectangle_case2(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_rectangle_normal_case2(void)
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

	rectangle_case2(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}
